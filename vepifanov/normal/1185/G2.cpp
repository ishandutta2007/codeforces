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

const int mod = 1000*1000*1000+7;

int n;
int m;
int was[51][51][51][4];
int res2[51][51][51][4];
vi v[3];
vii w[3];
vi ww[3][2501];
int res[3][2][2501][51];

inline int go (int a, int b, int c, int f) {
	if (a + b + c == 0) re 1;
	if (was[a][b][c][f]) re res2[a][b][c][f];
	was[a][b][c][f] = 1;
	ll cur = 0;
	if (a > 0 && f != 0) cur += (ll)a * go (a - 1, b, c, 0);
	if (b > 0 && f != 1) cur += (ll)b * go (a, b - 1, c, 1);
	if (c > 0 && f != 2) cur += (ll)c * go (a, b, c - 1, 2);
//	printf ("%d %d %d %d = %lld\n", a, b, c, f, cur);
	re res2[a][b][c][f] = cur % mod;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d%d", &x, &y); y--;
		v[y].pb (x);
	}
	vii u;
	for (int t = 0; t < 3; t++) {
		memset (res[t], 0, sizeof (res[t]));
		res[t][0][0][0] = 1;
		sort (all (v[t]));
		int sum = 0;
		for (int i = 0; i < sz (v[t]); i++) {
			int ci = i & 1;
			int ni = 1 - ci;
			memset (res[t][ni], 0, sizeof (res[t][ni]));
			for (int j = 0; j <= sum; j++)
				for (int k = 0; k <= i; k++)
					if (res[t][ci][j][k]) {
						res[t][ni][j][k] = (res[t][ni][j][k] + res[t][ci][j][k]) % mod;
						res[t][ni][j + v[t][i]][k + 1] = (res[t][ni][j + v[t][i]][k + 1] + res[t][ci][j][k]) % mod;
					}
			sum += v[t][i];
		}
		for (int i = 0; i <= sum; i++)
			for (int j = 0; j <= sz (v[t]); j++)
				if (res[t][sz (v[t]) & 1][i][j]) {
//					printf ("%d %d %d\n", t, i, j);
					w[t].pb (mp (i, j));
					ww[t][i].pb (j);
				}
		u.pb (mp (sz (w[t]), t));
	}
	sort (all (u));
	int a = u[0].se;
	int b = u[1].se;
	int c = 3 - a - b;
	int ans = 0;
	for (int i = 0; i < sz (w[a]); i++)
		for (int j = 0; j < sz (w[b]); j++)
			if (w[a][i].fi + w[b][j].fi <= m) {
				int rem = m - w[a][i].fi - w[b][j].fi;
				int cur = ((ll)res[a][sz (v[a]) & 1][w[a][i].fi][w[a][i].se] * res[b][sz (v[b]) & 1][w[b][j].fi][w[b][j].se]) % mod;
				for (auto k : ww[c][rem]) {
//					printf ("%d %d %d\n", cur, res[c][sz (v[c]) & 1][rem][k], go (w[a][i].se, w[b][j].se, k, 3));
					ans = (ans + (ll)cur * res[c][sz (v[c]) & 1][rem][k] % mod * go (w[a][i].se, w[b][j].se, k, 3)) % mod;
				}	
			}
	printf ("%d\n", ans);
	re 0;
}