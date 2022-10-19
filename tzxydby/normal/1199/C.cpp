#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=400005;
int a[N],s[N],n,k,cnt;
map<int,int>mp;
inline int get_s(int l,int r)
{
	if(r<l) return 0;
	return s[r]-s[l-1];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	k=k*8/n;
	int d=1;
	while(k--)
	{
		d*=2;
		if(d>=n)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(mp.find(a[i])==mp.end())
			mp[a[i]]=++cnt;
	for(int i=1;i<=n;i++)
	{
		a[i]=mp[a[i]];
		s[a[i]]++;
	}
	for(int i=1;i<=cnt;i++)
		s[i]+=s[i-1];
	int ans=1e9;
	for(int i=1;i<=cnt;i++)
	{
		int j=min(i+d-1,n);
		//cout<<i<<' '<<j<<' '<<get_s(1,i-1)<<' '<<get_s(j+1,cnt)<<endl;
		ans=min(ans,get_s(1,i-1)+get_s(j+1,cnt));
	}
	cout<<ans<<endl;
	return 0;
}