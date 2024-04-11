#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=105;
const ll INF=1e17;
int n,m,q,u,v,x,fix[N],ans;
vector<int>g[N][N];
int C;
void dfs (int k){
	fix[k]=1;
	for (int i=0;i<g[k][C].size();i++)
	if (fix[g[k][C][i]]==0)
	dfs(g[k][C][i]);
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>u>>v>>x;
		g[u][x].pb(v);
		g[v][x].pb(u);
	}
	cin>>q;
	while (q--){
		cin>>u>>v;
		ans=0;
		for (int i=1;i<=m;i++){
			C=i;
			for (int j=1;j<=n;j++)fix[j]=0;
			dfs(u);
			if (fix[v])ans++;
		}
		cout<<ans<<endl;
	}
    return 0;
}