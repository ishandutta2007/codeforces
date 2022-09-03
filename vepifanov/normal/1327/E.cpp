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

const int N = 200010;
const int mod = 998244353;

int n;
int m;

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int main () {
	scanf ("%d", &n);
	for (int len = 1; len <= n; len++) {
		int ans = 0;
		if (len == n) ans = 10; else {
			ans = (ans + (ll)2 * 10 * 9 * power (10, n - len - 1)) % mod;
			if (len + 2 <= n) ans = (ans + (ll)10 * 9 * 9 * (n - len - 1) % mod * power (10, n - len - 2)) % mod;
		}
		printf ("%d ", ans);
	}
	printf ("\n");
	re 0;
}