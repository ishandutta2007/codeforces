#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
vector<int> G[N];
int col[N];
bool cycle;
void Cycle(int u)
{
	col[u]=1;
	for(int v:G[u])
	{
		if(!col[v]) Cycle(v);
		else if(col[v]==1) cycle=1;
	}
	col[u]=2;
}
void AddEdge(int u, int v){ G[u].pb(v);}
int n,m;
int u[N],v[N],w[N];
bool Check(int mid)
{
	for(int i=1;i<=n;i++) G[i].clear(),col[i]=0;
	for(int i=1;i<=m;i++) if(w[i]>mid) AddEdge(u[i],v[i]);
	cycle=0;
	for(int i=1;i<=n;i++) if(!col[i]) Cycle(i);
	return !cycle;
}
int main()
{
	scanf("%i %i",&n,&m);
	for(int i=1;i<=m;i++) scanf("%i %i %i",&u[i],&v[i],&w[i]);
	int top=1e9+7,bot=0,mid,ans=0;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid)) ans=mid,top=mid-1;
		else bot=mid+1;
	}
	queue<int> q;
	vector<int> in(n+1,0);
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=m;i++) if(w[i]>ans) in[v[i]]++,AddEdge(u[i],v[i]);
	for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
	vector<int> disc(n+1,0);
	int cnt=0;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		disc[x]=++cnt;
		for(int y:G[x])
		{
			in[y]--;
			if(!in[y]) q.push(y);
		}
	}
	vector<int> rot;
	for(int i=1;i<=m;i++) if(w[i]<=ans)
	{
		if(disc[u[i]]>disc[v[i]]) rot.pb(i);
	}
	printf("%i %i\n",ans,rot.size());
	for(int i:rot) printf("%i ",i);
	return 0;
}