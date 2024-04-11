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
vii v[1000000];
vi w[1000000];
int was[1000000];
int ea[1000000];
int eb[1000000];
int cnt[1000000];
vi g;

int go (int x, int c) {
	g.pb (x);
	was[x] = 1;
	for (auto y : w[x])
		if (!was[y])
			go (y, c ^ 1);
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (mp (b, i));
		v[b].pb (mp (a, i));
		ea[i] = a;
		eb[i] = b;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 < sz (v[i]); j += 2) {
			w[v[i][j].se].pb (v[i][j + 1].se);
			w[v[i][j + 1].se].pb (v[i][j].se);
		}
	vi res;
	for (int i = 0; i < m; i++)
		if (!was[i] && sz (w[i]) < 2) {
			g.clear ();
			go (i, 0);
			for (int j = 0; j < sz (g); j += 2) res.pb (g[j]);
			if (sz (g) > 1 && sz (g) % 2 == 0) res.pb (g.back ());
		}
	for (int i = 0; i < m; i++)
		if (!was[i]) {
			g.clear ();
			go (i, 0);
			for (int j = 0; j < sz (g); j += 2) res.pb (g[j]);
		}
	printf ("%d\n", sz (res));
	for (auto x : res) {
		printf ("%d %d\n", ea[x] + 1, eb[x] + 1);
		cnt[ea[x]]++;
		cnt[eb[x]]++;
	}
/*	printf ("\n");
	for (int i = 0; i < n; i++) {
		printf ("%d: %d %d\n", i + 1, sz (v[i]), cnt[i]);
		assert (2 * cnt[i] >= sz (v[i]));
	}	*/
	re 0;
}