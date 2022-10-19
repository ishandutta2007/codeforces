#include<iostream>
#include<cstdio>
#include<cmath>
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
int qz[200005];
bool vis[200005];
signed main()
{
	int t,n,ans=0,now=0;
	int nmax;
	int x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),vis[i]=false;
		x=read();
		qz[0]=0;
		for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i]-x;
		vis[0]=true; 
		ans=n;
		nmax=-1121131433448687LL;
		for(int i=1;i<=n;i++)
		{
			if(qz[i]>=nmax)
			{
				nmax=max(nmax,qz[i-1]);
				vis[i]=true;
				//printf("%d\n",i);
			}
			else
			{
				nmax=-1121131433448687LL;
				vis[i]=false;
				ans--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}