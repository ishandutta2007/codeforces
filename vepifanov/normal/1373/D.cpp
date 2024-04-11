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

ll s[200010][2];
int x[200010];
ll best[2];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		s[n][0] = s[n][1] = 0;
		for (int i = n - 1; i >= 0; i--) {
			s[i][0] = s[i + 1][0];
			s[i][1] = s[i + 1][1];
			s[i][i & 1] += x[i];
		}
		ll ans = s[0][0];
		best[0] = best[1] = -1e18;
		best[n & 1] = 0;
		for (int i = n - 1; i >= 0; i--) {
			ans = max (ans, s[0][0] + (s[i][1] - s[i][0]) + best[i & 1]);
			best[i & 1] = max (best[i & 1], (s[i][0] - s[i][1]));
		}
		cout << ans << endl;
	}
	re 0;
}