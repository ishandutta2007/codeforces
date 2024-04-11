#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n, r = 0;
int m, k;
int io[2][1000], w[2][1000][1000], g[2][1000][1000], e[2][1000], u[2][1000][1000];
deque<pair<int, ii> > all;
vii v[1000];
map<string, int> st;

int get (string s) {
	if (st.count (s)) re st[s];
	st[s] = r++;
	re r - 1;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		v[a].pb (mp (b, i));
		v[b].pb (mp (a, i));
		io[0][i] = io[1][i] = 0;
	}
	for (int t = 0; t < 2; t++) {
		all.clear ();
		for (int i = 0; i < k; i++) {
			string s;
			cin >> s;
			int k = get (s), x, y, z;
			cin >> x >> y; x--;
			g[t][k][x] = 1;
			for (int j = 0; j < y; j++) {
				cin >> z; z--;
				e[t][z] = k;
				w[t][k][z] = 1;
			}
			all.pb (mp (0, mp (k, x)));
		}
		while (!all.empty ()) {
			int T = all.front ().fi;
			int x = all.front ().se.fi;
			int y = all.front ().se.se;
//			printf ("%d %d %d\n", T, x, y);
			all.pop_front ();
			if (T == 0) {
				for (int i = 0; i < sz (v[y]); i++) {
					int j = v[y][i].fi;
					int k = v[y][i].se;
					if (w[t][x][k] && !io[t][k]) {
						io[t][k] = 1;
						all.pb (mp (1, mp (y, j)));
					} else
					if (io[t][k] && !g[t][x][j]) {
						g[t][x][j] = 1;
						all.pb (mp (0, mp (x, j)));
					}
				}
			} else {
				for (int i = 0; i < k; i++) {
					if (g[t][i][x] && !g[t][i][y]) {
						g[t][i][y] = 1;
						all.pb (mp (0, mp (i, y)));
					}
					if (g[t][i][y] && !g[t][i][x]) {
						g[t][i][x] = 1;
						all.pb (mp (0, mp (i, x)));
					}
				}
			}
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (g[t][e[t][i]][j])
					u[t][i][j] = 1;
	}
	int ok = 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			ok &= int (u[0][i][j] == u[1][i][j]);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			ok &= int (g[0][i][j] == g[1][i][j]);
	if (ok) printf ("YES\n"); else printf ("NO\n");
	return 0;
}