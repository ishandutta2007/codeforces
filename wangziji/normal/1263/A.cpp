#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if(a>=b+c||b>=a+c||c>=a+b)
			cout << a+b+c-max(a,max(b,c)) << "\n";
		else
			cout << (a+b+c)/2 << "\n";
	}
	return 0;
}