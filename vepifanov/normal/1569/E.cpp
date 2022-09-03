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
 
int k;
int n;
int m;
int mul;
int h;
int w[32];
int p[33];
ii q[33];
vector<pair<int, vi> > res[2][32];

void gen (int t, int l, int r) {
	vi now (n);
	int cn = r - l;
	for (int i = 0; i < cn; i++) q[i] = mp (l + i, cn + 1);
	for (int mask = 0; mask < (1 << (cn - 1)); mask++) {
		for (int i = 0; i < n; i++) now[i] = 0;
		int m = cn;
		for (int i = 0, j = 0; j < cn - 1; i += 2, j++)
			if ((mask >> j) & 1) {
				q[m++] = mp (q[i].fi, q[i].se / 2 + 1);
				now[q[i + 1].fi] = q[i + 1].se;
			} else {
				q[m++] = mp (q[i + 1].fi, q[i + 1].se / 2 + 1);
				now[q[i].fi] = q[i].se;
			}
		int win = q[m - 1].fi;
		now[win] = 1;
		int cur = 0;
		for (int i = 0; i < n; i++) 
			if (now[i] != 0)
				cur = (cur + (ll)(i + 1) * p[now[i]]) % mod;
		res[t][win].pb (mp (cur, now));
	}
	for (int i = 0; i < n; i++) sort (all (res[t][i]));
}

int main () {
	scanf ("%d%d%d", &k, &mul, &h);
	n = 1 << k;
	p[0] = 1;
	for (int i = 1; i <= 32; i++) p[i] = ((ll)p[i - 1] * mul) % mod;
	gen (0, 0, n / 2);
	gen (1, n / 2, n);
	ll sec = ((ll)mul * mul - mul) % mod;
	for (int i = 0; i < n / 2; i++)
		for (int j = n / 2; j < n; j++)
			for (int win = 0; win < 2; win++) {
//				printf ("%d %d = %d %d\n", i, j, sz (res[0][i]), sz (res[1][j]));
				ll add = 0;
				for (int k = 0, t = sz (res[1][j]) - 1; k < sz (res[0][i]); k++) {
					ll req = (h + add - res[0][i][k].fi - (win ? (i + 1) * sec : (j + 1) * sec)) % mod;
//					printf ("%lld %lld\n", h + add - res[0][i][k].fi - win ? (ll)(i + 1) * sec : (ll)(j + 1) * sec, win ? (ll)(i + 1) * sec : (ll)(j + 1) * sec);
					while (req < 0) {
						req += mod;
						add += mod;
						t = sz (res[1][j]) - 1;
					}
//					printf ("%d %lld %d %d %d\n", h, req, res[0][i][k].fi, res[1][j][0].fi, sec);
					while (t >= 0 && res[1][j][t].fi > req) t--;
					if (t >= 0 && res[1][j][t].fi == req) {
						if (win) res[0][i][k].se[i]++; else res[1][j][t].se[j]++;
						for (int a = 0; a < n; a++) printf ("%d ", res[0][i][k].se[a] + res[1][j][t].se[a]);
						printf ("\n");
						re 0;
					}
				}
			}
	printf ("-1\n");
    re 0;
}