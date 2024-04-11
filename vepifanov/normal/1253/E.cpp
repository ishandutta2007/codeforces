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

int n;
int m;
int res[100001];
int tree[(1 << 18) + 10];
vii v[100001];

int get (int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re 1e9;
	if (l >= lc && r <= rc) re tree[x];
	int s = (l + r) / 2;
	re min (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

int upd (int x, int l, int r, int y, int z) {
	if (r < y || l > y) re tree[x];
	if (l == r) re tree[x] = z;
	int s = (l + r) / 2;
	re tree[x] = min (upd (x * 2 + 1, l, s, y, z), upd (x * 2 + 2, s + 1, r, y, z));
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d%d", &x, &y); x--;
		v[max (0, x - y)].pb (mp (min (m, x + y + 1), 0));
		for (int j = y + 1; x - j >= 0 || x + j < m; j++)
			v[max (0, x - j)].pb (mp (min (m, x + j + 1), j - y));
	}
	memset (tree, 0, sizeof (tree));
	res[m] = 0;
	for (int i = m - 1; i >= 0; i--) {
		int cur = 1e9;
		for (auto& y : v[i]) {
//			printf ("%d -> %d %d\n", i, i + 1, y.fi);
			cur = min (cur, get (0, 0, m, i + 1, y.fi) + y.se);
		}
		res[i] = cur;
		upd (0, 0, m, i, cur);
	}
	printf ("%d\n", res[0]);
	re 0;
}