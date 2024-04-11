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

const int N = 250;
const int mod = 1000*1000*1000+7;

int n;
int m;

int cnk[N + 1][N + 1];
int res[N + 1][N + 1];
int pm[N + 1];
int rpm[N + 1];
int cnt[N + 1];

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
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= i; j++)
			if (i == 0 || j % i == 0)
				cnk[i][j] = 1;
			else
				cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mod;	
	scanf ("%d%d", &n, &m);
	if (m == 1) {
		printf ("1\n");
		re 0;
	}
	pm[0] = rpm[0] = 1;
	for (int i = 1; i <= n; i++) {
		pm[i] = ((ll)pm[i - 1] * (m - 1)) % mod;
		rpm[i] = power (pm[i], mod - 2);
	}	
	for (int i = 0; i <= n; i++) {
		cnt[i] = 0;
		for (int j = 1; j <= i; j++) cnt[i] = (cnt[i] + (ll)cnk[i][j] * rpm[j]) % mod;
	}
	res[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			if (res[i][j])
				for (int b = 0; j + b <= n; b++) {
					res[i + 1][j + b] = (res[i + 1][j + b] + (ll)res[i][j] * cnt[j] % mod * cnk[n - j][b] % mod * pm[n - b]) % mod;
					if (b > 0) res[i + 1][j + b] = (res[i + 1][j + b] + (ll)res[i][j] * cnk[n - j][b] % mod * pm[n - b]) % mod;
				}
	printf ("%d\n", res[n][n]);
	re 0;
}