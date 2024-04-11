#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=2*N;
int pos(int x){ return x<<1;}
int neg(int x){ return x<<1|1;}
struct TwoSat
{
	int sz,sol[N];
	vector<int> E[M],G[M];
	TwoSat(){ sz=0;}
	void addEdge(int u, int v)
	{
		E[u].pb(v);sz=max(sz,u|1);sz=max(sz,v|1);
		//printf("(%i, %i) -> (%i, %i)\n",u/2,u&1,v/2,v&1);
	}
	int disc[M],low[M],tid,comp[M],cnt;
	stack<int> s;
	bool in[M];
	void Trajan(int u)
	{
		low[u]=disc[u]=++tid;
		in[u]=1;s.push(u);
		for(int i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			if(!disc[v])
			{
				Trajan(v);
				low[u]=min(low[u],low[v]);
			}
			else if(in[v]) low[u]=min(low[u],disc[v]);
		}
		if(low[u]==disc[u])
		{
			int v;
			cnt++;
			do
			{
				v=s.top();
				s.pop();
				in[v]=0;
				comp[v]=cnt;
			}while(v!=u);
		}
	}
	bool Check()
	{
		for(int i=0;i<=sz;i++) if(!disc[i]) Trajan(i);
		for(int i=0;i<=sz;i+=2) if(comp[i]==comp[i^1]) return 0;
		return 1;
	}
	int fsz[M],tme[M];
	void Solve()
	{
		queue<int> q;
		for(int i=0;i<=sz;i++)
		{
			int u=i;
			for(int j=0;j<E[i].size();j++)
			{
				int v=E[i][j];
				if(comp[u]!=comp[v]) G[comp[u]].pb(comp[v]),fsz[comp[v]]++;
			}
		}
		for(int i=1;i<=cnt;i++) if(!fsz[i]) q.push(i);
		int csz=0;
		while(q.size())
		{
			int u=q.front();q.pop();
			tme[u]=++csz;
			for(int i=0;i<G[u].size();i++)
			{
				int v=G[u][i];
				fsz[v]--;
				if(!fsz[v]) q.push(v);
			}
		}
		for(int i=0;i<=sz/2;i++) sol[i]=tme[comp[pos(i)]]>tme[comp[neg(i)]];
	}
} TwoSat;
int c[N];
map<int,int> id;
int main()
{
	int n,a,b,i;
	scanf("%i %i %i",&n,&a,&b);
	for(i=1;i<=n;i++) scanf("%i",&c[i]),id[c[i]]=i;
	for(i=1;i<=n;i++)
	{
		if(id[a-c[i]])
		{
			int j=id[a-c[i]];
			TwoSat.addEdge(neg(i),neg(j));
			TwoSat.addEdge(pos(j),pos(i));
		}
		else TwoSat.addEdge(neg(i),pos(i));
		if(id[b-c[i]])
		{
			int j=id[b-c[i]];
			TwoSat.addEdge(pos(i),pos(j));
			TwoSat.addEdge(neg(j),neg(i));
		}
		else TwoSat.addEdge(pos(i),neg(i));
	}
	if(TwoSat.Check())
	{
		printf("YES\n");
		TwoSat.Solve();
		for(i=1;i<=n;i++) printf("%i ",TwoSat.sol[i]);
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}