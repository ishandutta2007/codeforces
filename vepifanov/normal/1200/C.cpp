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

ll n;
ll m;
ll g;
int q;

ll get (ll x, ll y) {
	if (x == 1) {
		re (y - 1) / (n / g);
	} else {
		re (y - 1) / (m / g);
	} 
}


int main () {
	scanf ("%lld%lld%d", &n, &m, &q);
	g = gcd (n, m);
	for (int i = 0; i < q; i++) {
		ll sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		if (get (sx, sy) == get (ex, ey)) printf ("YES\n"); else printf ("NO\n");
	}
	re 0;
}