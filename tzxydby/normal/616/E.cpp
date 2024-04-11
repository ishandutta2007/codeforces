#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,m,ans;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	if(m>n)
	{
		ans=n%mod*(m%mod-n%mod+mod)%mod;
		m=n;
	}
	ans=(ans+(n%mod)*(m%mod)%mod)%mod;
	int iv2=qp(2,mod-2);
	for(int l=1,r;l<=m;l=r+1)
	{
		r=n/(n/l);
		if(r>m)
			r=m;
		int v=n/l,s=(l+r)%mod*((r-l+1)%mod)%mod*iv2%mod;
		int c=v*s%mod;
		ans=(ans+mod-c)%mod;
	}
	cout<<ans<<endl;
	return 0;
}