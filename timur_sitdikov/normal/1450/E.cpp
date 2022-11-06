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

#define x0 gray_cat_x0
#define y0 gray_cat_y0
#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e8 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e3 + 5;

int d[MAXN][MAXN];

struct edge{
	int s, to, t;
} ee[MAXN];

vi g[MAXN];

int col[MAXN];

bool bipartite;

void dfs(int s, int cl) {
	col[s] = cl;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (!col[to]) {
			dfs(to, 3 - cl);
		}
		if (col[to] == col[s]) {
			bipartite = false;
		}
	}
}

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, m) {
		scanf("%d%d%d", &ee[i].s, &ee[i].to, &ee[i].t);
		g[ee[i].s].pb(ee[i].to);
		g[ee[i].to].pb(ee[i].s);
	}
	bipartite = true;
	dfs(1, 1);
	if (!bipartite) {
		printf("NO\n");
		return;
	}
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	REP(i, 0, m) {
		int vl = 1, vr = 1;
		if (ee[i].t == 1) {
			vl = -1;
		}
		int a = ee[i].s, b = ee[i].to;
		d[b][a] = vl, d[a][b] = vr;
	}
	REPN(k, 1, n) {
		REPN(i, 1, n) {
			REPN(j, 1, n) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	REPN(i, 1, n) {
		if (d[i][i] < 0) {
			printf("NO\n");
			return;
		}
	}
	int a = 1, b = 1;
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			if (d[i][j] > d[a][b]) {
				a = i, b = j;
			}
		}
	}
	printf("YES\n%d\n", d[a][b]);
	REPN(i, 1, n) {
		printf("%d ", d[a][i]);
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