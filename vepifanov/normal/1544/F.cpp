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

const int mod = 31607;
 
int n;
int m;
int g[21][21];
int p[21][21];
int q[21][21];
int pcols[21][1 << 21];
int fb[1 << 21];
int res[21];
int frow[21];
int col[21];

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int go (int d1, int d2) {
	int ans = 0;
	for (int rows = 0; rows < (1 << n); rows++) {
		int cur = 1;
		int q = 1;
		for (int i = 0; i < n; i++)
			if ((rows >> i) & 1) {
				cur = cur * frow[i] % mod;
				q = mod - q;
			}
		if (d1)
			for (int i = 0; i < n; i++)
				if (((rows >> i) & 1) == 0)
					cur = cur * p[i][i] % mod;
		if (d2)
			for (int i = 0; i < n; i++)
				if (((rows >> i) & 1) == 0 && (!d1 || i != n - i - 1))
					cur = cur * p[i][n - i - 1] % mod;
//		printf ("%d %d %d = %d\n", d1, d2, rows, cur);
		for (int i = 0; i < n; i++) {
			int mask = ((1 << n) - 1) ^ rows;
			if (d1 && ((mask >> i) & 1)) mask ^= 1 << i;
			if (d2 && ((mask >> (n - i - 1)) & 1)) mask ^= 1 << (n - i - 1);
			col[i] = pcols[i][mask];
//			printf ("%d = %d %d\n", i, mask, col[i]);
		}
		res[0] = 1;
		for (int i = 0; i < n; i++)	res[i + 1] = res[i] * (1 - col[i] + mod) % mod;
//		printf ("%d\n", res[n]);
		ans = (ans + q * res[n] % mod * cur) % mod;
	}
//	printf ("%d %d %d\n", ans, d1, d2);
	re ans;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf ("%d", &g[i][j]);
			p[i][j] = (g[i][j] * power (10000, mod - 2)) % mod;
			q[i][j] = (mod + 1 - p[i][j]) % mod;
		}
	fb[0] = -1;
	for (int i = 1; i < (1 << n); i++) {
		int j = 0;
		while (((i >> j) & 1) == 0) j++;
		fb[i] = j;
	}
	for (int i = 0; i < n; i++) {
		pcols[i][0] = 1;
		for (int j = 1; j < (1 << n); j++) {
			int k = fb[j];
			pcols[i][j] = pcols[i][j ^ (1 << k)] * p[k][i] % mod;
		}
		frow[i] = 1;
		for (int j = 0; j < n; j++) frow[i] = frow[i] * p[i][j] % mod;
	}
	int ans = (go (0, 0) - go (0, 1) - go (1, 0) + go (1, 1)) % mod;
	ans = (1 - ans) % mod;
	if (ans < 0) ans += mod;
	printf ("%d\n", ans);
    re 0;
}