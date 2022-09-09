#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
vector<pair<int,int> > E[N];
vector<int> cycle;
map<int,bool> used[N],my[N];
int sol[N],was[N];
struct DSU
{
	int p[N];
	void init(){ for(int i=0;i<N;i++) p[i]=i;}
	DSU(){ init();}
	int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]);}
	void Union(int x, int y, int id)
	{
		E[x].pb(mp(y,id));E[y].pb(mp(x,id));
		//printf("%i - %i %i\n",x,y,id);
		if(Find(x)==Find(y)) cycle.pb(x);
		else p[Find(x)]=Find(y);
	}
} Tree;
void DFS(int u)
{
	was[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int id=E[u][i].second;
		if(!was[v])
		{
			used[u][id]=used[v][id]=1;
			sol[v]=id;
			DFS(v);
		}
		else
		{
			if(used[u][id]) continue;
			if(!sol[v])
			{
				sol[v]=id;
				used[u][id]=used[v][id]=1;
			}
		}
	}
}
int fin[N];
vector<int> pos[N],neg[N];
int main()
{
	int q,n,i,j;
	scanf("%i %i",&q,&n);
	for(i=1;i<=q;i++)
	{
		int sz,x;
		scanf("%i",&sz);
		while(sz--)
		{
			scanf("%i",&x);
			if(x>0) pos[x].pb(i),my[i][x]=1;
			else neg[-x].pb(i),my[i][-x]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(pos[i].size() && neg[i].size()) Tree.Union(pos[i][0],neg[i][0],i);
		else
		{
			for(j=0;j<pos[i].size();j++) Tree.Union(pos[i][j],pos[i][j],i);
			for(j=0;j<neg[i].size();j++) Tree.Union(neg[i][j],neg[i][j],i);
		}
	}
	for(i=0;i<cycle.size();i++) if(!was[cycle[i]]) DFS(cycle[i]);
	for(i=1;i<=q;i++) if(!was[i]) DFS(i);
	for(i=1;i<=q;i++) if(!sol[i]) return printf("NO\n"),0;
	for(i=1;i<=q;i++)
	{
		if(my[i][sol[i]]==1) fin[sol[i]]=1;
		else fin[sol[i]]=0;
		//printf("%i: %i %i\n",i,sol[i],my[i][sol[i]]);
	}
	//printf("\n");
	printf("YES\n");
	for(i=1;i<=n;i++) printf("%i",fin[i]);
	printf("\n");
	return 0;
}