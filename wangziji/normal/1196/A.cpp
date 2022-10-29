#include <iostream>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int q;
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		cout << (a+b+c)/2 << endl;
	}
	return 0;
}