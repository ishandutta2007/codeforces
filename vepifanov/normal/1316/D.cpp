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

const string sym = "DURL";

int n;
int m;
ii g[1000][1000];
int was[1000][1000];
char res[1000][1010];
ii q[1000*1000];
ii last;
ii pos;

int go (int i, int j, int pi, int pj) {
	was[i][j] = 1;
	int cur = 0;
	for (int t = 0; t < 4; t++) {
		int ni = i - int (t == 0) + int (t == 1);
		int nj = j - int (t == 2) + int (t == 3);
		if (ni < 0 || nj < 0 || ni >= n || nj >= n || g[ni][nj] != mp (-2, -2)) continue;
		if (was[ni][nj] == 1) {
			res[ni][nj] = sym[t];
			pos = last = mp (ni, nj);
			re 1;
		}
		if (was[ni][nj] == 0)
			if (go (ni, nj, i, j)) {
				if (last != mp (-2, -2))
					res[ni][nj] = sym[t];
				if (last == mp (i, j)) last = mp (-2, -2);
				re 1;
			}
	}
	was[i][j] = 2;
	re cur;
}

int go2 (int i, int j) {
	was[i][j] = 3;
	int cur = 0;
	for (int t = 0; t < 4; t++) {
		int ni = i - int (t == 0) + int (t == 1);
		int nj = j - int (t == 2) + int (t == 3);
		if (ni < 0 || nj < 0 || ni >= n || nj >= n || g[ni][nj] != mp (-2, -2) || was[ni][nj] == 3) continue;
		if (res[ni][nj] == 0) res[ni][nj] = sym[t];
		go2 (ni, nj);
	}
	re cur;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf ("%d%d", &g[i][j].fi, &g[i][j].se);
			g[i][j].fi--;
			g[i][j].se--;
		}
	memset (res, 0, sizeof (res));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!was[i][j] && g[i][j] == mp (-2, -2)) {
				if (!go (i, j, i, j)) {
					printf ("INVALID\n");
					re 0;
				} else go2 (pos.fi, pos.se);
			}
	memset (was, 0, sizeof (was));
	int l = 0, r = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[i][j] == mp (i, j)) {
				was[i][j] = 1;
				q[r++] = mp (i, j);
				res[i][j] = 'X';
			}
	while (l < r) {
		ii x = q[l++];
		for (int t = 0; t < 4; t++) {
			int i = x.fi - int (t == 0) + int (t == 1);
			int j = x.se - int (t == 2) + int (t == 3);
			if (i < 0 || j < 0 || i >= n || j >= n || was[i][j] || g[i][j] != g[x.fi][x.se]) continue;
			was[i][j] = 1;
			res[i][j] = sym[t];
			q[r++] = mp (i, j);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!res[i][j]) {
				printf ("INVALID\n");
				re 0;
			}
	printf ("VALID\n");
	for (int i = 0; i < n; i++) {
		res[i][n] = '\0';
		printf ("%s\n", res[i]);
	}
	re 0;
}