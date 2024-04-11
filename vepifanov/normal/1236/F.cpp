#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const int mod = 1000*1000*1000+7;
const int rev2 = (mod + 1) / 2;
const int N = 500100;

int n;
int m;
int r = 0;
int col[N];
int was[N];
int par[N];
int bad[N];
int ord[N];
int p2[N + 1];
vi v[N];
int cnt[N];
int prob[N];
vi w[N];
vi u[N];
int pre[N];
int sum[N];
int ea[N];
int eb[N];
vi h[N];

int go (int x, int p) {
	was[x] = 1;
	par[x] = p;
	for (auto y : v[x]) {
		if (y == p) continue;
		if (was[y] == 1) {
			int z = x, k = 0;
			while (z != y) {
				h[z].pb (r);
				u[r].pb (z);
				col[z] = r;
				bad[z] = 1;
				ord[z] = k;
				k++;
				int oz = par[z];
				par[z] = y;
				z = oz;
			}
			h[z].pb (r);
			u[r].pb (z);
			w[y].pb (r);
			cnt[r] = k + 1;
			r++;
		} else
		if (was[y] == 0) go (y, x);
	}
	was[x] = 2;
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
		ea[i] = a;
		eb[i] = b;
	}
	p2[0] = 1;
	for (int i = 1; i <= N; i++) p2[i] = ((ll)p2[i - 1] * rev2) % mod;
	go (0, 0);
	int nodes = ((ll)n * rev2) % mod;
	int edges = ((ll)m * p2[2]) % mod;
	int rings = 0;
	for (int i = 0; i < r; i++) rings = (rings + p2[cnt[i]]) % mod;
	int est = (nodes - edges + rings) % mod;
	if (est < 0) est += mod;
	int nodes2 = ((ll)n * (n - 1) % mod * p2[2] + (ll)n * rev2) % mod;
	ll e2 = m;
	ll e1 = 0;
	for (int i = 0; i < n; i++) e1 += (ll)sz (v[i]) * (sz (v[i]) - 1);
	ll e0 = (ll)m * m - e2 - e1;
	e1 %= mod;
	e0 %= mod;
	int edges2 = ((ll)e2 * p2[2] + (ll)e1 * p2[3] + (ll)e0 * p2[4]) % mod;
	int rings2 = ((ll)rings * rings) % mod;
	for (int i = 0; i < r; i++) rings2 = (rings2 - (ll)p2[cnt[i]] * p2[cnt[i]] % mod + p2[cnt[i]] + mod) % mod;
	for (int i = 0; i < n; i++)
		if (sz (h[i]) >= 2) {
			int cur = 0;
			for (int j = 0; j < sz (h[i]); j++) {
				rings2 = (rings2 + (ll)p2[cnt[h[i][j]] - 1] * cur % mod + mod) % mod;
				cur = (cur + p2[cnt[h[i][j]]]) % mod;
			}
		}
	int nodes_edges = (((ll)2 * p2[2] + (ll)(n - 2) * p2[3]) % mod * m) % mod;
	int nodes_rings = 0;
	for (int i = 0; i < r; i++) nodes_rings = (nodes_rings + (ll)cnt[i] * p2[cnt[i]] + (ll)(n - cnt[i]) * p2[cnt[i] + 1]) % mod;
	int edges_rings = 0;
	for (int i = 0; i < r; i++) {
		int re2 = cnt[i];
		int re1 = 0;
		int re0 = 0;
		for (int j = 0; j < cnt[i]; j++) re1 += sz (v[u[i][j]]);
		re1 -= 2 * re2;
		re0 = m - re2 - re1;
		edges_rings = (edges_rings + (ll)re2 * p2[cnt[i]] + (ll)re1 * p2[cnt[i] + 1] + (ll)re0 * p2[cnt[i] + 2]) % mod;
	}
	int est2 = ((ll)nodes2 + edges2 + rings2 - (ll)2 * (nodes_edges + edges_rings - nodes_rings) % mod) % mod;
	if (est2 < 0) est2 += mod;
//	printf ("%d %d\n", est, est2);
	int ans = (est2 - (ll)est * est % mod + mod) % mod;
	printf ("%d\n", ans);	
	re 0;
}