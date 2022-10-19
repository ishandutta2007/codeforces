#include<iostream>
#include<cstdio>
#include<algorithm>
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
int p[1000005],q[1000005];
int dy[1000005];
int hc[1000005],cnt;
bool vis[1000005];
bool sc[1000005];
int tans[1000005],tmp;
signed main()
{
	int t,n,m,x,nh,sl,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)p[i]=read();
		for(int i=1;i<=n;i++)q[i]=read();
		for(int i=1;i<=n;i++)dy[p[i]]=q[i];
		for(int i=1;i<=n;i++)vis[i]=false;
		sl=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			nh=1;
			vis[i]=true;
			x=dy[i];
			while(x!=i)
			{
				vis[x]=true;
				nh++;
				x=dy[x];
			}
			hc[++cnt]=nh;
			if(nh%2==1)sl++;
		}
		ans=0;
		for(int i=n-(n-sl)/2+1;i<=n;i++)ans+=i;
		for(int i=1;i<=(n-sl)/2;i++)ans-=i;
		printf("%lld\n",ans*2);
	}
	return 0;
}