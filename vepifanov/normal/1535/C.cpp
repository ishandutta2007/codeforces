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
char s[200100];
int res[200010][2];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf (" %s", s);
		n = strlen (s);
		res[n][0] = res[n][1] = 0;
		ll ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			res[i][0] = int (s[i] != '1');
			res[i][1] = int (s[i] != '0');
			if (res[i][0]) res[i][0] += res[i + 1][1];
			if (res[i][1]) res[i][1] += res[i + 1][0];
			ans += max (res[i][0], res[i][1]);
		}
		printf ("%lld\n", ans);
	}
	re 0;
}