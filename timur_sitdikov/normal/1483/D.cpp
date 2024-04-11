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
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

const int MAXN = 605;

ll g[MAXN][MAXN];
ll gr[MAXN][MAXN];

ll d1[MAXN][MAXN], d2[MAXN][MAXN], d3[MAXN][MAXN];

void solve(){
	int n, m, q;
	scanf("%d%d", &n, &m);
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			g[i][j] = LL_INF;
			gr[i][j] = LL_INF;
		}
		g[i][i] = 0;
	}
	REP(i, 0, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = c;
	}
	scanf("%d", &q);
	REP(i, 0, q) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		gr[a][b] = gr[b][a] = -c;
	}
	
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			d1[i][j] = g[i][j];
			d2[i][j] = LL_INF;
			d3[i][j] = LL_INF;
		}
	}
	
	REPN(k, 1, n) {
		REPN(i, 1, n) {
			REPN(j, 1, n) {
				d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
			}
		}
	}
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			REPN(k, 1, n) {
				d2[i][j] = min(d2[i][j], d1[i][k] + gr[k][j]);
			}
		}
	}
	REPN(i, 1, n) {
		REPN(j, 1, n) {
			REPN(k, 1, n) {
				d3[i][j] = min(d3[i][j], d2[i][k] + d1[k][j]);
			}
		}
	}
	int ans = 0;
	REPN(i, 1, n) {
		REPN(j, i + 1, n) {
			if (g[i][j] == LL_INF) {
				continue;
			}
			//printf("%d %d: %lld, %lld\n", i, j, d3[i][j], g[i][j]);
			if (d3[i][j] <= -g[i][j]) {
				//printf("-> %d %d is good\n", i, j);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
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