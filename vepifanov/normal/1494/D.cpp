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
int val[1000];
vii res;
int g[500][500];

int go (const vi& v) {
	if (sz (v) == 1) re v[0];
	int top = 0;
	for (int i = 0; i < sz (v); i++)
		for (int j = i + 1; j < sz (v); j++)
			top = max (top, g[v[i]][v[j]]);
	int root = m++;
	val[root] = top;
	vi w (sz (v), 0);
	for (int i = 0; i < sz (v); i++)
		if (!w[i]) {
			vi u;
			for (int j = 0; j < sz (v); j++)
				if (g[v[i]][v[j]] != top) {
					u.pb (v[j]);
					w[j] = 1;
				}
			int child = go (u);
			res.pb (mp (child + 1, root + 1));
		}
	re root;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%d", &g[i][j]);
	vi v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i;
		val[i] = g[i][i];
	}
	m = n;
	int root = go (v);
	printf ("%d\n", m);
	for (int i = 0; i < m; i++) printf ("%d ", val[i]);
	printf ("\n%d\n", root + 1);
	for (int i = 0; i < sz (res); i++) printf ("%d %d\n", res[i].fi, res[i].se);
	re 0;
}