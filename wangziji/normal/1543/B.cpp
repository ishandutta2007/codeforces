#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[400005];
signed main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int s=0
		;for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			s+=a[i];
		}
		cout << (s%n)*(n-s%n) << "\n";
	}
	return 0;
}