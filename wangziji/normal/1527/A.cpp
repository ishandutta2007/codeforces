#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,x=1;
		cin >> n;
		while((x*2<=n)) x<<=1;
		cout << x-1 << "\n";
	}
	return 0;
}