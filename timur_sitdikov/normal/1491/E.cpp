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
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

const int MAXN = 3e5 + 5;
const int MAXF = 27;

int f[MAXF];
int is_f[MAXN];

vector<pii> g[MAXN];
int sz[MAXN][MAXF], used[MAXN][MAXF];

bool decomp(int s, int ind);

pii break_apart(int s, int ind) {
	used[s][ind] = 1;
	sz[s][ind] = 1;
	REP(i, 0, SZ(g[s])) {
		if (g[s][i]._2) {
			int to = g[s][i]._1;
			if (!used[to][ind]) {
				pii pp = break_apart(to, ind);
				if (pp._1 != -1) {
					return pp;
				}
				if (sz[to][ind] == f[ind - 1] || sz[to][ind] == f[ind - 2]) {
					g[s][i]._2 = 0;
					REP(j, 0, SZ(g[to])) {
						if (g[to][j]._1 == s) {
							g[to][j]._2 = 0;
						}
					}
					if (sz[to][ind] == f[ind - 1]) {
						return {to, s};
					} else {
						return {s, to};
					}
				}
				sz[s][ind] += sz[to][ind];
			}
		}
	}
	return {-1, -1};
}

bool decomp(int s, int ind) {
	if (ind <= 1) {
		return true;
	}
	pii pp = break_apart(s, ind);
	if (pp._1 == -1) {
		return false;
	}
	// printf("%d %d\n", pp._1, pp._2);
	return decomp(pp._1, ind - 1) & decomp(pp._2, ind - 2);
}

void solve(){
	f[0] = f[1] = 1;
	is_f[1] = 1;
	REP(i, 2, MAXF) {
		f[i] = f[i - 1] + f[i - 2];
		is_f[f[i]] = i;
	}
	int n;
	scanf("%d", &n);
	REP(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb({b, 1});
		g[b].pb({a, 1});
	}
	if (!is_f[n]) {
		printf("NO\n");
		return;
	}
	int ans = decomp(1, is_f[n]);
	if (ans) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
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