#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=300050;
int comp[N],sz[N];
bool was[N];
vector<int> E[N];
void DFS(int u, int c)
{
	was[u]=1;
	comp[u]=c;
	sz[c]++;
	for(int v:E[u]) if(!was[v]) DFS(v,c);
}
const int inf=1e9+7;
void BFS(int st, int n, int dist[], int go[])
{
	for(int i=1;i<=n;i++) dist[i]=inf,go[i]=0;
	dist[st]=0;
	queue<int> q;
	q.push(st);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int v:E[u]) if(dist[v]>dist[u]+1) dist[v]=dist[u]+1,go[v]=u,q.push(v);
	}
}
void AddEdge(int u, int v)
{
	if(v!=1) E[u].pb(v);
	if(u!=1) E[v].pb(u);
}
int dist[N],go[N];
int main()
{
	int n,m,i,j,u,v;
	scanf("%i %i",&n,&m);
	while(m--) scanf("%i %i",&u,&v),AddEdge(u,v);
	for(i=2;i<=n;i++) if(!was[i]) DFS(i,i);
	BFS(1,n,dist,go);
	int asz=inf;
	vector<int> ans;
	if(dist[n]!=inf)
	{
		asz=dist[n];
		for(u=n;u;u=go[u]) ans.pb(u);
		reverse(ans.begin(),ans.end());
	}
	if(asz>4)
	{
		for(i=2;i<=n;i++) if(dist[i]==2)
		{
			asz=4;
			ans.clear();
			ans.pb(1);
			ans.pb(go[i]);
			ans.pb(i);
			ans.pb(1);
			ans.pb(n);
			break;
		}
	}
	if(asz>5)
	{
		for(i=2;i<=n;i++) if(dist[i]!=inf && E[i].size()!=sz[comp[i]]-1)
		{
			asz=5;
			BFS(i,n,dist,go);
			for(j=2;j<=n;j++) if(dist[j]==2)
			{
				ans.clear();
				ans.pb(1);
				ans.pb(i);
				ans.pb(go[j]);
				ans.pb(j);
				ans.pb(i);
				ans.pb(n);
				break;
			}
			break;
		}
	}
	if(asz==inf) return 0*printf("-1\n");
	printf("%i\n",asz);
	for(i:ans) printf("%i ",i);
	return 0;
}