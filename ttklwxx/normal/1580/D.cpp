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
int a[100005];
int ls[100005],rs[100005],rt;
int sta[100005],tmp;
int dp[4005][4005];
int siz[4005]; 
int n,m;
int jdz(int x)
{
	if(x<0)return -x;
	return x;
} 
void dfs(int x)
{
	siz[x]=1;
	if(ls[x]!=0)dfs(ls[x]);
	for(int i=min(m,siz[x]);i>=0;i--)
	{
		for(int j=min(m,siz[ls[x]]);j>=0;j--)
		{
			dp[x][i+j]=max(dp[x][i+j],dp[x][i]+dp[ls[x]][j]+j*(m-j)*jdz(a[x]-a[ls[x]]));
		}
	}
	siz[x]+=siz[ls[x]];
	if(rs[x]!=0)dfs(rs[x]);
	for(int i=min(siz[x],m);i>=0;i--)
	{
		for(int j=min(siz[rs[x]],m);j>=0;j--)
		{
			dp[x][i+j]=max(dp[x][i+j],dp[x][i]+dp[rs[x]][j]+j*(m-j)*jdz(a[x]-a[rs[x]]));
		}
	}
	siz[x]+=siz[rs[x]];
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		while(tmp>=1&&a[sta[tmp]]>=a[i])
		{
			ls[i]=sta[tmp];
			tmp--;
		}
		if(tmp>=1)
		{
			rs[sta[tmp]]=i;
		}
		else rt=i;
		sta[++tmp]=i;
	}
	//for(int i=1;i<=n;i++)printf("%lld %lld\n",ls[i],rs[i]);
	dfs(rt);
	printf("%lld\n",dp[rt][m]);
	return 0;
}