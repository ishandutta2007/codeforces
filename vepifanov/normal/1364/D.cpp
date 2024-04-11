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
int k;
int ans;
int d[100000];
int par[100000];
int was[100000];
vi col[2];
vi v[100000];
int ai, aj;

int go (int x, int p, int len) {
	d[x] = len;
	par[x] = p;
	was[x] = 1;
	col[len & 1].pb (x);
	for (auto y : v[x]) {
		if (y == p) continue;
		if (!was[y])
			go (y, x, len + 1);
		else
		if (was[y] == 1 && len - d[y] + 1 < ans) {
			ans = len - d[y] + 1;
			ai = x;
			aj = y;
		}
	}
	was[x] = 2;
	re 0;
}

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	ans = n + 1;
	vi res;
	int tp = 1;
	for (int i = 0; i < n; i++)
		if (!was[i]) {
			col[0].clear ();
			col[1].clear ();
			go (i, i, 0);
			if (sz (col[0]) > sz (col[1]))
				res.insert (res.end (), col[0].begin (), col[0].end ());
			else
				res.insert (res.end (), col[1].begin (), col[1].end ());
		}
	if (ans <= n) {
		if (ans <= k) {
			tp = 2;
			res.clear ();
			do {
				res.pb (ai);
				ai = par[ai];
			} while (ai != aj);
			res.pb (aj);
		} else {
			res.clear ();
			int t = 0;
			do {
				if (!t) res.pb (ai);
				t ^= 1;
				ai = par[ai];
			} while (ai != aj);
		}
	}
	printf ("%d\n", tp);
	if (tp == 1) {
		for (int i = 0; i < sz (res) && i < (k + 1) / 2; i++)
			printf ("%d ", res[i] + 1);
		printf ("\n");
	} else {
		printf ("%d\n", sz (res));
		for (auto x : res) printf ("%d ", x + 1);
		printf ("\n");
	}
	re 0;
}