#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
#define ll long long
const int N=1000500;
stack<int> s;
vector<int> E[N];
vector< pair<int,int> > G[N];
int vis[N],low[N],time,cnt,Component[N];
bool in[N];
int min(int a, int b){ return a>b?b:a;}
void DFS(int u)
{
	vis[u]=low[u]=++time;
	s.push(u);in[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS(v),low[u]=min(low[u],low[v]);
		else if(in[v]) low[u]=min(low[u],vis[v]);
	}
	if(vis[u]==low[u])
	{
		cnt++;
		while(s.top()!=u)
		{
			int x=s.top();
			s.pop();
			Component[x]=cnt;
			in[x]=0;
		}
		s.pop();
		in[u]=0;
		Component[u]=cnt;
	}
}
ll dp[30005];
ll Calc(int x)
{
	int top=30000,bot=1,mid,ans=1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(mid*(mid-1)/2<x) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	ll ret=(ll)x*ans-dp[ans];
	return ret;
}
ll Dist[N],Disc[N],ans[N];
ll max(ll a, ll b){ return a>b?a:b;}
void Solve(int u)
{
	if(Disc[u]) return;
	Disc[u]=1;
	ans[u]=Dist[u];
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].first;
		int w=G[u][i].second;
		Solve(v);
		ans[u]=max(ans[u],ans[v]+Dist[u]+w);
	}
}
int u[N],v[N],w[N];
int main()
{
	int n,m,i,s;
	for(i=1;i<=30000;i++) dp[i]=dp[i-1]+(ll)i*(i-1)/2;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i %i",&u[i],&v[i],&w[i]),E[u[i]].push_back(v[i]);
	scanf("%i",&s);
	DFS(s);
	for(i=1;i<=m;i++)
	{
		int c1=Component[u[i]];
		int c2=Component[v[i]];
		if(!c1 || !c2) continue; 
		if(c1==c2) Dist[c1]+=Calc(w[i]);
		else G[c1].push_back(make_pair(c2,w[i]));
	}
	Solve(Component[s]);
	printf("%lld\n",ans[Component[s]]);
	return 0;
}