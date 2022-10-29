#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		long long a,b,c;
		cin >> a >> b >> c;
		long long t=(a+1)/2;
		int x=(t-1)/b+1;
		cout << max((x-1)*c+t,a) << endl;
	}
	return 0;
}