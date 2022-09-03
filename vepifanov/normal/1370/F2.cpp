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

const int N = 1000;

int n;
int m;
int d[N];
int tin[N];
int tout[N];
int par[N];
int ct;
vi v[N];
int was[N];

ii ask (vi w) {
	sort (all (w));
	w.resize (unique (all (w)) - w.begin ());
	printf ("? %d", sz (w));
	for (auto x : w) printf (" %d", x + 1);
	printf ("\n");
	fflush (stdout);
	int x, y;
	scanf ("%d%d", &x, &y); x--;
	re mp (x, y);
}

int go (int x, int p, int len) {
	d[x] = len;
	tin[x] = ct++;
	par[x] = p;
	for (auto y : v[x])
		if (y != p)
			go (y, x, len + 1);
	tout[x] = ct++;
	re 0;
}

vii u;
int best;

int go2 (int x, int p, int sd) {
	int ok = 1;
	for (auto y : v[x])
		if (y != p && !was[y]) {
			go2 (y, x, sd);
			ok = 0;
		}	
	if (ok) {
		best = max (best, d[x] - sd);
		u.pb (mp (d[x] - sd, x));
	}
	re 0;
}

bool isanc (int a, int b) { re tin[a] <= tin[b] && tout[a] >= tout[b]; }

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) v[i].clear ();
		for (int i = 1; i < n; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			v[a].pb (b);
			v[b].pb (a);
		}
		vi w(n);
		for (int i = 0; i < n; i++) {
			w[i] = i;
			was[i] = 0;
		}	
		ii cur = ask (w);
		int root = cur.fi;
		int len = cur.se;
		ct = 0;
		go (root, root, 0);
		int a = root, b = root;
		while (true) {
//			printf ("- %d %d\n", a + 1, b + 1);
			w.clear ();
			best = 0;
			u.clear ();
			for (auto c : v[a])
				if (c != par[a] && !isanc (c, b) && !was[c])
					go2 (c, a, d[a]);
			if (a != b)
			for (auto c : v[b])
				if (c != par[b] && !isanc (c, a) && !was[c])
					go2 (c, b, d[b]);
			best = (best + 1) / 2;
			for (int i = 0; i < sz (u); i++)
				if (u[i].fi >= best)
					w.pb (u[i].se);
			if (d[a] + d[b] == len || w.empty ()) {
				printf ("! %d %d\n", a + 1, b + 1);
				fflush (stdout);
				char h[10];
				scanf (" %s", h);
				break;
			}
			cur = ask (w);
			int rem = (cur.se - len) / 2;
			for (auto x : w) {
				int y = x;
				for (int i = 0; i < rem; i++) {
					was[y] = 1;
					y = par[y];
				}
			}
			int y = cur.fi;
			for (int i = 0; i < rem; i++) y = par[y];
			if (isanc (a, y)) a = y; else b = y;
		}
	}
	re 0;
}