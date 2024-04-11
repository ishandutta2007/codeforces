#include <iostream>
#include <cstdio>
using namespace std;
struct edge
{
	int v,n;
}e[1000005];
int head[500005],cnt,dep[500005],f[500005][20];
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
//	cout << x << " " << y << " " << dep[x]+dep[y]-2*dep[lca(x,y)] << "\n";
//	cout << lca(x,y) << "\n";
	return dep[x]+dep[y]-2*dep[lca(x,y)]+1; 
}
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=2;i<=n;i++)
	{
		int x;
		cin >> x;
		add(x,i);
	}
	dep[1]=1;
	dfs(1,0);
	while(m--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		printf("%d\n",(max(dis(x,y)+dis(x,z)-dis(y,z),max(dis(x,z)+dis(y,z)-dis(x,y),dis(y,z)+dis(y,x)-dis(x,z)))+1)/2);
	}
	return 0;
}