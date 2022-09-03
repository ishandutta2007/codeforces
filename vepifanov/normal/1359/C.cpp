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
int h, c, t;

pair<ll, ll> get (ll k) {
	ll sum = abs ((k + 1) / 2 * h + k / 2 * c - t * k);
	re mp (sum, k);
}

bool ls (const pair<ll, ll>& a, const pair<ll, ll>& b) {
	re a.fi * b.se < a.se * b.fi || (a.fi * b.se == a.se * b.fi && a.se < b.se);
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d%d", &h, &c, &t);
		if (2 * t <= h + c) printf ("2\n"); else {
			pair<ll, ll> ans = get (2);
			int k = (h - t) / (2 * t - h - c);
			for (int s = k - 1; s <= k + 1; s++)
				if (s >= 0) {
					pair<ll, ll> cur = get (2 * s + 1);
					if (ls (cur, ans)) ans = cur;
				}
			printf ("%lld\n", ans.se);
		}
	}
	re 0;
}