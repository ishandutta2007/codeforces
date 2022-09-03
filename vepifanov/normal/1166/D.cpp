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
ll sl[100];
ll sr[100];
ll res[100];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		ll a, b, m;
		cin >> a >> b >> m;
		if (a == b) {
			printf ("1 %lld\n", a);
			continue;
		}
		sl[0] = sr[0] = a;
		for (int i = 0; ; i++) {
			if (sl[i] + 1 <= b && sr[i] + m >= b) {
				n = i + 1;
				break;
			}
			if (sl[i] + 1 > b) {
				n = -1;
				break;
			}
			sl[i + 1] = sl[i] * 2 + 1;
			sr[i + 1] = sr[i] * 2 + m;
		}
		if (n == -1) printf ("-1\n"); else {
			res[n] = b;
			for (int i = n - 1; i >= 0; i--) {
				ll dec = m;
				if (i + 1 == n) {
					if ((res[i + 1] - dec) < sl[i]) dec = res[i + 1] - sl[i];
					res[i] = res[i + 1] - dec;
				} else {
					if ((res[i + 1] - dec) % 2 == 1) dec--;
//					printf ("%lld - %lld ? %lld %lld\n", res[i + 1], dec, sl[i], sr[i]);
					if ((res[i + 1] - dec) < 2 * sl[i]) dec = res[i + 1] - 2 * sl[i];
//					printf ("%lld - %lld ? %lld %lld\n", res[i + 1], dec, sl[i], sr[i]);
					res[i] = (res[i + 1] - dec) / 2;
				}
				if (i + 1 < n) res[i + 1] -= res[i];
			}
			printf ("%d", n + 1);
			for (int i = 0; i <= n; i++) printf (" %lld", res[i]);
			printf ("\n");
		}
	}
	re 0;
}