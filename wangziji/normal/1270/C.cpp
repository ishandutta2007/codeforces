#include <iostream>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,sum=0,XOR=0;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			int t;
			cin >> t;
			XOR^=t;
			sum+=t;
		}
		cout << 2 << "\n" << XOR;
		sum+=XOR;
		cout << " " << sum << "\n";
	}
	return 0;
}