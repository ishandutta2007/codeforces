#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		for(int i=1;i<=n+n;i++)
			cin >> a[i];
		sort(a+1,a+n+n+1);
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i+n]<a[i]+k) flag=0;
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
 }