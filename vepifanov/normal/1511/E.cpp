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
const int inv2 = (mod + 1) / 2;

int n;
int m;
int g[300000];
char h[300000];
int lft[300000];
int up[300000];
int res[300001];
int last[300001];
int p2[300001];

int main () {
	scanf ("%d%d", &n, &m);
	int wh = 0;
	for (int i = 0; i < n; i++) {
		scanf (" %s", h);
		for (int j = 0; j < m; j++) {
			g[i * m + j] = int (h[j] == 'o');
			wh += g[i * m + j];
		}
	}
	p2[0] = 1;
	res[0] = 1;
	last[0] = 0;
	for (int i = 1; i <= n * m; i++) {
		p2[i] = (p2[i - 1] * 2) % mod;
		res[i] = last[i] = 0;
		if (i >= 2) {
			res[i] = (inv2 + (ll)inv2 * inv2 % mod * res[i - 2]) % mod;
			last[i] = (ll)inv2 * inv2 % mod * res[i - 2] % mod;
		} else res[i] = inv2;
//		printf ("%d = %d %d\n", i, res[i], last[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (!g[i * m + j]) continue;
			lft[i * m + j] = up[i * m + j] = 1;
			if (i > 0) up[i * m + j] += up[(i - 1) * m + j];
			if (j > 0) lft[i * m + j] += lft[i * m + (j - 1)];
//			printf ("%d %d = %d %d\n", i, j, lft[i * m + j], up[i * m + j]);
			ans = ((ll)ans + last[up[i * m + j]] + last[lft[i * m + j]]) % mod;
		}
	ans = ((ll)ans * p2[wh]) % mod;
	printf ("%d\n", ans);
	re 0;
}