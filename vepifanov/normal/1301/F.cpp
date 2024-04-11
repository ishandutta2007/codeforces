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

int n;
int m;
int k;
int w[1000][1000];
int g[40][40];
int d[1000][1000][40];
ii q[1000*1000];
int was[1000][1000];
vii ww[40];

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			g[i][j] = int (i != j) * 1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf ("%d", &w[i][j]); w[i][j]--;
			ww[w[i][j]].pb (mp (i, j));
		}
	int ct = 0;
	for (int t = 0; t < k; t++) {	
		ct++;
		int l = 0, r = 0;
		for (auto& x : ww[t]) {
			d[x.fi][x.se][t] = 0;
			was[x.fi][x.se] = ct;
			q[r++] = x;
		}
		while (l < r) {
			ii x = q[l++];
			for (int d = 0; d < 4; d++) {
				int i = x.fi + int (d == 0) - int (d == 1);
				int j = x.se + int (d == 2) - int (d == 3);
				if (i < 0 || j < 0 || i >= n || j >= m || was[i][j] == ct) continue;
				was[i][j] = ct;
				::d[i][j][t] = ::d[x.fi][x.se][t] + 1;
				q[r++] = mp (i, j);
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int c = w[i][j];
			for (int t = c + 1; t < k; t++)	
				g[t][c] = g[c][t] = min (g[t][c], d[i][j][t] * 2 + 2);
		}
/*	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++)
			printf ("%d ", g[i][j]);
		printf ("\n");
	}*/
	for (int t = 0; t < k; t++)
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				g[i][j] = min (g[i][j], g[i][t] + g[t][j]);
	int q;
	scanf ("%d", &q);
	for (int i = 0; i < q; i++) {
		int r1, c1, r2, c2;
		scanf ("%d%d%d%d", &r1, &c1, &r2, &c2); r1--; c1--; r2--; c2--;
		int ans = abs (r1 - r2) + abs (c1 - c2);
		for (int a = 0; a < k; a++)
			for (int b = 0; b < k; b++)
				ans = min (ans, d[r1][c1][a] + d[r2][c2][b] + g[a][b] / 2 + 1);
		printf ("%d\n", ans);
	}
	re 0;
}