//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
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

int p[200000];
int x[200000];

int gp (int x) {
	if (x != p[x]) p[x] = gp (p[x]);
	re p[x];
}

pair<ll, ll> calc (ll h) {
	vector<pair<ll, ii> > w;
	ll cur = (ll)x[0] * x[n - 1] + h * (x[0] + x[n - 1]);
	ll slope = x[0] + x[n - 1];
	for (int i = 1; i + 1 < n; i++) {
		if ((ll)x[0] * x[i] + h * (x[0] + x[i]) < (ll)x[n - 1] * x[i] + h * (x[n - 1] + x[i])) {
			cur += (ll)x[0] * x[i] + h * (x[0] + x[i]);
			slope += (x[0] + x[i]);
		} else {
			cur += (ll)x[n - 1] * x[i] + h * (x[n - 1] + x[i]);
			slope += (x[n - 1] + x[i]);
		}
	}
	re mp (cur, slope);
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		sort (x, x + n);
		ll a = 0, b = 0, sum = 0;
		for (int i = 0; i < n; i++) sum += x[i];
		a = sum + (ll)(n - 2) * x[0];
		b = sum + (ll)(n - 2) * x[n - 1];
		if (a > 0 || b < 0) {
			printf ("INF\n");
			continue;
		}
		ll l = -1e6, r = 1e6;
		while (r - l > 2) {
			ll s1 = (2 * l + r) / 3;
			ll s2 = (l + 2 * r) / 3;
			ll h1 = calc (s1).fi;
			ll h2 = calc (s2).fi;
			if (h1 > h2) r = s2; else l = s1;
		}
		ll ans = -5e18;
		pair<ll, ll> x = calc (l - 5);
		for (ll i = l - 5; i < r + 5; i++) {
			ans = max (ans, x.fi);
			pair<ll, ll> y = calc (i + 1);
			pair<ll, ll> oy = y;
			x.fi -= x.se * i;
			y.fi -= y.se * (i + 1);
			if (x.se > y.se) ans = max (ans, x.fi + x.se * (x.fi - y.fi) / (y.se - x.se));
			x = oy;
		}
		printf ("%lld\n", ans);
	}
    re 0;
}