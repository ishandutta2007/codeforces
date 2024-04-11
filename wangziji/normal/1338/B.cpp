#include <iostream>
using namespace std;
struct edge
{
	int v,n;
}e[200005];
int cnt,head[100005],dep[100005],ans,yezi[100005];
inline void add(int u,int v)
{
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
inline void dfs(int u,int f)
{
	yezi[u]=2;
	for(int i=head[u];i;i=e[i].n)
	{
		--yezi[u];
		if(e[i].v==f) continue;
		dep[e[i].v]=dep[u]+1;
		dfs(e[i].v,u);
	}
	yezi[u]=max(yezi[u],0);
}
inline void dfs2(int u,int f)
{
	int cnt=0;
	for(int i=head[u];i;i=e[i].n)
	{
		if(yezi[e[i].v]==1) ++cnt;
		if(e[i].v==f) continue;
		dfs2(e[i].v,u);
	}
	if(cnt>1) ans-=cnt-1;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		add(u,v),add(v,u);
	}
	ans=n-1;
	dfs(1,0),dfs2(1,0);
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(yezi[i])
		{
			for(int j=1;j<=n;j++)
			{
				if(yezi[j]==1&&dep[i]%2!=dep[j]%2)
				{
					flag=1;
					cout << "3 ";
					break;
				}
			}
			if(!flag) cout << "1 ";
			break;
		}
	}
	cout << ans;
	return 0;
}