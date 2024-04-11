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
int l[200005],r[200005];
struct bbian
{
	int u,v,nex;
}a[800004];
int head[200005],tmp;
inline void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int dp[200005][2];
inline int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
void dfs(int x,int f)
{
	dp[x][0]=dp[x][1]=0;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x);
		dp[x][0]=dp[x][0]+max(dp[a[i].v][1]+jdz(r[a[i].v]-l[x]),dp[a[i].v][0]+jdz(l[a[i].v]-l[x]));
		dp[x][1]=dp[x][1]+max(dp[a[i].v][1]+jdz(r[a[i].v]-r[x]),dp[a[i].v][0]+jdz(l[a[i].v]-r[x]));
	}
}
signed main()
{
	int t,n,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			l[i]=read();
			r[i]=read();
		}
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			addb(x,y);
			addb(y,x);
		}
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
		tmp=0;
		for(int i=1;i<=n;i++)
		{
			head[i]=0;
			dp[i][0]=dp[i][1]=0;
		}
	}
	return 0;
}