#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
#define pb push_back
const int N=100050;
stack<int> s;
bool vis[N],was[N],in[N];
vector<int> E[N],R[N];
void DFS1(int u)
{
	vis[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS1(v);
	}
	s.push(u);
	in[u]=1;
}
int cnt,com[N];
vector<int> scc[N];
void DFS2(int u)
{
	was[u]=1;
	if(in[u]) in[u]=0,scc[cnt].pb(u),com[u]=cnt;
	for(int i=0;i<R[u].size();i++)
	{
		int v=R[u][i];
		if(!was[v]) DFS2(v);
	}
}
bool bad[N];
int a[N];
int main()
{
	int n,m,h,i,u,v,j;
	scanf("%i %i %i",&n,&m,&h);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		if((a[u]+1)%h==a[v]) E[u].pb(v),R[v].pb(u);
		if((a[v]+1)%h==a[u]) E[v].pb(u),R[u].pb(v);
	}
	for(i=1;i<=n;i++) if(!vis[i]) DFS1(i);
	while(s.size())
	{
		u=s.top();
		s.pop();
		if(in[u])
		{
			cnt++;
			DFS2(u);
		}
	}
	for(u=1;u<=n;u++)
	{
		for(j=0;j<E[u].size();j++)
		{
			v=E[u][j];
			if(com[u]!=com[v]) bad[com[u]]=1;
		}
	}
	int sol=1e9,ans;
	for(i=1;i<=cnt;i++)
	{
		if(bad[i]) continue;
		if(sol>scc[i].size()) sol=scc[i].size(),ans=i;
	}
	printf("%i\n",scc[ans].size());
	for(i=0;i<scc[ans].size();i++)
	{
		printf("%i ",scc[ans][i]);
	}
	return 0;
}