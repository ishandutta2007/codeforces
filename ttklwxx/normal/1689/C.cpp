#include<iostream>
#include<cstdio>
#include<algorithm>
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
int dp[300005],siz[300005];
struct bbian
{
	int u,v,nex;
}a[800004];
int head[300005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
void dfs(int x,int f)
{
	int sth1=0,sth2=0;
	siz[x]=1;
	dp[x]=0;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x);
		siz[x]+=siz[a[i].v];
		if(sth1==0)sth1=a[i].v;
		else if(sth2==0)sth2=a[i].v;
	}
	if(sth1!=0&&sth2!=0)dp[x]=max(dp[sth1]+siz[sth2]-1,dp[sth2]+siz[sth1]-1);
	else if(sth1!=0)dp[x]=siz[sth1]-1;
}
int main()
{
	int ttt,n,x,y;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)head[i]=0;
		tmp=0;
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			addb(x,y);
			addb(y,x);
		}
		dfs(1,0);
		printf("%d\n",dp[1]);
	}
	return 0;
}