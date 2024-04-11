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
char g[51][51];
int was[51][51];
ii q[51 * 51];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf (" %s", g[i]);
		int ok = 1;
		for (int i = 0; i < n && ok; i++)
			for (int j = 0; j < m && ok; j++)
				if (g[i][j] == 'B') {
					for (int t = 0; t < 4; t++) {
						int ni = i + int (t == 0) - int (t == 1);
						int nj = j + int (t == 2) - int (t == 3);
						if (ni < 0 || nj < 0 || ni >= n || nj >= m || g[ni][nj] == 'B') continue;
						if (g[ni][nj] == 'G') ok = 0; else g[ni][nj] = '#';
					}
				}
		if (ok) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					was[i][j] = 0;
		    if (g[n - 1][m - 1] != '#') {
				int l = 0, r = 1;
				q[0] = mp (n - 1, m - 1);
				was[n - 1][m - 1] = 1;
				while (l < r) {
					int i = q[l].fi;
					int j = q[l].se;
					l++;
					for (int t = 0; t < 4; t++) {
						int ni = i + int (t == 0) - int (t == 1);
						int nj = j + int (t == 2) - int (t == 3);
						if (ni < 0 || nj < 0 || ni >= n || nj >= m || g[ni][nj] == '#' || was[ni][nj]) continue;
						was[ni][nj] = 1;
						q[r++] = mp (ni, nj);
					}
				}
			}
			for (int i = 0; i < n && ok; i++)
				for (int j = 0; j < m && ok; j++)
					if (g[i][j] == 'G' && !was[i][j])
						ok = 0;
		}
		printf ("%s\n", ok ? "Yes" : "No");
	}
	re 0;
}