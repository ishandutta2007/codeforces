#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <sstream>
#include <set>
#include <time.h>
#include <memory.h>
#include <queue>
#include <bitset>
#include <functional>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(a) ((int) (a).size())
#define pb push_back
#define SORT(x) sort(all(x))
#define UNIQUE(x) SORT(x),(x).resize(unique(all(x))-(x).begin())
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef long long ll;

const double pi = acos(-1.0);

ll gcd(ll x, ll y) {
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	if (x < y) swap(x, y);
	while (y) {
		ll t = y;
		y = x % y;
		x = t;
	}
	return x;
}

int add[5012];
vi adj[5012];

bool d[5012];
bool out[5012];

int dfs(int x, int y) {
	int ret = 1;
	REP (i, sz (adj[x]))
		if (adj[x][i] != y)
			ret += dfs(adj[x][i], x);
	return ret;
}

int main () {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	REP (i, n-1) {
		int q, w;
		cin >> q >> w;
		--q, --w;
		adj[q].pb(w);
		adj[w].pb(q);
	}
	REP (i, n) {
		memset(d, 0, sizeof(d));
		d[0] = true;
		REP (j, sz (adj[i])) {
			int cv = dfs(adj[i][j], i);
			FORD (k, n-1, 0)
				if (d[k])
					d[k + cv] = true;
		}			
		REP (j, n+1)
			out[j] |= d[j];
	}
	vpii res;
	FOR (i, 1, n-1)
		if (out[i])
			res.pb(pii(i, n-i-1));
	cout << sz(res) << endl;
	REP (i, sz (res))
		cout << res[i].X << ' ' << res[i].Y << endl;
#ifdef LocalHost
	cout << "--FINISHED--" << endl;
	while (1);
#endif
	return 0;
}