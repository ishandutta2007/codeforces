#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000050;
vector<int> E[N];
int disc[N],low[N],tid,comp[N],csz;
bool in[N];
stack<int> s;
void Tarjan(int u)
{
	disc[u]=low[u]=++tid;
	in[u]=1;s.push(u);
	for(int v:E[u])
	{
		if(!disc[v])
		{
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v]) low[u]=min(low[u],disc[v]);
	}
	if(disc[u]==low[u])
	{
		int v;
		csz++;
		do
		{
			v=s.top();
			s.pop();
			in[v]=0;
			comp[v]=csz;
		}while(v!=u);
	}
}
bool was[N];
void DFS(int u)
{
	was[u]=1;
	for(int v:E[u]) if(!was[v]) DFS(v);
}
int main()
{
    int t;
    scanf("%i",&t);
    while(t--)
	{
		int n,m;
		scanf("%i %i",&n,&m);
		for(int i=1;i<=n;i++) E[i].clear(),disc[i]=low[i]=was[i]=comp[i]=0;
		csz=tid=0;
		for(int i=1,u,v;i<=m;i++) scanf("%i %i",&u,&v),E[u].pb(v);
		int last=-1;
		for(int i=1;i<=n;i++) if(!disc[i]) Tarjan(i),last=i;
		int o=-1;
		for(int i=1;i<=n;i++) if(comp[i]!=comp[last]) o=i;
		if(o==-1){ printf("No\n");continue;}
		DFS(o);
		vector<int> jury,cats;
		for(int i=1;i<=n;i++)
		{
			if(was[i]) jury.pb(i);
			else cats.pb(i);
		}
		printf("Yes\n%i %i\n",jury.size(),cats.size());
		for(int i:jury) printf("%i ",i);printf("\n");
		for(int i:cats) printf("%i ",i);printf("\n");
	}
	return 0;
}