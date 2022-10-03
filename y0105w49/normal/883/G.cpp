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





const int N=300<<10;
int t[N],u[N],v[N];
int f=0;
bool orig[N];
char Z[N];
vector<int> adj[N];
vector<pair<int,int> > uadj[N];

bool seen[N];
void clear() {
	for(int i=0;i<N;i++) seen[i]=0;
}
int dfs1(int u) {
	if(seen[u]) return 0;
	seen[u]=1;
	int W=1;
	for(int v:adj[u]) W+=dfs1(v);
	for(const auto &P:uadj[u]) {
		int f=P.fi;
		if(f<0) Z[~f]='+';
		else Z[f]='-';
	}
	return W;
}
int dfs2(int u) {
	if(seen[u]) return 0;
	seen[u]=1;
	int W=1;
	for(int v:adj[u]) W+=dfs2(v);
	for(const auto &P:uadj[u]) {
		int rec=dfs2(P.se);
		int f=P.fi;
		if(!rec) continue;
		W+=rec;
		if(f<0) Z[~f]='-';
		else Z[f]='+';
	}
	return W;
}




int32_t main() {
	int n,m,s; scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",t+i,u+i,v+i);
		if(t[i]==1) adj[u[i]].pb(v[i]);
		if(t[i]==2) {
			uadj[u[i]].pb({f,v[i]});
			uadj[v[i]].pb({~f,u[i]});
			++f;
		}
	}

	for(int i=0;i<f;i++) Z[i]='+';
	dfs1(s); clear();
	int z1=dfs2(s); clear();
	printf("%d\n%s\n",z1,Z);
	int z2=dfs1(s);
	printf("%d\n%s\n",z2,Z);

}