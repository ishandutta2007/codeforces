#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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

const int inf = 1e9;
const int N = 1 << 21;
 
int n;
int m;
int tree[2 * N + 10];
int same[2 * N + 10];
pair<int, ii> v[300000];

int build (int x, int l, int r) {
	same[x] = inf;
	if (l == r) re tree[x] = inf;
	int s = (l + r) / 2;
	tree[x] = max (build (x * 2 + 1, l, s), build (x * 2 + 2, s + 1, r));
	re inf;
}

int add (int x, int l, int r, int lc, int rc, int y) {
	if (r < lc || l > rc) re min (tree[x], same[x]);
	if (l >= lc && r <= rc) {
		same[x] = y;
//		printf ("%d = %d %d\n", x, tree[x], same[x]);
		re min (tree[x], same[x]);
	}
	int s = (l + r) / 2;
	tree[x] = max (add (x * 2 + 1, l, s, lc, rc, y), add (x * 2 + 2, s + 1, r, lc, rc, y));
	re min (tree[x], same[x]);
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d%d", &v[i].se.fi, &v[i].se.se, &v[i].fi);
		v[i].se.fi = 2 * (v[i].se.fi - 1);
		v[i].se.se = 2 * (v[i].se.se - 1);
	}
	build (0, 0, 2 * m - 2);
	sort (v, v + n);
	int ans = 1e9;
	for (int i = n - 1; i >= 0; i--) {
		int cur = add (0, 0, 2 * m - 2, v[i].se.fi, v[i].se.se, v[i].fi);
		if (cur < inf) ans = min (ans, cur - v[i].fi);
	}
	printf ("%d\n", ans);
    re 0;
}