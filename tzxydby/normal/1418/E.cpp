#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,mod=998244353;
int n,m,d[N],s[N],f[N]={1},iv[N]={1},dp[N];
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
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	sort(d+1,d+n+1);
	reverse(d+1,d+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+d[i];
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		int l=0,r=n+1;
		while(r-l>1)
		{
			int m=l+r>>1;
			if(d[m]<b)
				r=m;
			else
				l=m;
		}
		r--;
		if(a>r)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<(s[r]%mod*(r-a)%mod*qp(r,mod-2)%mod+(s[n]-s[r])%mod*(r+1-a)%mod*qp(r+1,mod-2)%mod)%mod<<endl;
	}
	return 0;
}