/*input
5 4
1 2
2 3
2 4
4 5
2 1
2 5
1 2
2 5
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

#define MX 100005

int n,q;
set<int> adj[MX];
int par[MX],anc[MX][21],ans[MX],sz[MX],dep[MX],cntlvl[MX];

void dfs(int s,int p,int lvl = 0){
	anc[s][0] = p;
	dep[s] = lvl;
	for(auto x:adj[s]){
		if(x != p){
			dfs(x,s,lvl+1);
		}
	}
}

int lca(int u,int v){
	// cout << u << " --- " << v << endl;
	if(dep[u] > dep[v]) swap(u,v);
	// cout << u << " " << v << endl;
	for(int i = 20; i >= 0; i --){
		if(dep[v]-dep[u] >= (1<<i)){
			// cout << i << " " << u << " " << v << endl;
			v = anc[v][i];
		}
	}
	// cout << u << " " << v << endl;
	if(u == v) return u;
	for(int i = 20; i >= 0; i --){
		if(anc[u][i] != anc[v][i]){
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	return anc[u][0];
}

int dist(int u,int v){
	int res = dep[u]+dep[v]-2*dep[lca(u,v)];
	// cout << u << " " << v << " " << res << endl;
	return res;
}

int cur = 0;

void dfssz(int s,int p){
	cur ++;
	sz[s] = 1;
	for(auto x:adj[s]){
		if(x != p){
			dfssz(x,s);
			sz[s] += sz[x];
		}
	}
}

int fc(int s,int p){
	for(auto x:adj[s]){
		if(x != p and sz[x] > cur/2) return fc(x,s);
	}
	return s;
}

void decompose(int s,int p,int c = 0){
	// cout << " -- " << s << endl;
	cur = 0;
	dfssz(s,p);
	int centroid = fc(s,p);
	// cout << s << " - " << centroid << endl;
	if(p == -1) p = centroid;
	par[centroid] = p;
	cntlvl[centroid] = c;
	for(auto x:adj[centroid]){
		adj[x].erase(centroid);
		decompose(x,centroid,c+1);
	}
	adj[centroid].clear();
}

void upd(int u){
	int v = u;
	while(true){
		ans[v] = min(ans[v],dist(u,v));
		if(par[v] == v) break;
		v = par[v];
	}
}

int quer(int u){
	int res = INF;
	int v = u;
	// cout << u << " - - - - -\n";
	while(true){
		remin(res,dist(u,v)+ans[v]);
		// cout << v << " " << ans[v] << " " << dist(u,v) << endl;
		if(par[v] == v) break;
		v = par[v];
	}
	return res;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	REP(i,n-1){
		int u,v; cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dep[1] = 0;
	dfs(1,1);
	FOR(j,1,21){
		FOR(i,1,n+1){
			anc[i][j] = anc[anc[i][j-1]][j-1];
		}
	}
	decompose(1,-1);
	FOR(i,1,n+1){
		cout << (char)('A'+cntlvl[i]) << endl;
	}
}