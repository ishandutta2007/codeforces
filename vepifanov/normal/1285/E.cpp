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

const int N = 1 << 19;

int n;
int m;
ii tree[2 * N + 10];
int same[2 * N + 10];
int cnt[2 * N + 10];
int l[N];
int r[N];
map<int, int> num;

void build (int x, int l, int r) {
	same[x] = 0;
	tree[x] = mp (1e9, 0);
	cnt[x] = 0;
	if (l == r) re;
	int s = (l + r) / 2;
	build (x * 2 + 1, l, s);
	build (x * 2 + 2, s + 1, r);
}

ii merge (const ii& a, const ii& b) {
	ii c;
	c.fi = min (a.fi, b.fi);
	c.se = int (c.fi == a.fi) * a.se + int (c.fi == b.fi) * b.se;
	re c;
}

ii add (int x, int l, int r, int y, int z) {
	if (r < y || l > y) re mp (tree[x].fi + same[x], tree[x].se);
	if (l == r) {
		cnt[x] += z;
		if (cnt[x] == 0) tree[x] = mp (1e9, 0); else tree[x] = mp (0, 1);
		re mp (tree[x].fi + same[x], tree[x].se);
	}
	int s = (l + r) / 2;
	tree[x] = merge (add (x * 2 + 1, l, s, y, z), add (x * 2 + 2, s + 1, r, y, z));
	re mp (tree[x].fi + same[x], tree[x].se);
}

ii addseg (int x, int l, int r, int lc, int rc, int z) {
	if (r < lc || l > rc) re mp (tree[x].fi + same[x], tree[x].se);
	if (l >= lc && r <= rc) {
		same[x] += z;
//		printf ("addseg %d %d %d %d %d %d = %d %d | %d\n", x, l, r, lc, rc, z, tree[x].fi + same[x], tree[x].se, same[x]);
		re mp (tree[x].fi + same[x], tree[x].se);
	}
	int s = (l + r) / 2;
	tree[x] = merge (addseg (x * 2 + 1, l, s, lc, rc, z), addseg (x * 2 + 2, s + 1, r, lc, rc, z));
//	printf ("addseg %d %d %d %d %d %d = %d %d\n", x, l, r, lc, rc, z, tree[x].fi + same[x], tree[x].se);
	re mp (tree[x].fi + same[x], tree[x].se);
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		vi v;
		for (int i = 0; i < n; i++) {
			scanf ("%d%d", &l[i], &r[i]);
			l[i] = 2 * l[i];
			r[i] = 2 * r[i];
			v.pb (l[i]);
			v.pb (r[i] + 1);
		}
		sort (all (v));
		v.resize (unique (all (v)) - v.begin ());
		m = sz (v);
		num.clear ();
//		printf ("%d\n", m);
		for (int i = 0; i < m; i++) num[v[i]] = i;
		for (int i = 0; i < n; i++) {
			l[i] = num[l[i]];
			r[i] = num[r[i] + 1];
		}
		build (0, 0, m - 1);
		for (int i = 0; i < n; i++) {
			add (0, 0, m - 1, r[i], 1);
			addseg (0, 0, m - 1, l[i], r[i] - 1, 1);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			add (0, 0, m - 1, r[i], -1);
			addseg (0, 0, m - 1, l[i], r[i] - 1, -1);
//			printf ("%d %d = ", l[i], r[i]);
//			printf ("%d %d\n", tree[0].fi, tree[0].se);
			ans = max (ans, tree[0].se);
			add (0, 0, m - 1, r[i], 1);
			addseg (0, 0, m - 1, l[i], r[i] - 1, 1);
		}
		printf ("%d\n", ans);
	}
	re 0;
}