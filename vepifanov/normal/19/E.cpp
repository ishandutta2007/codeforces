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
int m;
vi ans;
int was[10000], d[10000], be[10000], bs[10000], ge[10000], gs[10000];
vii v[10000];
int bad = 0, last;

int go (int x, int p, int l) {
	was[x] = 1;
	d[x] = l;
	for (int i = 0; i < v[x].size (); i++) {
		int y = v[x][i].first;
		if (y != p && was[y] == 1) if ((d[x] - d[y]) & 1) { gs[y]++; ge[x]++; } else { bs[y]++; be[x]++; bad++; last = v[x][i].second; }
		if (was[y] == 0) go (y, x, l + 1);
	}
	was[x] = 2;
	return 0;
}

int go2 (int x, int p, int *cb, int *cg) {
	was[x] = 1;
	*cb = *cg = 0;
	for (int i = 0; i < v[x].size (); i++) {
		int y = v[x][i].first;
		int k = v[x][i].second;
		if (was[y] == 0) {
			int ncg, ncb;
			go2 (y, k, &ncb, &ncg);
			*cb += ncb;
			*cg += ncg;
		}
	}
	*cg -= gs[x] - ge[x];
	*cb -= bs[x] - be[x];
	if (p != -1 && *cg == 0 && *cb == bad) ans.pb (p);
	return 0;
}

int main() {
//	freopen ("e.in", "r", stdin);
//	freopen ("e.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (mp (b, i));
		v[b].pb (mp (a, i));
	}
	memset (was, 0, sizeof (was));
	for (int i = 0; i < n; i++)
		if (!was[i]) go (i, -1, 0);
	if (bad == 0) {
		printf ("%d\n", m);
		for (int i = 0; i < m; i++) printf ("%d ", i + 1);
		printf ("\n");
		return 0;
	}
	memset (was, 0, sizeof (was));
	int a, b;
	for (int i = 0; i < n; i++)
		if (!was[i]) go2 (i, -1, &a, &b);
	if (bad == 1) ans.pb (last);
	sort (ans.begin (), ans.end ());
	printf ("%d\n", ans.size ());
	for (int i = 0; i < ans.size (); i++) printf ("%d ", ans[i] + 1);
	printf ("\n");
	return 0;
}