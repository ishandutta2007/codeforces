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
vi v[4];
vector<ll> w[4];

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int t, a, b;
		scanf ("%d%d%d", &t, &a, &b);
		v[a | (2 * b)].pb (t);
	}
	for (int i = 0; i < 4; i++) {
		sort (all (v[i]));
		w[i].resize (sz (v[i]) + 1);
		w[i][0] = 0;
		for (int j = 0; j < sz (v[i]); j++) w[i][j + 1] = w[i][j] + v[i][j];
	}
	ll ans = 1e18;
	for (int i = 0; i <= m && i <= sz (v[3]); i++)
		if (m - i <= sz (v[1]) && m - i <= sz (v[2]))
			ans = min (ans, w[3][i] + w[1][m - i] + w[2][m - i]);
	if (ans > 5e17) ans = -1;
	printf ("%lld\n", ans);
	re 0;
}