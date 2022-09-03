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
vi v[1 << 17];
vi q;
int ans, pos;

int go (int x, int p, int len) {
	if (len > ans) {
		ans = len;
		pos = x;
	}
	for (auto y : v[x])
		if (y != p)
			go (y, x, len + 1);
	re 0;
}

int go2 (int x, int p, int z) {
	if (x == z) {
		q.pb (x);
		re 1;
	}
	for (auto y : v[x])
		if (y != p)
			if (go2 (y, x, z)) {
				q.pb (x);
				re 1;
			}
	re 0;
}

vi pot;
vi res;
int ok;

int go3 (int x, int p, int d) {
	vi w;
	for (auto y : v[x])
		if (y != p)
			w.pb (go3 (y, x, d + 1));
	sort (all (w));
	if (w.empty ()) re d;
//	printf ("%d = ", x + 1);
//	for (auto y : w) printf ("%d ", y);
//	printf ("\n");
	if (sz (w) == 1) {
		if (d == n - 2 && w[0] == n - 1) {
			pot.pb (x + 1);
			re n - 1;
		}
	} else
	if (sz (w) == 2) {
		if (w[0] == w[1]) {
			re w[0];
		}
	} else
	if (sz (w) == 3) {
		if (w[0] == n - 2 && w[1] == n - 2 && w[2] == n - 1) {
			pot.pb (x + 1);
			re n - 1;
		}
	}
	ok = 0;
	re n - 1;
}

int calc (int root) {
//	printf ("check %d\n", root + 1);
	pot.clear ();
	ok = 1;
	ok &= int (go3 (root, root, 0) == n - 1);
	if (ok && sz (pot) == 1) res.pb (pot[0]);
	re 0;
}

int main () {
	scanf ("%d", &n);
	m = (1 << n) - 1;
	for (int i = 0; i < m - 2; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	pos = 0;
	ans = -1;
	go (0, 0, 0);
	ans = -1;
	int ai = pos;
	go (pos, pos, 0);
	int bi = pos;
	go2 (ai, ai, bi);
	if (sz (q) % 2 == 0) {
		calc (q[sz (q) / 2]);
		calc (q[sz (q) / 2 - 1]);
	} else calc (q[sz (q) / 2]);
	res.resize (unique (all (res)) - res.begin ());
	printf ("%d\n", sz (res));
	if (!res.empty ()) {
		sort (all (res));
		for (auto x : res) printf ("%d ", x);
		printf ("\n");
	}	
	re 0;
}