#include <iostream>
#include <algorithm>
#define mod 998244353
#define int long long
using namespace std;
pair<int,int> a[300005];
inline bool cmp(pair<int,int>x,pair<int,int> y)
{
	return x.second<y.second;
}
signed main()
{
	int n,ans=1;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].first >> a[i].second;
		ans*=i,ans%=mod;
	}
	sort(a+1,a+n+1);
	int cnt=1,now=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].first!=a[i-1].first)
			cnt=1;
		else ++cnt;
		now*=cnt,now%=mod;
	}
	ans-=now;cnt=1,now=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].first!=a[i-1].first||a[i].second!=a[i-1].second)
			cnt=1;
		else ++cnt;
		if(a[i].second<a[i-1].second)now=0;
		now*=cnt,now%=mod;
	}
	ans+=now;sort(a+1,a+n+1,cmp);cnt=1,now=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].second!=a[i-1].second)
			cnt=1;
		else ++cnt;
		now*=cnt,now%=mod;
	}
	ans-=now;
	cout << (ans%mod+mod)%mod;
}