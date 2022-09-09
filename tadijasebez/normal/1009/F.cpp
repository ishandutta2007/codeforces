#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
#define pb push_back
const int N=1000050;
int dep[N],sol[N],val[N];
map<int,int> cnt[N];
map<int,int>::iterator it;
vector<int> E[N];
void DFS(int u, int p)
{
	dep[u]=dep[p]+1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p)
		{
			DFS(v,u);
			if(cnt[v].size()>cnt[u].size()) cnt[u].swap(cnt[v]),sol[u]=sol[v],val[u]=val[v];
			for(it=cnt[v].begin();it!=cnt[v].end();it++)
			{
				cnt[u][it->first]+=it->second;
				if(val[u]<cnt[u][it->first] || (val[u]==cnt[u][it->first] && it->first<sol[u]))
				{
					sol[u]=it->first;
					val[u]=cnt[u][it->first];
				}
			}
		}
	}
	cnt[u][dep[u]]++;
	if(val[u]<cnt[u][dep[u]] || (val[u]==cnt[u][dep[u]] && dep[u]<sol[u]))
	{
		sol[u]=dep[u];
		val[u]=cnt[u][dep[u]];
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i\n",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	for(i=1;i<=n;i++) printf("%i\n",sol[i]-dep[i]);
	return 0;
}