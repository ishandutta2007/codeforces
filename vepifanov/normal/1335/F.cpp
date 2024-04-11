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

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int n;
int m;
char h[1000010];
int g[1000010];
int w[1000010];
int was[1000010];
int d[1000010];
int cyc[1000010];
int pos[1000010];
int col[1000010];
set<int> all[1000010];

int get (char c) {
	re int (c == 'D') * 0 +
	   int (c == 'R') * 1 +
	   int (c == 'U') * 2 +
	   int (c == 'L') * 3;
}

int r = 0;
int ans = 0;

int go (int i, int j, int len) {
//	printf ("%d %d %d %d\n", i, j, len, g[i * m + j]);
	d[i * m + j] = len;
	was[i * m + j] = 1;
	int ni = i + di[g[i * m + j]];
	int nj = j + dj[g[i * m + j]];
	if (was[ni * m + nj] == 1) {
		col[i * m + j] = r;
		pos[i * m + j] = 0;
		cyc[r] = len - d[ni * m + nj] + 1;
		all[r].clear ();
		r++;
		ans += len - d[ni * m + nj] + 1;
	} else {
		if (!was[ni * m + nj]) go (ni, nj, len + 1);
		col[i * m + j] = col[ni * m + nj];
		pos[i * m + j] = (pos[ni * m + nj] + 1) % cyc[col[i * m + j]];
	}
	if (w[i * m + j]) all[col[i * m + j]].insert (pos[i * m + j]);
	was[i * m + j] = 2;
	re 0;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf ("%s", h);
			for (int j = 0; j < m; j++)
				w[i * m + j] = 1 - (h[j] - '0');
		}
		for (int i = 0; i < n; i++) {
			scanf ("%s", h);
			for (int j = 0; j < m; j++)
				g[i * m + j] = get (h[j]);
		}
		for (int i = 0; i < n * m; i++) was[i] = 0;
		r = ans = 0;
		for (int i = 0; i < n * m; i++)
			if (!was[i])
				go (i / m, i % m, 0);
		int cnt = 0;
		for (int i = 0; i < r; i++) cnt += sz (all[i]);
		printf ("%d %d\n", ans, cnt);
	}
	re 0;
}