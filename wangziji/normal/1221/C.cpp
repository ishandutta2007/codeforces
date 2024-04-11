#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int q;
	cin >> q;
	while(q--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		cout << min(a,min(b,(a+b+c)/3)) << endl;
	}
	return 0;
}