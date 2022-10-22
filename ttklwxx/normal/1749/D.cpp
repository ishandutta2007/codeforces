#include<iostream>
#include<cstdio>
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
int pri[300005],cnt;
bool vis[300005];
int ksm(int n,int k)
{
	n%=mod;
	int ans=1;
	//printf("%lld %lld ",n,k);
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	//printf("%lld\n",ans);
	return ans;
}
signed main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=2;i<=n;i++)
	{
		if(vis[i]==false)
		{
			pri[++cnt]=i; 
		}
		for(int j=1;j<=cnt&&i*pri[j]<=n;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	int now=1,ans=1,zh=0;
	for(int i=1;i<=n;i++)zh=(zh+ksm(m,i))%mod;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			now=1LL*now*i;
			if(now>m)
			{
				break;
			}
		}
		//printf("%lld %lld\n",i,now);
		ans=1LL*ans*((m/now)%mod)%mod;
		zh=(zh+mod-ans)%mod;
	}
	printf("%lld\n",zh);
}