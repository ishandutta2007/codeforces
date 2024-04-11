#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=400050;
int neg(int x){ return x*2;}
int pos(int x){ return x*2+1;}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
struct SAT2
{
	int tot;
	vector<int> E[N],scc[N];
	vector<pair<int,int> > edges;
	SAT2(){}
	void Clear(){ for(int i=0;i<=tot;i++) E[i].clear();tot=0;edges.clear();}
	void Add(int u, int v)
	{
		E[u^1].pb(v);
		E[v^1].pb(u);
		edges.pb(mp(u^1,v));
		edges.pb(mp(v^1,u));
		tot=max(tot,u|1);
		tot=max(tot,v|1);
	}
	bool was[N];
	int cnt,comp[N],disc[N],low[N],time;
	stack<int> s;
	void Init()
	{
		int i;
		for(i=0;i<=tot;i++) was[i]=disc[i]=low[i]=comp[i]=0;
		for(i=0;i<=cnt;i++) scc[i].clear();
		cnt=time=0;
	}
	void DFS(int u)
	{
		was[u]=1;
		s.push(u);
		disc[u]=low[u]=++time;
		for(int i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			if(!disc[v])
			{
				DFS(v);
				low[u]=min(low[u],low[v]);
			}
			else if(was[v]) low[u]=min(low[u],disc[v]);
		}
		if(disc[u]==low[u])
		{
			cnt++;
			int v;
			do
			{
				v=s.top();
				s.pop();
				comp[v]=cnt;
				scc[cnt].pb(v);
				was[v]=0;
			}while(v!=u);
		}
	}
	bool Check()
	{
		Init();
		int i;
		for(i=0;i<=tot;i++) if(!disc[i]) DFS(i);
		for(i=0;i<=tot;i++) if(comp[i]==comp[i^1]) return 0;
		return 1;
	}
	bool sol[N];
	int in[N],exp[N];
	vector<int> G[N];
	queue<int> q;
	void Solve()
	{
		int i;
		for(i=0;i<edges.size();i++)
		{
			int u=comp[edges[i].first];
			int v=comp[edges[i].second];
			if(u!=v) G[u].pb(v),in[v]++;
		}
		for(i=1;i<=cnt;i++) exp[i]=0;
		for(i=1;i<=cnt;i++) if(!in[i]) q.push(i);
		time=0;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			exp[u]=++time;
			for(i=0;i<G[u].size();i++)
			{
				int v=G[u][i];
				in[v]--;
				if(!in[v]) q.push(v);
			}
		}
		for(i=0;i<=tot;i+=2)
		{
			if(exp[comp[i]]<exp[comp[i+1]]) sol[i>>1]=1;
			else sol[i>>1]=0;
		}
	}
} SAT;
int col[N],n,m;
vector<pair<int,int> > E[N];
struct Edge
{
	int u,v,c,t,i;
	Edge(int a, int b, int d, int e, int f){ u=a,v=b,c=d,t=e,i=f;}
	bool operator < (Edge b) const { return t<b.t;}
};
vector<Edge> edges;
int cnt[N],lst[N];
bool Check(int t)
{
	//printf("Check %i\n",t);
	int i,j;SAT.Clear();
	for(i=1;i<=n;i++) E[i].clear();
	for(i=0;i<edges.size() && edges[i].t<=t;i++)
	{
		E[edges[i].u].pb(mp(edges[i].v,i));
		E[edges[i].v].pb(mp(edges[i].u,i));
	}
	for(;i<edges.size();i++)
	{
		SAT.Add(neg(edges[i].i),neg(edges[i].i));
		E[edges[i].u].pb(mp(edges[i].v,i));
		E[edges[i].v].pb(mp(edges[i].u,i));
	}
	for(i=0;i<N;i++) cnt[i]=lst[i]=0;
	int tot=m;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<E[i].size();j++)
		{
			cnt[edges[E[i][j].second].c]++;
			if(cnt[edges[E[i][j].second].c]>2) return 0;
			if(cnt[edges[E[i][j].second].c]==2)
			{
				SAT.Add(pos(lst[edges[E[i][j].second].c]),pos(edges[E[i][j].second].i));
				//printf("Add pos(%i) V pos(%i)\n",lst[edges[E[i][j].second].c],edges[E[i][j].second].i);
			}
			else lst[edges[E[i][j].second].c]=edges[E[i][j].second].i;
		}
		for(j=0;j<E[i].size();j++) cnt[edges[E[i][j].second].c]=0;
		for(j=0;j<E[i].size();j++)
		{
			tot++;
			SAT.Add(neg(edges[E[i][j].second].i),pos(tot));
			//printf("Add neg(%i) V pos(%i)\n",edges[E[i][j].second].i,tot);
			if(j)
			{
				SAT.Add(neg(tot-1),pos(tot));
				//printf("Add neg(%i) V pos(%i)\n",tot-1,tot);	
				SAT.Add(neg(tot-1),neg(edges[E[i][j].second].i));
				//printf("Add neg(%i) V pos(%i)\n",tot-1,edges[E[i][j].second].i);
			}
		}
	}
	return SAT.Check();
}
map<int,int> id;
vector<int> sol;
int main()
{
	scanf("%i %i",&n,&m);
	int i,u,v,c,t,o=0;
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i %i",&u,&v,&c,&t);
		c=id[c]?id[c]:id[c]=++o;
		edges.pb(Edge(u,v,c,t,i));
	}
	sort(edges.begin(),edges.end());
	int top=1e9,bot=0,mid,ans=-1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid)) top=mid-1,ans=mid;
		else bot=mid+1;
	}
	if(ans==-1) printf("No\n");
	else
	{
		printf("Yes\n");
		Check(ans);
		SAT.Solve();
		for(i=1;i<=m;i++) if(SAT.sol[i]==1) sol.pb(i);
		printf("%i %i\n",ans,sol.size());
		for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
		printf("\n");
	}
	return 0;
}