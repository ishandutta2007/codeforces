#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,x,a,b;
		cin >> n >> x >> a >> b;
		cout << min(abs(a-b)+x,n-1) << endl;
	}
	return 0;
}