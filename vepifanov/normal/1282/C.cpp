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
int a;
int b;
int t[2];
int s[2];
int c[2];
ii v[200000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d%d%d", &n, &m, &t[0], &t[1]);
		s[0] = s[1] = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &v[i].se);
			s[v[i].se]++;
		}	
		for (int i = 0; i < n; i++) scanf ("%d", &v[i].fi);
		sort (v, v + n);
		int ans = 0;
		c[0] = c[1] = 0;
		for (int i = 0; i <= n; i++) {
			int now = i < n ? v[i].fi - 1 : m;
			if (now >= 0) {
				if ((ll)c[0] * t[0] + (ll)c[1] * t[1] <= now) {
					int cur = c[0] + c[1];
					int cc0 = min ((ll)s[0] - c[0], (now - (ll)c[0] * t[0] - (ll)c[1] * t[1]) / t[0]);
					cur += cc0;
					int cc1 = min ((ll)s[1] - c[1], (now - (ll)c[0] * t[0] - (ll)c[1] * t[1] - (ll)cc0 * t[0]) / t[1]);
					cur += cc1;
					ans = max (ans, cur);
				}
			}
			if (i < n) c[v[i].se]++;
		}
		printf ("%d\n", ans);
	}
	re 0;
}