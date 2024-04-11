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

const ll inf = 1e18;

int n;
int m;
vi v[200000];
int a[200000];

ll go (int x, ll h) {
	ll cur = 0;
	if (v[x].empty ()) cur = h; else
	for (auto y : v[x]) {
		ll tmp = go (y, h);
		if (tmp < 0) {
			cur = -inf;
			break;
		}
		cur += tmp;
		if (cur > inf) cur = inf;
	}
	cur -= a[x];
//	printf ("%lld: %d = %lld | %d\n", h, x, cur, a[x]);
	re cur;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x;
		scanf ("%d", &x); x--;
		v[x].pb (i + 1);
	}
	for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
	ll l = -1, r = inf;
	while (r - l > 1) {
		ll s = (l + r) / 2;
		if (go (0, s) >= 0) r = s; else l = s;
	}
	cout << r << endl;
	re 0;
}