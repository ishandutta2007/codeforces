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
int o;
map<ii, int> num;
vi v;
int last[300010];
int f[300010];
int x[300010];
int y[300010];
int res[100010];
int tin[100010];
int tout[100010];
vii w[300010];

int get (int x, int y) {
	int d = gcd (abs (x), abs (y));
	x /= d;
	y /= d;
	if (num.count (mp (x, y))) re num[mp (x, y)];
	num[mp (x, y)] = o++;
	re o - 1;
}

int get (int x) {
	x++;
	int y = 0;
	while (x > 0) {
		y += f[x];
		x = (x & (x + 1)) - 1;
	}
	re y;
}

void add (int x, int y) {	
	x++;
	while (x <= sz (v) + 1) {
		f[x] += y;
		x |= x + 1;
	}
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &m);
		for (int i = 0; i < m; i++) scanf ("%d%d", &x[i], &y[i]);
		x[m] = x[0];
		y[m] = y[0];
		tin[i] = sz (v);
		for (int i = 0; i < m; i++) v.pb (get (x[i + 1] - x[i], y[i + 1] - y[i]));
		tout[i] = sz (v) - 1;
	}
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf ("%d%d", &l, &r); l--; r--;
		w[tin[l]].pb (mp (tout[r], i));
	}
	for (int i = 0; i < o; i++) last[i] = sz (v);
	memset (f, 0, sizeof (f));
	for (int i = sz (v) - 1; i >= 0; i--) {
		add (last[v[i]], -1);
		add (i, 1);
		last[v[i]] = i;
		for (auto & q : w[i]) res[q.se] = get (q.fi);
	}
	for (int i = 0; i < m; i++) printf ("%d\n", res[i]);
	re 0;
}