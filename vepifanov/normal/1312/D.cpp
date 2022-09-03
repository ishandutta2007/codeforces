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
const int N = 200000;

int n;
int m;
int f[N + 1];
int rf[N + 1];
int inv[N + 1];
int p2[N + 1];

int main () {
	f[0] = rf[0] = f[1] = rf[1] = inv[1] = p2[0] = 1;
	p2[1] = 2;
	for (int i = 2; i <= N; i++) {
		f[i] = ((ll)f[i - 1] * i) % mod;
		inv[i] = (mod - (ll)(mod / i) * inv[mod % i] % mod);
		rf[i] = ((ll)rf[i - 1] * inv[i]) % mod;
		p2[i] = ((ll)p2[i - 1] * 2) % mod;
	}
	scanf ("%d%d", &n, &m);
	if (n == 2 || n - 1 > m) {
		printf ("0\n");
		re 0;
	}
	int ans = ((ll)f[m] * rf[n - 1] % mod * rf[m - n + 1] % mod * p2[n - 3] % mod * (n - 2)) % mod;
	printf ("%d\n", ans);
	re 0;
}