#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXV = 1e5 + 5, MAXLOG = 17;

// LCA (N log N for preprocessing, N log N memory, log N time for query)

// Use: fill graph (n, g)
// Call init()
// Call dfs(root, root)
// Call lca(a, b) for lca query
// Call get_prv(s, d) to get predecessor of s at distance d from s

struct graph_lca {
	// Count of vertices
	int n;
	
	// Graph
	vector<pii> g[MAXV];
	
	// Distances
	int dis[MAXV];
	
	// Prv (1, 2, 4, ...)
	int prv[MAXV][MAXLOG];
	
	int prv_e[MAXV];
	
	// For dfs
	int tin[MAXV], tout[MAXV], timer;
	
	int add[MAXV];
	
	// Init all data before DFS
	void init(){
		REPN(i, 1, n){
			tin[i] = tout[i] = dis[i] = 0;
			REP(j, 0, MAXLOG){
				prv[i][j] = -1;
			}
		}
		timer = 0;
	}

	// Dfs for finding LCA
	void dfs(int s, int p, int p_e){
		int i, to;
		tin[s] = ++timer;
		prv[s][0] = p;
		prv_e[s] = p_e;
		REP(i, 1, MAXLOG){
			prv[s][i] = prv[prv[s][i - 1]][i - 1];
		}
		REP(i, 0, SZ(g[s])){
			to = g[s][i]._1;
			if (to != p){
				dis[to] = dis[s] + 1;
				dfs(to, s, g[s][i]._2);
			}
		}	
		tout[s] = ++timer;
	}
	
	void dfs2(int s) {
		REP(i, 0, SZ(g[s])){
			int to = g[s][i]._1;
			if (to != prv[s][0]){
				dfs2(to);
				add[prv_e[s]] += add[prv_e[to]];
			}
		}
	}

	// Checks if a is predecessor for b
	bool is_prv(int a, int b) {
		return tin[a] <= tin[b] && tout[a] >= tout[b];
	}

	// Get LCA
	int lca (int a, int b) {
		// Check if A or B is LCA
		if (is_prv(a, b)){
			return a;
		}
		if (is_prv(b, a)){
			return b;
		}	
		// Get LCA
		for (int i = MAXLOG - 1; i >= 0; i--){
			if (!is_prv(prv[a][i], b)){
				a = prv[a][i];
			}
		}
		return prv[a][0];
	}

	// Get predecessor of vertex s at distance d (distance d is mearured from s, not from the root)
	int get_prv(int s, int d){
		for(int i = MAXLOG - 1, st2 = 1 << (MAXLOG - 1); i >= 0 && d; i--, st2 >>= 1){
			if (st2 <= d){
				d -= st2;
				s = prv[s][i];
			}
		}
		return s;
	}
} gg;

void solve(){
	scanf("%d", &gg.n);
	REP(i, 1, gg.n) {
		int a, b;
		scanf("%d%d", &a, &b);
		gg.g[a].pb({b, i});
		gg.g[b].pb({a, i});
	}
	gg.init();
	gg.dfs(1, 1, 0);
	int q;
	scanf("%d", &q);
	REP(i, 0, q) {
		int a, b;
		scanf("%d%d", &a, &b);
		int p = gg.lca(a, b);
		gg.add[gg.prv_e[a]]++;
		gg.add[gg.prv_e[b]]++;
		gg.add[gg.prv_e[p]] -= 2;
	}
	gg.dfs2(1);
	/*REPN(i, 1, gg.n) {
		gg.ans[prv_e[i]] = gg.add[prv_e[i]];
	}*/
	REP(i, 1, gg.n) {
		printf("%d ", gg.add[i]);
	}
	putchar('\n');
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}