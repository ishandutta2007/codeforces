#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1005
int used[10]={1,2,3,4,5,6,7,8};
int n,a[N],s[10][N],vis[10],now,ans,t[10][N][N];
int find(int p,int op,int k)
{
	if(t[op][p][k])return t[op][p][k];
	int l=p,r=n+1;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(s[op][m]-s[op][p]>=k)r=m;
		else l=m+1;
	}return t[op][p][k]=l;
}
void dfs(int sta,int sum,int p)
{
	if(p>=n+1)return ;
	if(sta==255){ans=max(ans,sum);return ;}
	for(int i=0;i<8;i++)if(!((1<<i)&sta))
	{
		int x=find(p,used[i],now);
		dfs(sta|(1<<i),sum+now,x);
		x=find(p,used[i],now-1);
		dfs(sta|(1<<i),sum+now-1,x);
	}
}
int main()
{
	// freopen("numstr.in","r",stdin);
	// freopen("numstr.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		// vis[a[i]]=1;
		for(int j=1;j<=9;j++)s[j][i]=s[j][i-1]+(a[i]==j);
	}
	// int sta=0;
	// for(int i=0;i<8;i++)if(!vis[used[i]])sta|=1<<i;
	for(now=1;now<=n;now++)dfs(0,0,0);
	printf("%d\n",ans);
}