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
const ll MOD = 1000000000000000003;
const ll MOD2 = 998244353;
// const ll P = 997;

const int MAXN = 1555;

ll stp[MAXN];

ll bin_mul(ll a, ll b) {
	ll ans = 0;
	for(; b; b >>= 1) {
		if (b & 1) {
			ans = (ans + a) % MOD;
		}
		a = (a << 1) % MOD;
	}
	return ans;
}

void init_p() {
	ll P = rng() % 20000 + 10000;
	stp[0] = 1;
	REP(i, 1, MAXN) {
		stp[i] = bin_mul(stp[i - 1], P);
	}
}

int x[MAXN], y[MAXN];
int d[MAXN][MAXN];
int sorted_d[MAXN][MAXN];
set<pii> st;

int per[MAXN];
int base_ind;

bool cmp(int a, int b) {
	return d[base_ind][a] < d[base_ind][b];
}

ll hsh[MAXN][MAXN];
char used[MAXN][MAXN];

map<ll, int> compressed;
int last_ind_v[MAXN];
int g_nxt[2 * MAXN];

vector<pair<ll, int> > vv_pp;

vector<ll> dp[2 * MAXN];
vector<ll> dp_tmp;

void solve(int n){
	REP(i, 0, n) {
		REP(j, 0, n) {
			scanf("%d", &d[i][j]);
		}
	}
	// Calc hashes
	REP(i, 0, n) {
		REP(j, 0, n) {
			used[i][j] = 0;
		}
	}
	REP(i, 0, n) {
		REP(j, 0, n) {
			per[j] = j;
		}
		base_ind = i;
		sort(per, per + n, cmp);
		REP(j, 0, n) {
			int cur = per[j], nxt = per[j + 1];
			if (j == n - 1 || d[i][cur] < d[i][nxt]) {
				used[i][j] = 1;
			}
			hsh[i][j] = stp[cur];
			if (j) {
				hsh[i][j] = (hsh[i][j] + hsh[i][j - 1]) % MOD;
			}
			sorted_d[i][j] = d[i][cur];
		}
	}
	// Find clusters
	compressed.clear();
	REP(i, 0, n) {
		last_ind_v[i] = 0;
	}
	REP(i, 0, 2 * n) {
		g_nxt[i] = 0;
	}
	REP(j, 0, n) {
		vv_pp.clear();
		REP(i, 0, n) {
			if (used[i][j]) {
				vv_pp.pb(mp(hsh[i][j], i));
			}
		}
		SORT(vv_pp);
		/*printf("%d: ", j);
		REP(i, 0, SZ(vv_pp)) {
			printf("%lld ", vv_pp[i]._1);
		}
		putchar('\n');*/
		REP(i, j, SZ(vv_pp)) {
			if (vv_pp[i]._1 == vv_pp[i - j]._1) {
				if (j < n - 1) {
					// Verify cluster
					ll mx = 0, mn = INF;
					REPN(k, i - j, i) {
						int ind_v = vv_pp[k]._2;
						mx = max(mx, (ll)sorted_d[ind_v][j]);
						mn = min(mn, (ll)sorted_d[ind_v][j + 1]);
					}
					if (mx >= mn) {
						continue;
					}
				}
				ll cur_hsh = vv_pp[i]._1;
				int ind = SZ(compressed);
				compressed[cur_hsh] = ind;
				if (j) {
					if (i < SZ(vv_pp) - 1) {
						assert(vv_pp[i] != vv_pp[i + 1]);
					}
					REPN(k, i - j, i) {
						int ind_v = vv_pp[k]._2;
						int ind_prev = compressed[hsh[ind_v][last_ind_v[ind_v]]];
						g_nxt[ind_prev] = ind;
						last_ind_v[ind_v] = j;
					}
				}
			}
		}
	}
	// Calc dp
	int m = SZ(compressed);
	/*REP(i, 0, m) {
		printf("%d: %d\n", i, g_nxt[i]);
	}
	return;*/
	REP(i, 0, m) {
		dp[i].clear();
	}
	REP(i, 0, m) {
		if (dp[i].empty()) {
			dp[i].resize(2);
		}
		dp[i][1] = 1;
		if (i == m - 1) {
			break;
		}
		int to = g_nxt[i];
		assert(to != 0);
		if (SZ(dp[to]) == 0) {
			swap(dp[i], dp[to]);
		} else {
			dp_tmp.resize(SZ(dp[i]) + SZ(dp[to]) - 1);
			REP(j, 0, SZ(dp_tmp)) {
				dp_tmp[j] = 0;
			}
			REP(j, 1, SZ(dp[i])) {
				if (dp[i][j]) {
					REP(k, 1, SZ(dp[to])) {
						dp_tmp[j + k] = (dp_tmp[j + k] + dp[i][j] * dp[to][k]) % MOD2;
					}
				}
			}
			swap(dp[to], dp_tmp);
		}
	}
	// Print result
	REPN(i, 1, n) {
		printf("%lld ", dp[m - 1][i]);
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	init_p();
    int n;
	scanf("%d", &n);
    solve(n);
}