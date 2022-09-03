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
ll m;
int x[100000];
ii p[100000];

int main () {
	scanf ("%d%lld", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	sort (x, x + n);
	int r = 0;
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && x[j] == x[i]) j++;
		p[r] = mp (x[i], j - i);
		r++;
		i = j;
	}
	int ans = p[r - 1].fi - p[0].fi;
	int l = 0;
	while (ans > 0) {
		if (p[l].se < p[r - 1].se) {
			int tmp = min (m / p[l].se, (ll)(p[l + 1].fi - p[l].fi));
			if (tmp == 0) break;
			m -= (ll)tmp * p[l].se;
			ans -= tmp;
			p[l].fi += tmp;
		} else {
			int tmp = min (m / p[r - 1].se, (ll)(p[r - 1].fi - p[r - 2].fi));
			if (tmp == 0) break;
			m -= (ll)tmp * p[r - 1].se;
			ans -= tmp;
			p[r - 1].fi -= tmp;
		}
		while (l + 1 < r && p[l].fi == p[l + 1].fi) {
			p[l + 1].se += p[l].se;
			l++;
		}
		while (l + 1 < r && p[r - 2].fi == p[r - 1].fi) {
			p[r - 2].se += p[r - 1].se;
			r--;
		}
	}
	printf ("%d\n", ans);
	re 0;
}