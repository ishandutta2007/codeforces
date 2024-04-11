#include <iostream>
#include <cstring>
using namespace std;
struct edge
{
	int v,n;
}e[100005];
int head[205],cnt,E[200][200],deg[200],vis[200];
int flag;
inline void add(int u,int v)
{
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
inline void dfs(int u,int f)
{
	if(f) cout << (char)u;
	vis[u]=1;
	for(int i=head[u];i;i=e[i].n)
	{
		if(!vis[e[i].v])
			dfs(e[i].v,f);
	}
}
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		cnt=0;
		flag=0;
		memset(E,0,sizeof E);
		memset(deg,0,sizeof deg);
		memset(vis,0,sizeof vis);
		memset(head,0,sizeof head);
		string a;
		cin >> a;
		for(int i=0;i<a.size()-1;i++)
		{
			if(E[a[i]][a[i+1]]) continue;
			E[a[i]][a[i+1]]=E[a[i+1]][a[i]]=1;
			++deg[a[i]],++deg[a[i+1]];
			add(a[i],a[i+1]);
			add(a[i+1],a[i]);
		}
		int t=-1;
		int flag=0;
		for(int i=1;i<=150;i++)
		{
			if(deg[i]==1&&!vis[i]) dfs(i,0);
			if(deg[i]>=3) flag=1;
		}
		for(int i=1;i<=150;i++)
			if(!vis[i]&&deg[i]==2) flag=1;
		if(flag)
		{
			puts("NO");
			continue;
		}
		memset(vis,0,sizeof vis);
		puts("YES");
		for(int i='a';i<='z';i++)
		{
			if(!vis[i]&&deg[i]==1)
				dfs(i,1);
		}
		for(int i='a';i<='z';i++)
		{
			if(!vis[i])
				dfs(i,1);
		}
		puts("");
	}
	return 0;
}