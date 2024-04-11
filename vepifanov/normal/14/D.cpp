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

int n;
int m, res, w;
int was[2][200], use[200], g[200][200], p[200][200];
vector<int> v[200];

int go (int a, int b) {
	use[a] = use[b] = 1;
	if (g[a][b] > 1) {
		go (a, p[a][b]);
		go (p[a][b], b);
	}
}

int dfs (int t, int x, int l) {
	if (l > res) { res = l; w = x; }
	was[t][x] = 1;
	for (int i = 0; i < v[x].size (); i++)
		if (!use[v[x][i]] && !was[t][v[x][i]])
			dfs (t, v[x][i], l + 1);
	return 0;
}

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = 1e9 * int (i != j);
	for (int i = 0; i + 1 < n; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].push_back (b);
		v[b].push_back (a);
		g[a][b] = g[b][a] = 1;
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i != j && g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = g[i][k] + g[k][j];
					p[i][j] = k;
				}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			memset (use, 0, sizeof (use));
			go (i, j);
			memset (was, 0, sizeof (was));
			for (int k = 0; k < n; k++)
				if (!was[0][k] && !use[k]) {
					res = -1; w = 0;
					dfs (0, k, 0);
					res = -1;
					dfs (1, w, 0);
					if (res * g[i][j] > ans) ans = res * g[i][j];
				}
		}	
	printf ("%d\n", ans);
	return 0;
}