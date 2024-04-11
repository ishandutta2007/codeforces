#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=300005,M=55,mod=998244353;
int n,m,l[N],r[N],a[M],b[M],z[N],f[N]={1},iv[N]={1},s[N][M],ans,co[N];
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
int c(int n,int m){if(n<m||m<0)return 0;return f[n]*iv[m]%mod*iv[n-m]%mod;}
signed main()
{
	ios::sync_with_stdio(false);
	for(int i=1;i<=3e5;i++)
		f[i]=f[i-1]*i%mod,iv[i]=qp(f[i],mod-2);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		z[l[i]]++;
		z[r[i]+1]--;
	}
	for(int i=1;i<=n;i++)
	{
		z[i]+=z[i-1];
		for(int j=0;j<=2*m;j++)
			s[i][j]=(s[i-1][j]+c(z[i]-j,i-j))%mod;
	}
	for(int i=0;i<m;i++)
		cin>>a[i]>>b[i];
	for(int i=0;i<(1ll<<m);i++)
	{
		int le=1,ri=n,t=0;
		for(int j=0;j<m;j++)
		{
			if(!(i&(1ll<<j)))
				continue;
			if(co[a[j]]!=i)
			{
				co[a[j]]=i;
				t++;
			}
			if(co[b[j]]!=i)
			{
				co[b[j]]=i;
				t++;
			}
			le=max(le,max(l[a[j]],l[b[j]]));
			ri=min(ri,min(r[a[j]],r[b[j]]));
		}
		if(le>ri)
			continue;
		int k=(s[ri][t]-s[le-1][t]+mod)%mod;
		if(__builtin_popcount(i)&1)
			ans=(ans+mod-k)%mod;
		else
			ans=(ans+k)%mod;
	}
	cout<<ans<<endl;
	return 0;
}