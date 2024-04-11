#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define N 4105
#define M 500005
int c[N],a[13],n,m,Q,S;int v[N][101];
void dfs(int dep,int sum,int s)
{
	if(sum>100)return ;
	if(dep==n)
	{
		if(!c[s])return ;
		// printf("%d %d %d\n",S,s,sum);
		v[S][sum]+=c[s];
		return ;
	}
	if(S&(1<<dep))dfs(dep+1,sum+a[n-dep],s|(1<<dep)),dfs(dep+1,sum,s);
	else dfs(dep+1,sum+a[n-dep],s),dfs(dep+1,sum,s|(1<<dep));
}
// int find(int S,int x)
// {
// 	int l=0,r=(int)v[S].size();
// 	while(l<r)
// 	{
// 		int m=(l+r)>>1;
// 		if(v[S][m].first<=x)l=m+1;
// 		else r=m;
// 	}//printf("%d\n",l);
// 	// return v[S][l].second;
// 	// printf("%d\n",(int)v[S].size());
// 	return v[S][l-1].second;
// }
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int x=0,tmp;
		for(int i=n-1;~i;i--)scanf("%1d",&tmp),x|=(tmp<<i);
		c[x]++;
	}
	for(S=0;S<(1<<n);S++)
	{
		// if(!c[S])continue;
		dfs(0,0,0);
		for(int i=1;i<=100;i++)v[S][i]+=v[S][i-1];
	}
	while(Q--)
	{
		int tmp,k;S=0;
		for(int i=n-1;~i;i--)scanf("%1d",&tmp),S|=(tmp<<i);
		scanf("%d",&k);
		printf("%d\n",v[S][k]);
	}
}