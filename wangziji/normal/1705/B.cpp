#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int ans=0,cnt=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]>1) cnt+=a[i]-1,a[i]=1;
			if(!a[i]&&cnt) --cnt,++a[i],++ans;
		}
		ans+=cnt;
		int flag=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]) flag=1;
			ans+=flag;
		}
		cout << ans << "\n";
	}
	return 0;
 }