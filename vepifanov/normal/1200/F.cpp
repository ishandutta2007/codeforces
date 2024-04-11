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

const int mod = 9*8*7*5;
const int N = 1000;

int n;
int was[N][mod];
int res[N][mod];
int g[N][10];
int m[N];
int d[N][mod];
int k[N];
int ct = 0;
int was2[N];
ii par[N][mod];

int go (int x, int j, int len) {
	was[x][j] = 1;
	d[x][j] = len;
	int nj = (j + k[x]) % mod;
	int t = nj % m[x];
	int y = g[x][t];
//	printf ("parse %d %d -> %d %d\n", x + 1, j, y + 1, nj);
	if (was[y][nj] == 1) {
		int xx = x, jj = j, cnt = 0;
		ct++;
		while (true) {
//			printf ("%d %d\n", xx + 1, jj);
			cnt += int (was2[xx] != ct);
			was2[xx] = ct;
			if (xx == y && jj == nj) break;
			ii tmp = par[xx][jj];
			xx = tmp.fi;
			jj = tmp.se;
		}
//		printf ("cnt = %d\n", cnt);
		res[x][j] = cnt;
	} else
	if (was[y][nj] == 2) {
		res[x][j] = res[y][nj];
	} else {
		par[y][nj] = mp (x, j);
		res[x][j] = go (y, nj, len + 1);
	}
	was[x][j] = 2;
	re res[x][j];
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &k[i]);
		k[i] = (k[i] % mod + mod) % mod;
	}
	for (int i = 0; i < n; i++) {
		scanf ("%d", &m[i]);
		for (int j = 0; j < m[i]; j++) {
			scanf ("%d", &g[i][j]); g[i][j]--;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < mod; j++)
			if (!was[i][j])
				go (i, j, 0);
	int q;
	scanf ("%d", &q);
	for (int i = 0; i < q; i++) {
		int x, y;
		scanf ("%d%d", &x, &y);
		x--;
		y = (y % mod + mod) % mod;
		printf ("%d\n", res[x][y]);
	}
	re 0;
}