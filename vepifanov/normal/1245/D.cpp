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
int x[2000];
int y[2000];
int c[2000];
int k[2000];
vector<pair<ll, ii> > v;
int p[2000];
int q[2000];
vi rv;
vii red;

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &c[i]);
		v.pb (mp (c[i], mp (i, i)));
	}
	for (int i = 0; i < n; i++) scanf ("%d", &k[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			v.pb (mp ((ll)(k[i] + k[j]) * (abs (x[i] - x[j]) + abs (y[i] - y[j])), mp (i, j)));
	for (int i = 0; i < n; i++) {
		p[i] = i;
		q[i] = 0;
	}
	sort (all (v));
	ll ans = 0;
	for (int i = 0; i < sz (v); i++) {
		ll c = v[i].fi;
		int a = v[i].se.fi;
		int b = v[i].se.se;
		if (a == b) {
			a = gp (a);
			if (q[a]) continue;
			q[a] = 1;
			ans += c;
			rv.pb (v[i].se.fi + 1);
		} else {
			a = gp (a);
			b = gp (b);
			if (a == b || (q[a] && q[b])) continue;
			if (rand () & 1) swap (a, b);
			p[a] = b;
			q[b] |= q[a];
			ans += c;
			red.pb (mp (v[i].se.fi + 1, v[i].se.se + 1));
		}
	}
	printf ("%lld\n", ans);
	printf ("%d\n", sz (rv));
	for (auto x : rv) printf ("%d ", x);
	printf ("\n");
	printf ("%d\n", sz (red));
	for (auto& x : red) printf ("%d %d\n", x.fi, x.se);
	re 0;
}