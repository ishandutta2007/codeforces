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
int m, r = 0, t;
int was[2000], cmp[2000], cnt[2000], res[2000], e[2000], leaf[2000];
int g[2000][2000], w[2000][2000];
vi v[2000], vv[2000];
vi q;

int go (int x) {
	was[x] = 1;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i];
		if (!was[y]) {
			g[x][y] = 2;
			go (y);
		}
	}
	q.pb (x);
	re 0;
}

int go2 (int x, int k) {
	was[x] = 1;
	cmp[x] = k;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i];
		if (!was[y] && g[x][y] == 1) go2 (y, k);
	}
	re 0;
}

int go3 (int x, int p) {
	int il = 1;
	leaf[x] = 0;
	cnt[x] = 1;
	for (int i = 0; i < sz (vv[x]); i++) {
		int y = vv[x][i];
		if (y != p) {
			go3 (y, x);
			cnt[x] += cnt[y];
			leaf[x] += leaf[y];
			il = 0;
		}
	}
	leaf[x] += il;
	int cur = cnt[x] - leaf[x];
	for (int i = 0; i < sz (vv[x]); i++) {
		int y = vv[x][i];
		if (y != p) {
			int tmp = res[y] + (cnt[x] - leaf[x]) - (cnt[y] - leaf[y]) - 1;
			cur = min (cur, tmp);
		}
	}
	res[x] = cur;
	re cur;
}

int go4 (int x, int p) {
	was[x] = 1;
	for (int i = 0; i < sz (vv[x]); i++) {
		int y = vv[x][i];
		if (y != p) go4 (y, x);
	}
	if (sz (vv[x]) < 2) e[t++] = x;
	re 0;
}

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
		g[a][b] = g[b][a] = 1;
	}
	memset (was, 0, sizeof (was));
	for (int i = 0; i < n; i++)
		if (!was[i])
			go (i);
	memset (was, 0, sizeof (was));
	reverse (all (q));
	for (int i = 0; i < n; i++) 
		if (!was[q[i]]) {
			go2 (q[i], r);
			r++;
		}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (cmp[i] != cmp[j] && g[i][j] && !w[cmp[i]][cmp[j]]) {
				vv[cmp[i]].pb (cmp[j]);
				vv[cmp[j]].pb (cmp[i]);
				w[cmp[i]][cmp[j]] = w[cmp[j]][cmp[i]] = 1;
			}
	int ans = n - r;
	memset (was, 0, sizeof (was));
	for (int i = 0; i < r; i++)
		if (!was[i]) {
			t = 0;
			go4 (i, i);
			int tmp = n;
			for (int j = 0; j < t; j++) {
				int tmp2 = go3 (e[j], e[j]);
				tmp = min (tmp, tmp2);
			}
			ans += tmp + 1;
		}
	printf ("%d\n", ans - 1);
	return 0;
}