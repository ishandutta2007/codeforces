#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int r=a+c-b,l=a-c-b;
		l=max(1,l);
	//	cout << l << " " << r << endl;
		if(r<l) puts("0");
	else 	cout << max(0,(r-l)/2+1) << "\n";
	}
	return 0;
}