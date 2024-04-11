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

ll a[200000];
ll b[200000];

int main () {
	scanf ("%d", &n);
	ll sa = 0, sb = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &a[i]);
		sa += a[i];
	}	
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &b[i]);
		sb += b[i];
	}
	ll ans = 0, tot = 0;
	vector<pair<char, ll> > res;
	while (true) {
		int ok1 = 1, ok2 = 1;
		int ok3 = 1, ok4 = 1;
		for (int i = 0; i < n; i++) {
			ok1 &= int (a[i] == b[i]);
			ok2 &= int (a[i] == b[n - i - 1]);
			if (i > 0) {
				ok3 &= int (b[i] > b[i - 1]);
				ok4 &= int (b[n - i - 1] > b[n - i]);
			}
		}
		if (ok1) break;
		if (ok2) {
			tot++;
			res.pb (mp ('R', 1));
			break;
		}
		if (sa >= sb) {
			ans = -1;
			break;
		}
		if (n == 1) {
			ans = -1;
			break;
		}
		if (ok4) {
			tot++;
			res.pb (mp ('R', 1));
			reverse (b, b + n);
		}
		if (ok3 || ok4) {
			if (n == 2) {
				ll tmp = min ((sb - sa + b[0] - 1) / b[0], (b[1] - 1) / b[0]);
				b[1] -= tmp * b[0];
				sb -= tmp * b[0];
				ans += tmp;
				tot += tmp;
				res.pb (mp ('P', tmp));
			} else {
				for (int i = n - 1; i > 0; i--) {
					b[i] = b[i] - b[i - 1];
					sb -= b[i - 1];
				}
				ans++;
				tot++;
				res.pb (mp ('P', 1));
			}
			continue;
		}
		ans = -1;
		break;
	}
	if (ans == -1) {
		printf ("IMPOSSIBLE\n");
		re 0;
	}
	if (ans > 200000)
		printf ("BIG\n%lld\n", ans);
	else {
		printf ("SMALL\n%d\n", (int)tot);
		for (int i = sz (res) - 1; i >= 0; i--) printf ("%s", string (res[i].se, res[i].fi).c_str ());
		printf ("\n");
	}	

	re 0;
}