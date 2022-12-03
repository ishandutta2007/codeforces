#define _CRT_SECURE_NO_DEPRECATE
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) SORT(a),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int n, m, k;
pair <int, pii> a[1024];
int x[1024], y[1024];
vi adj[1024];
int d[1024][1024];
int root;

inline long long sqr (long long x) {
	return x*x;
}

void dfs (int x, int prev, int sum) {
	d[root][x] = sum;
	REP (i, sz (adj[x]))
		if (adj[x][i] != prev)
			dfs (adj[x][i], x, sum+1);
}

int out[1024];

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
	scanf ("%d%d%d", &n, &m, &k);
	REP (i, n)
		scanf ("%d%d", x + i, y + i);
	REP (i, m)
		scanf ("%d%d%d", &a[i].X, &a[i].Y.X, &a[i].Y.Y);
	sort (a, a + m);
	REP (i, m) {
		bool ok = false;
		FOR (j, i+1, m)
			if (sqr(a[j].Y.X-a[i].Y.X) + sqr(a[j].Y.Y-a[i].Y.Y) < sqr (a[j].X)) {
				adj[i].pb (j);
				adj[j].pb (i);
				ok = true;
				break;
			}
		if (!ok) {
			adj[i].pb (m);
			adj[m].pb (i);
		}
	}
	++m;
	for (root = 0; root < m; ++root)
		dfs (root, -1, 0);
	REP (i, n) {
		out[i] = m-1;
		REP (j, m)
			if (sqr (a[j].Y.X - x[i]) + sqr (a[j].Y.Y - y[i]) < sqr (a[j].X)) {
				out[i] = j;
				break;
			}
	}
	int q, w;
	REP (i, k) {
		scanf ("%d%d", &q, &w);
		--q;
		--w;
		printf ("%d\n", d[out[q]][out[w]]);
	}
	return 0;
}