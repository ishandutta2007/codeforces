#include <iostream>
using namespace std;
int ans[5005];
struct edge
{
	int v,n;
}e[100005];
int vis[5005],head[5005],cnt;
inline void add(int u,int v)
{
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
inline void dfs(int u,int F)
{
	for(int i=head[u];i;i=e[i].n)
	{
		if(vis[e[i].v]!=F)
		{
			vis[e[i].v]=F;
			dfs(e[i].v,F);
		}
	}
}
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		add(u,v);
		ans[i]=(u>v)+1;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,i);
		if(vis[i]==i)
		{
			cout << 2 << endl;
			for(int j=1;j<=m;j++)
				cout << ans[j] << " ";
			return 0;
		}
	}
	cout << 1 << endl;
	for(int i=1;i<=m;i++)
		cout << 1 << " ";
	return 0;
}