#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ld TAU=2*acos(-1);
const ld eps=1e-7;
const int inf=1e9+99;
const ll linf=1e18+88;


const int N=100<<10;

int rk[N+N],da[N+N];
int rt(int u) {
	if(da[u]==u) return u;
	return da[u]=rt(da[u]);
}
void un(int u,int v) {
	u=rt(u),v=rt(v);
	if(u==v) return;
	if(rk[u]>rk[v]) swap(u,v);
	if(rk[u]==rk[v]) ++rk[v];
	da[u]=v;
}

vector<int> adj[N+N];
int r[N+N];


int32_t main() {
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",r+i);
	for(int i=1;i<=m;i++) {
		da[i]=i;
		da[i+N]=i+N;
		int xi; scanf("%d",&xi);
		for(int j=0;j<xi;j++) {
			int rm; scanf("%d",&rm);
			adj[rm].push_back(i);
		}
	}

	for(int i=1;i<=n;i++) {
		assert(adj[i].size()==2u);
		if(r[i]) {
			un(adj[i][0],adj[i][1]);
			un(N+adj[i][0],N+adj[i][1]);
		} else {
			un(N+adj[i][0],adj[i][1]);
			un(adj[i][0],N+adj[i][1]);
		}
	}

	for(int i=1;i<=m;i++) if(rt(i)==rt(i+N)) goto die;
	printf("YES\n");
	return 0;
	die:;
	printf("NO\n");
}