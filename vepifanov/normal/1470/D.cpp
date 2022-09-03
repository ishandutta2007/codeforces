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
int p[300000];
vi v[300000];
int col[300000];
int was[300000];
vi res;

int go (int x) {
	res.pb (x);
	was[x] = 1;
	vi w;
	for (auto y : v[x])
		if (!was[y]) {
			w.pb (y);
			was[y] = 1;
		}
	for (auto y : w)
		for (auto z : v[y])
			if (!was[z])
				go (z);
	re 0;
}

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			p[i] = i;
			v[i].clear ();
			col[i] = -1;
			was[i] = 0;
		}	
		int rem = n;
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			v[a].pb (b);
			v[b].pb (a);
			int pa = gp (a);
			int pb = gp (b);
			if (pa != pb) {
				rem--;
				p[pa] = pb;
			}
		}
		if (rem > 1) printf ("NO\n"); else {
			res.clear ();
			go (0);
			printf ("YES\n%d\n", sz (res));
			for (auto x : res) printf ("%d ", x + 1);
			printf ("\n");
		}
	}
	re 0;
}