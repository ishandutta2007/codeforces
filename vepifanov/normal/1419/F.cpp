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

const ll inf = 1e10;

int n;
int m;
vi vx;
vi vy;
map<int, int> numx;
map<int, int> numy;
int rx;
int ry;
vii ax[1000];
vii ay[1000];
int p[1000];
int x[1000];
int y[1000];
int o;
int v[4];

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

int merge (int a, int b) {
	a = gp (a);
	b = gp (b);
	if (a != b) {
		if (rand () & 1) swap (a, b);
		p[a] = b;
		re 1;
	}
	re 0;
}

int check (int a, int b) {
	a = gp (a);
	b = gp (b);
	re int (a != b);
}

int check (int a, int b, int c) {
	a = gp (a);
	b = gp (b);
	c = gp (c);
	if (a > b) swap (a, b);
	if (b > c) swap (b, c);
	if (a > b) swap (a, b);
	re int (a != b) + int (b != c);
}

inline int check () {
	for (int i = 0; i < o; i++) v[i] = gp (v[i]);
	sort (v, v + o);
	int cur = 0;
	for (int i = 0; i + 1 < o; i++) cur += int (v[i] != v[i + 1]);
	re cur;
}

int can (ll h) {
//	printf ("%lld:\n", h);
	for (int i = 0; i < n; i++) p[i] = i;
	int now = n;
	for (int i = 0; i < rx; i++)
		for (int j = 0; j + 1 < sz (ax[i]); j++)
			if (ax[i][j].fi + h >= ax[i][j + 1].fi)
				now -= merge (ax[i][j].se, ax[i][j + 1].se);
	for (int i = 0; i < ry; i++)
		for (int j = 0; j + 1 < sz (ay[i]); j++)
			if (ay[i][j].fi + h >= ay[i][j + 1].fi)
				now -= merge (ay[i][j].se, ay[i][j + 1].se);
	if (now == 1) re 1;
	for (int i = 0; i < rx; i++)
		for (int j = 0; j + 1 < sz (ax[i]); j++)
			if (ax[i][j].fi + 2 * h >= ax[i][j + 1].fi)
				if (now - check (ax[i][j].se, ax[i][j + 1].se) == 1)
					re 1;
	for (int i = 0; i < ry; i++)
		for (int j = 0; j + 1 < sz (ay[i]); j++)
			if (ay[i][j].fi + 2 * h >= ay[i][j + 1].fi)
				if (now - check (ay[i][j].se, ay[i][j + 1].se) == 1)
					re 1;
	for (int i = 0; i < rx; i++)
		for (int j = -1; j < sz (ax[i]); j++)
			for (int s = 0; s < ry; s++)
				for (int t = -1; t < sz (ay[s]); t++) {
					int cx = vx[i];
					int cy = vy[s];
					o = 0;
					if (j >= 0 && ax[i][j].fi >= cy - h && ax[i][j].fi < cy) v[o++] = ax[i][j].se;
					if (j + 1 < sz (ax[i]) && ax[i][j + 1].fi <= cy + h && ax[i][j + 1].fi > cy) v[o++] = ax[i][j + 1].se;
					if (t >= 0 && ay[s][t].fi >= cx - h && ay[s][t].fi < cx) v[o++] = ay[s][t].se;
					if (t + 1 < sz (ay[s]) && ay[s][t + 1].fi <= cx + h && ay[s][t + 1].fi > cx) v[o++] = ay[s][t + 1].se;
					if (now - check () == 1) re 1;
/*					for (int k = 0; k < sz (v); k++) printf ("%d ", v[k]);
					printf (" = ");
					printf ("%lld: %d %d = %d | %d = ", h, cx, cy, check (v), now);
					for (int k = 0; k < sz (v); k++) printf ("%d ", v[k]);
					printf ("\n");*/
				}
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &x[i], &y[i]);
		vx.pb (x[i]);
		vy.pb (y[i]);
	}
	sort (all (vx));
	vx.resize (unique (all (vx)) - vx.begin ());
	rx = sz (vx);
	for (int i = 0; i < rx; i++) numx[vx[i]] = i;
	sort (all (vy));
	vy.resize (unique (all (vy)) - vy.begin ());
	ry = sz (vy);
	for (int i = 0; i < ry; i++) numy[vy[i]] = i;
	for (int i = 0; i < n; i++) {
		x[i] = numx[x[i]];
		y[i] = numy[y[i]];
		ax[x[i]].pb (mp (vy[y[i]], i));
		ay[y[i]].pb (mp (vx[x[i]], i));
	}
	for (int i = 0; i < rx; i++) sort (all (ax[i]));
	for (int i = 0; i < ry; i++) sort (all (ay[i]));
	ll l = 0, r = inf;
	while (r - l > 1) {
		ll s = (l + r) / 2;
		if (can (s)) r = s; else l = s;
	}
	if (r > inf / 2) r = -1;
	cout << r << endl;
//	cerr << clock () << endl;
	re 0;
}