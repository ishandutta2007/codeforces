// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;




const int N=64;
int n;
int D[N][N];
vector<int> adj[N];
int ct[N];
int s,m;
vector<int> loc_leafs;
set<int> leafs;

int dfs1(int u,int p=-1) {
	int Z=ct[u];
	for(int v:adj[u]) if(v!=p) Z+=dfs1(v,u);
	if(adj[u].size()==1u && adj[u][0]==p) loc_leafs.pb(u);
	if(adj[u].size()<=1u) leafs.insert(u);
	return Z;
}



int g(int u,int q) {
	static bool seen[N][N];
	static int dp[N][N];
	bool &sn=seen[u][q];
	int &ans=dp[u][q];
	if(sn) return ans;
	sn=1;
	if(!q) return ans=0;

	int L=0,R=inf;
	for(;L!=R;) {
		int M=(L+R+1)/2;
		int spend=0;
		for(int v:leafs) {
			// if(g(v,q)+D[u][v] < M) goto nf;
			int ii=1;
			for(;q-ii >= 0 && g(v,q-ii)+D[u][v]>=M;) ++ii;
			--ii;
			spend += ii;
		}
		if(spend >= q) {
			L=M;
			continue;
		}
		// nf:;
		R=M-1;
	}
	// cerr<<"g("<<u<<","<<q<<") = "<<L<<endl;
	return ans=L;
}


int32_t main() {
	scanf("%d",&n);
	if(n==1) return printf("0\n"),0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) D[i][j]=inf*int(i!=j);
	for(int i=1;i<=n-1;i++) {
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		adj[u].pb(v);
		adj[v].pb(u);
		D[u][v]=D[v][u]=w;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		D[i][j]=min(D[i][j],D[i][k]+D[k][j]);

	scanf("%d%d",&s,&m);
	for(int i=1;i<=m;i++) {
		int x; scanf("%d",&x);
		++ct[x];
	}
	assert(dfs1(s)==m);
	int Z=inf;
	for(int u:adj[s]) {
		int L=0,R=inf;
		loc_leafs.clear();
		int sm=dfs1(u,s);
		for(;L!=R;) {
			int M=(L+R+1)/2;
			int spend=0;
			for(int v:loc_leafs) {
				if(g(v,m)+D[s][v] < M) goto no_force;
				int ii=0;
				for(;m-ii >= 0 && g(v,m-ii)+D[s][v]>=M;) ++ii;
				--ii;
				spend+=ii;
			}
			if(spend >= sm) {
				L=M;
				continue;
			}
			no_force:;
			R=M-1;
		}
		Z=min(Z,L);
	}
	printf("%d\n",Z);
}