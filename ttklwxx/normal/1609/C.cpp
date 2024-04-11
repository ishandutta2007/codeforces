#include<iostream>
#include<cstdio>
#define int long long
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
int a[200005];
bool vis[1000005];
int pri[1000005],cnt;
int nex[200005],las[200005];
signed main()
{
	vis[1]=true;
	for(int i=2;i<=1000000;i++)
	{
		if(!vis[i])
		{
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=1000000;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	int t,n,e,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		e=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)
		{
			if(i-e<=0)las[i]=i;
			else if(a[i-e]==1)las[i]=las[i-e];
			else las[i]=i;
		}
		for(int i=n;i>=1;i--)
		{
			if(i+e>n)nex[i]=i;
			else if(a[i+e]==1)nex[i]=nex[i+e];
			else nex[i]=i;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[a[i]])continue;
			//printf("%lld %lld %lld\n",i,las[i],nex[i]);
			ans+=((nex[i]-i)/e+1)*((i-las[i])/e+1)-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}