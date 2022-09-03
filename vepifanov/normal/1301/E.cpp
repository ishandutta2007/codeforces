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
int q;

char g[510][510];
ii seg[10][510];
int sq[510][510];
vii u[510];
vi now[10][510];
int res[300000];
int r1[300000];
int r2[300000];
int c1[300000];
int c2[300000];
int f[510][510];

void add (int x, int y) {
	x++;
	y++;
	for (int i = x; i > 0; i = (i & (i + 1)) - 1)
		for (int j = y; j > 0; j = (j & (j + 1)) - 1) {
			f[i][j]++;
		}
}

int get (int x, int y) {
	x++;
	y++;
	int s = 0;
	for (int i = x; i <= n; i |= i + 1)
		for (int j = y; j <= m; j |= j + 1) {
			s += f[i][j];
		}	
	re s;
}

int get (int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) re 0;
	re get (x1, y1) - get (x1, y2 + 1) - get (x2 + 1, y1) + get (x2 + 1, y2 + 1);
}

int build (int t, int l, int r) {
	int s = (l + r) / 2;
	seg[t][s] = mp (l, r);
	if (l + 1 == r) re 0;
	build (t + 1, l, s);
	build (t + 1, s, r);
	re 0;
}

int main () {
	scanf ("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) scanf (" %s", g[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			sq[i][j] = 1;
			if (i > 0 && j > 0 && g[i - 1][j] == g[i][j] && g[i][j - 1] == g[i][j] && g[i - 1][j - 1] == g[i][j])
				sq[i][j] += min (sq[i - 1][j], min (sq[i][j - 1], sq[i - 1][j - 1]));
		}
	for (int i = 0; i + 1 < n; i++)
		for (int j = 0; j + 1 < m; j++) {
			if (g[i][j] != 'R' || g[i + 1][j] != 'Y' || g[i][j + 1] != 'G' || g[i + 1][j + 1] != 'B') continue;
			int l = 1, r = min (min (i + 1, j + 1), min (n - i, m - j)) + 1;
			while (r - l > 1) {
				int s = (l + r) / 2;
				if (sq[i][j] >= s && sq[i + s][j] >= s && sq[i][j + s] >= s && sq[i + s][j + s] >= s) l = s; else r = s;
			}
//			printf ("%d %d = %d\n", i, j, l);
			u[l].pb (mp (i, j));
		}
	int l = 0, r = min (n, m) / 2 + 1;
	build (0, l, r);
	int last = r;
	for (int i = 0; i < q; i++) {
		scanf ("%d%d%d%d", &r1[i], &c1[i], &r2[i], &c2[i]); r1[i]--; c1[i]--; r2[i]--; c2[i]--;
		now[0][(l + r) / 2].pb (i);
		last = min (last, (l + r) / 2);
	}
	int it = 0;
	while (last < r) {
		memset (f, 0, sizeof (f));
		int olast = last;
		last = r;
		for (int cs = r; cs >= olast; cs--) {
			int cl = seg[it][cs].fi;
			int cr = seg[it][cs].se;
			for (auto& x : u[cs]) {
				add (x.fi, x.se);
//				printf ("add %d %d\n", x.fi, x.se);
			}	
			if (cl == cr) continue;
//			printf ("seg %d %d\n", cl, cr);
			for (auto j : now[it][cs])
				if (cl + 1 == cr)
					res[j] = cl;
				else {
//					printf ("%d: %d = %d %d %d %d = %d\n", cs, j, r1[j] + cs - 1, c1[j] + cs - 1, r2[j] - cs, c2[j] - cs, get (r1[j] + cs - 1, c1[j] + cs - 1, r2[j] - cs, c2[j] - cs));
					if (get (r1[j] + cs - 1, c1[j] + cs - 1, r2[j] - cs, c2[j] - cs)) {
						last = min (last, (cs + cr) / 2);
						now[it + 1][(cs + cr) / 2].pb (j);
					} else {
						last = min (last, (cl + cs) / 2);
						now[it + 1][(cl + cs) / 2].pb (j);
					}
				}
			now[it][cs].clear ();
		}
		it++;
	}
	for (int i = 0; i < q; i++) printf ("%d\n", res[i] * res[i] * 4);
	cerr << clock () << endl;
	re 0;
}