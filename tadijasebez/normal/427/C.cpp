#include <stdio.h>
#include <vector>
#include <stack>
#include <map>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=100050;
vector<int> E[N];
stack<int> s;
bool in[N];
int disc[N],low[N],time,comp[N],clock,cost[N];
map<int,int> cnt[N];
map<int,int>::iterator it;
int min(int a, int b){ return a>b?b:a;}
void DFS(int u)
{
	disc[u]=low[u]=++time;
	s.push(u);
	in[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!disc[v])
		{
			DFS(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v]) low[u]=min(low[u],disc[v]);
	}
	if(disc[u]==low[u])
	{
		clock++;
		while(s.top()!=u)
		{
			comp[s.top()]=clock;
			cnt[clock][cost[s.top()]]++;
			in[s.top()]=0;
			s.pop();
		}
		s.pop();
		comp[u]=clock;
		cnt[clock][cost[u]]++;
		in[u]=0;
	}
}
ll sol=1,ans;
int main()
{
	int n,m,u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&cost[i]);
	scanf("%i",&m);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
	}
	for(i=1;i<=n;i++) if(!disc[i]) DFS(i);
	for(i=1;i<=clock;i++)
	{
		it=cnt[i].begin();
		ans+=it->first;
		sol=sol*(it->second)%mod;
	}
	printf("%lld %lld\n",ans,sol);
	return 0;
}