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

const int mod = 998244353;

int n;
int m;

int power (int a, ll b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int main () {
	int l, r;
	scanf ("%d%d%d%d", &n, &m, &l, &r);
	r = r - l + 1;
	if (((ll)n * m) % 2 == 1) {
		printf ("%d\n", power (r, (ll)n * m));
		re 0;
	}
	int a = (r + 1) / 2;
	int b = r / 2;
	int c0 = 1, c1 = 0;
	int g0 = b, g1 = a;
	ll k = (ll)n * m;
	while (k) {
		if (k & 1) {
			int n0 = ((ll)c0 * g0 + (ll)c1 * g1) % mod;
			int n1 = ((ll)c0 * g1 + (ll)c1 * g0) % mod;
			c0 = n0;
			c1 = n1;
		}
		int n0 = ((ll)g0 * g0 + (ll)g1 * g1) % mod;
		int n1 = ((ll)g0 * g1 + (ll)g1 * g0) % mod;
		g0 = n0;
		g1 = n1;
		k /= 2;
	}
	printf ("%d\n", c0);
	re 0;
}