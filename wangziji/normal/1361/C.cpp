#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
pair <int,int> a[1100005];
int head[1100005],cnt;
struct edge
{
	int v,n,f,id;
}e[2200005];
int fa[1100005],deg[1100005],ans[1100005],vis[2200005],Cnt,Vis[1100005];
inline void add(int u,int v,int f,int id)
{
	e[++cnt]={v,head[u],f,id};
	head[u]=cnt;
}
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
inline void dfs(int u,int lst)
{
	++Vis[u];
	int now=Vis[u];
	for(int i=head[u];i;i=e[i].n)
	{
		head[u]=e[i].n;
		if(Vis[u]!=now) break;
		if(vis[i]) continue;
		vis[i]=1;
		if(e[i].f) vis[i-1]=1;
		else vis[i+1]=1;
		dfs(e[i].v,e[i].id);
	}
	ans[++Cnt]=lst;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	for(int i=20;i>=0;i--)
	{
		int X=(1<<i)-1;
		for(int i=0;i<=X;i++) fa[i]=i;
		memset(deg,0,sizeof deg);
		for(int j=1;j<=n;j++)
		{
			fa[ff(a[j].first&X)]=ff(a[j].second&X);
			++deg[a[j].first&X],++deg[a[j].second&X];
		}
		int F=-1,flag=1;
		for(int j=0;j<=X;j++)
		{
			if(deg[j]&1) flag=0;
			if(deg[j]) if(F==-1) F=ff(j);
			if(deg[j]&&ff(j)!=F) flag=0;
		}
		if(flag)
		{
			cout << i << "\n";
			for(int j=1;j<=n;j++)
				add(a[j].first&X,a[j].second&X,0,j*2-1),add(a[j].second&X,a[j].first&X,1,j*2);
			for(int j=0;j<=X;j++)
			{
				if(deg[j])
				{
					dfs(j,0);
					break;
				}
			}
			break;
		}
	}
	--Cnt;
	for(int i=1;i<=Cnt;i++)
	{
		if(ans[i]&1)
			printf("%d %d ",ans[i]+1,ans[i]);
		else printf("%d %d ",ans[i]-1,ans[i]);
	}
	return 0;
}