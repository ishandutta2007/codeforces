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
int k;

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	if (k > 4 * n * m - 2 * n - 2 * m) {
		printf ("NO\n");
		re 0;
	}
	vector<pair<char, int> > v;
	for (int i = 0; i < n; i++) {
		if (m > 1) v.pb (mp ('R', min (m - 1, k))); k -= min (m - 1, k); if (!k) break;
		if (i + 1 < n) {
			if (m > 1) v.pb (mp ('L', min (m - 1, k))); k -= min (m - 1, k); if (!k) break;
			v.pb (mp ('D', min (1, k))); k -= min (1, k); if (!k) break;
		} else {
			for (int j = m - 1; j > 0; j--) {
				if (n > 1) {
					v.pb (mp ('U', min (n - 1, k))); k -= min (n - 1, k); if (!k) break;
					v.pb (mp ('D', min (n - 1, k))); k -= min (n - 1, k); if (!k) break;
				}	
				v.pb (mp ('L', min (1, k))); k -= min (1, k); if (!k) break;
			}
			if (!k) break;
			if (n > 1) v.pb (mp ('U', min (n - 1, k))); k -= min (n - 1, k); if (!k) break;
		}
	}
	printf ("YES\n%d\n", sz (v));
	for (int i = 0; i < sz (v); i++) printf ("%d %c\n", v[i].se, v[i].fi);
	re 0;
}