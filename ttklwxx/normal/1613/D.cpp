#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
#define mod 998244353
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[500005],dp[500005];
int sl[500005];
int ans[500005];
signed main()
{
	int t,n,tans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=0;i<=n;i++)sl[i]=1,ans[i]=0;
		for(int i=1;i<=n;i++)a[i]=read(),sl[a[i]]=sl[a[i]]*2%mod;
		dp[0]=0;
		tans=sl[1]-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)dp[i]=ans[a[i]]+1,ans[a[i]]=(ans[a[i]]+dp[i])%mod,sl[a[i]]=sl[a[i]]*(mod+1)/2%mod;
			else
			{
				dp[i]=(ans[a[i]]+ans[a[i]-1])%mod;
				ans[a[i]]=(ans[a[i]]+dp[i])%mod;
				sl[a[i]]=sl[a[i]]*(mod+1)/2%mod;
				if(a[i]>=2)tans=(tans+ans[a[i]-2]*sl[a[i]]%mod*sl[a[i]-2]%mod)%mod;
			}
		}
		for(int i=0;i<=n;i++)
		{
			tans=(tans+ans[i])%mod; 
		}
		printf("%lld\n",tans); 
	} 
	return 0;
}