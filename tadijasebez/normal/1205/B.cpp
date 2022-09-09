#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int L=63;
vector<int> my[L];
const int N=100050;
vector<int> E[N];
void AddEdge(int u, int v){ E[u].pb(v);E[v].pb(u);}
int ans=-1;
const int M=L*3;
int dist[N];
bool ban[N];
vector<int> use;
void BFS(int u)
{
	for(int x:use) dist[x]=-1;
	queue<int> q;
	q.push(u);
	dist[u]=0;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(int y:E[x])
		{
			if(dist[y]==-1 && !ban[y])
			{
				dist[y]=dist[x]+1;
				q.push(y);
			}
		}
	}
}
void Solve(int u)
{
	ban[u]=1;
	for(int v:E[u])
	{
		BFS(v);
		for(int d:E[u]) if(d!=v && dist[d]!=-1)
		{
			if(ans==-1 || ans>dist[d]+2) ans=dist[d]+2;
		}
	}
	ban[u]=0;
}
int main()
{
	vector<ll> a;
	int n;
	scanf("%i",&n);
	a.resize(n);
	for(ll &i:a) scanf("%lld",&i);
	for(int j=0;j<n;j++)
	{
		ll x=a[j];
		for(int i=0;i<L;i++) if(x>>i&1) my[i].pb(j);
	}
	for(int i=0;i<L;i++) if(my[i].size()>2) return 0*printf("3\n");
	for(int i=0;i<L;i++) if(my[i].size()==2) AddEdge(my[i][0],my[i][1]);
	for(int i=0;i<n;i++) if(a[i]!=0) use.pb(i);
    for(int i:use) Solve(i);
    printf("%i\n",ans);
	return 0;
}