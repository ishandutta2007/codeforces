#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=300050;
vector<pair<int,int> > E[N];
int d[N],t[N];
bool was[N];
vector<int> ans;
void DFS(int u)
{
	was[u]=1;
	for(auto p:E[u])
	{
		if(!was[p.first])
		{
			DFS(p.first);
			if(d[p.first]!=t[p.first])
			{
				ans.pb(p.second);
				t[u]^=1;
				t[p.first]^=1;
			}
		}
	}
}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	int r=1;
	for(i=1;i<=n;i++) scanf("%i",&d[i]),r=d[i]==-1?i:r;
	for(i=1;i<=m;i++) scanf("%i %i",&u,&v),E[u].pb(mp(v,i)),E[v].pb(mp(u,i));
	DFS(r);
	bool ok=1;
	for(i=1;i<=n;i++) if(!(t[i]==d[i] || d[i]==-1)) ok=0;
	if(!ok) printf("-1\n");
	else
	{
		sort(ans.begin(),ans.end());
		printf("%i\n",ans.size());
		for(i:ans) printf("%i\n",i);
	}
	return 0;
}