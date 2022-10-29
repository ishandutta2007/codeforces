#include <iostream>
#include <cstdio>
using namespace std;
struct edge
{
	int v,n;
}e[500005];
int head[200005],cnt,dep[200005],f[200005][20];
inline void add(int u,int v)
{
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
inline void dfs(int u,int fa)
{
	f[u][0]=fa;
	for(int i=1;i<=19;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].n)
	{
		if(e[i].v==fa)
			continue;
		dep[e[i].v]=dep[u]+1;
		dfs(e[i].v,u);
	}
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=19;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
inline int dis(int x,int y)
{
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int main(int argc, char** argv) {
	int n,m;
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dep[1]=1;
	dfs(1,0);
	int q;
	cin >> q;
	while(q--)
	{
		int x,y,a,b,k;
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		int ans=0;
		int t=dis(a,b);
		if(t<=k&&t%2==k%2) ans=1;
		t=dis(a,x)+1+dis(y,b);
		if(t<=k&&t%2==k%2) ans=1;
		t=dis(a,y)+1+dis(x,b);
		if(t<=k&&t%2==k%2) ans=1;
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}