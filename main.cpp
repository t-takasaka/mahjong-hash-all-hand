#include <windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void hoge(ofstream &ofs, ostringstream &oss, int cnt){
	for(int i = 1; i <= 4; i++){
		ostringstream tmp;
		tmp << oss.str() << i;
//		cout << tmp.str() << endl;
		ofs << tmp.str() << endl;
		if((cnt + i) < 14){
			hoge(ofs, tmp, cnt + i);
			tmp << '0';
			hoge(ofs, tmp, cnt + i);
		}else{
			break;
		}
	}
}

int main(){
	LARGE_INTEGER freq, begin, end;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&begin);

	ofstream ofs("hoge.txt");
	ostringstream oss;
	hoge(ofs, oss, 0);

	QueryPerformanceCounter(&end);
	printf("\n%f\n", (double)(end.QuadPart - begin.QuadPart) / freq.QuadPart);

	_getch();
	return 0;
}