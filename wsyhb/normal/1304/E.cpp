#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
int End[M],Last[N],Next[M],f[N][20],dep[N];
int cnt;
void add(int x,int y)
{
	End[++cnt]=y;
	Next[cnt]=Last[x];
	Last[x]=cnt;
}
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=18;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa) dfs(y,x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int k=dep[x]-dep[y];
	for(int i=18;i>=0;i--)
		if(k&(1<<i)) x=f[x][i];
	if(x==y) return x;
	for(int i=18;i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int dis(int x,int y)
{
	int p=lca(x,y);
	return dep[x]+dep[y]-(dep[p]<<1);
}
bool check(int s,int k)
{
	return s<=k&&((k-s)&1)==0;
}
int main()
{
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
	scanf("%d",&q);
	while(q--)
	{
		int x,y,a,b,k;
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		int d1=dis(a,b),d2=dis(a,x)+dis(b,y)+1,d3=dis(a,y)+dis(b,x)+1;
		if(check(d1,k)||check(d2,k)||check(d3,k)||check(d1+d2+d3,k)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}