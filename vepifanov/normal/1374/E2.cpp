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

const int N = 1 << 14;

int n;
int t;
int m;
vii v[4];
vector<ll> w[4];
ii tree[2 * N + 1];

void build (int x, int l, int r) {
	tree[x] = mp (0, 0);
	if (l == r) re;
	int s = (l + r) / 2;
	build (x * 2 + 1, l, s);
	build (x * 2 + 2, s + 1, r);
}

ii merge (const ii& a, const ii& b) {
	re mp (a.fi + b.fi, a.se + b.se);
}

ii add (int x, int l, int r, int y, int z) {
	if (r < y || l > y) re tree[x];
	if (l == r) {
		tree[x].fi += z;
		tree[x].se += y * z;
		re tree[x];
	}
	int s = (l + r) / 2;
	re tree[x] = merge (add (x * 2 + 1, l, s, y, z), add (x * 2 + 2, s + 1, r, y, z));
}

int get (int x, int l, int r, int y) {
	if (y <= 0) re 0;
	if (tree[x].fi <= y) re tree[x].se;
	if (l == r) re min (tree[x].fi, y) * l;
	int s = (l + r) / 2;
	re get (x * 2 + 1, l, s, y) + get (x * 2 + 2, s + 1, r, y - tree[x * 2 + 1].fi);
}

int main () {
	scanf ("%d%d%d", &n, &t, &m);
	for (int i = 0; i < n; i++) {
		int t, a, b;
		scanf ("%d%d%d", &t, &a, &b);
		v[a | (2 * b)].pb (mp (t, i));
	}
	for (int i = 0; i < 4; i++) {
		sort (all (v[i]));
		w[i].resize (sz (v[i]) + 1);
		w[i][0] = 0;
		for (int j = 0; j < sz (v[i]); j++) w[i][j + 1] = w[i][j] + v[i][j].fi;
	}
	build (0, 0, N);
	for (int i = 0; i < sz (v[0]); i++) add (0, 0, N, v[0][i].fi, 1);
	for (int i = 0; i < sz (v[3]); i++) add (0, 0, N, v[3][i].fi, 1);
	for (int i = m; i < sz (v[1]); i++) add (0, 0, N, v[1][i].fi, 1);
	for (int i = m; i < sz (v[2]); i++) add (0, 0, N, v[2][i].fi, 1);
	ll ans = 1e18;
	int ai = -1;
	for (int i = 0; i <= m && i <= sz (v[3]); i++) {
		if (m - i <= sz (v[1]) && m - i <= sz (v[2])) {
			if (i + 2 * (m - i) <= t) {
				ll cur = w[3][i] + w[1][m - i] + w[2][m - i] + get (0, 0, N, t - i - 2 * (m - i));
				if (cur < ans) {
					ans = cur;
					ai = i;
				}
			}
		}
		if (i < sz (v[3])) add (0, 0, N, v[3][i].fi, -1);
		if (m - i - 1 >= 0 && m - i - 1 < sz (v[1])) add (0, 0, N, v[1][m - i - 1].fi, 1);
		if (m - i - 1 >= 0 && m - i - 1 < sz (v[2])) add (0, 0, N, v[2][m - i - 1].fi, 1);
	}
	if (ans > 5e17) ans = -1;
	printf ("%lld\n", ans);
	if (ans != -1) {
		for (int i = 0; i < ai; i++) printf ("%d ", v[3][i].se + 1);
		for (int i = 0; i < m - ai; i++) printf ("%d ", v[1][i].se + 1);
		for (int i = 0; i < m - ai; i++) printf ("%d ", v[2][i].se + 1);
		vii u;
		for (int i = ai; i < sz (v[3]); i++) u.pb (v[3][i]);
		for (int i = m - ai; i < sz (v[2]); i++) u.pb (v[2][i]);
		for (int i = m - ai; i < sz (v[1]); i++) u.pb (v[1][i]);
		for (int i = 0; i < sz (v[0]); i++) u.pb (v[0][i]);
		sort (all (u));
		for (int i = 0; i < t - ai - 2 * (m - ai); i++) printf ("%d ", u[i].se + 1);
	}
	re 0;
}