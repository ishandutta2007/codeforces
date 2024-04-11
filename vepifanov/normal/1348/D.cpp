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

pair<pair<ll, ll>, pair<ll, ll> > calc (int t, ll x, ll y) {
	pair<ll, ll> left (x, y), right (x, y);
	for (int i = 0; i < t; i++) {
		left.se += left.fi;
		right.fi *= 2;
		right.se += right.fi;
	}
	re mp (left, right);	
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		int ans = 0;
		while (true) {
			ans++;
			pair<pair<ll, ll>, pair<ll, ll> > seg = calc (ans, 1, 1);
			if (seg.fi.se <= n && seg.se.se >= n) break;			
		}
		printf ("%d\n", ans);
		pair<ll, ll> cur (1, 1);
		for (int i = 0; i < ans; i++) {
			ll l = 0, r = cur.fi + 1;
			while (r - l > 1) {
				ll s = (l + r) / 2;
				pair<pair<ll, ll>, pair<ll, ll> > seg = calc (ans - i - 1, cur.fi + s, cur.se + cur.fi + s);
				if (seg.fi.se > n) r = s; else l = s;
			}
			printf ("%lld ", l);
			cur.fi += l;
			cur.se += cur.fi;
		}
		printf ("\n");
	}
	re 0;
}