#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=300050;
vector<int> E[N];
int dep[N],par[N];
int main()
{
	int n,q;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&n);
		for(int i=1,u,v;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);

		function<void(int,int)> DFS=[&](int u, int p)
		{
			dep[u]=dep[p]+1+max((int)E[u].size()-2,0);
			par[u]=p;
			for(int v:E[u]) if(v!=p) DFS(v,u);
		};
		auto Best=[&](){ int x=1;for(int i=1;i<=n;i++) if(dep[x]<dep[i]) x=i;return x;};

		int cen,den;
		DFS(1,0);
		cen=Best();
		DFS(cen,0);
		den=Best();
		int ans=dep[den];
		//for(int u=par[den];dep[u]>1;u=par[u]) ans+=(int)E[u].size()-2;
		//for(int u=den;u;u=par[u]) printf("%i ",u);printf("\n");
		printf("%i\n",ans);
		for(int i=1;i<=n;i++) E[i].clear();
	}
	return 0;
}