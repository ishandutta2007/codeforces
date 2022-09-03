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
int m[2];
int p[2][100000];
int bad[100000];
vii res;
set<ii> all;
vector<pair<ii, int> > v;
int r[2];

int gp (int t, int x) {
	if (p[t][x] != x) p[t][x] = gp (t, p[t][x]);
	re p[t][x];
}

int main () {
	scanf ("%d%d%d", &n, &m[0], &m[1]);
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < n; i++) p[t][i] = i;
		r[t] = n;
		for (int i = 0; i < m[t]; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			int pa = gp (t, a);
			int pb = gp (t, b);
			if (pa != pb) {
				if (rand () & 1) swap (pa, pb);
				p[t][pa] = pb;
				r[t]--;
			}
		}
	}
	mt19937 rng(0);
	while (sz (res) < min (r[0], r[1]) - 1) {
		v.clear ();
		all.clear ();
		for (int i = 0; i < n; i++) {
			if (bad[i] || all.count (mp (gp (0, i), gp (1, i)))) {
				bad[i] = 1;
				continue;
			}	
			all.insert (mp (gp (0, i), gp (1, i)));
			v.pb (mp (mp (gp (0, i), gp (1, i)), i));
		}
		shuffle (all (v), rng);
		for (int i = 0; i < sz (v); i++) {
			int ok = 0;
			for (int j = 1; j <= 10 && i + j < sz (v); j++) {
				int a = gp (0, v[i].fi.fi);
				int b = gp (1, v[i].fi.se);
				int c = v[i].se;
				int a1 = gp (0, v[i + j].fi.fi);
				int b1 = gp (1, v[i + j].fi.se);
				int c1 = v[i + j].se;
				if (a != a1 && b != b1) {
					ok = 1;
					res.pb (mp (c, c1));
					assert (gp (0, c) != gp (0, c1) && gp (1, c) != gp (1, c1));
					p[0][a1] = a;
					p[1][b1] = b;
				}
			}
//			if (!ok) bad[v[i].se] = 1;
		}	
		for (int i = 0; i < n; i++) swap (p[0][i], p[1][i]);
		cerr << sz (res) << " " << min (r[0], r[1]) << endl;
	}	
	printf ("%d\n", sz (res));
	for (auto& x : res) printf ("%d %d\n", x.fi + 1, x.se + 1);
    re 0;
}