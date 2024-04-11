#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
int inv[N + 1];
int x[N];

int main () {
	f[0] = f[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= N; i++) {
		f[i] = ((ll)f[i - 1] * i) % mod;
		inv[i] = mod - (ll)inv[mod % i] * (mod / i) % mod;
	}
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		sort (x, x + n);
		reverse (x, x + n);
		if (x[0] > x[1] + 1) printf ("0\n"); else
		if (x[0] == x[1] + 1) {
			int j = 1;
			while (j < n && x[j] == x[1]) j++;
			printf ("%d\n", (int)((ll)f[n] * inv[j] % mod * (j - 1) % mod));
		} else printf ("%d\n", f[n]);
	}
    re 0;
}