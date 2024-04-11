#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = 1e6;

vector<int> g[N];
int n, k, a[N], b[N], take[N], sz[N], cnt[N], maxS[N], cntTake;
bool found;

void upd(int &mx1, int &mx2, int x) {
	if (x >= mx1) {
		mx2 = mx1;
		mx1 = x;
	} else if (x > mx2) {
		mx2 = x;
	}
}

void dfs0(int x, int px) {
	sz[x] = 1;
	cnt[x] = take[x];
	int all = 0;
	int mx = 0;
	for (int i = 0; i < (int)g[x].size(); i++) {
		int y = g[x][i];
		if (y != px) {
			dfs0(y, x);
			sz[x] += sz[y];
			cnt[x] += cnt[y];
			if (cnt[y] == sz[y]) {
				all += sz[y];
			} else {
				mx = max(mx, maxS[y]);
			}
		}
	}
	if (take[x]) {
		maxS[x] = 1 + all + mx;
	} else {
		maxS[x] = 0;
	}
}

void dfs1(int x, int px, int pmaxS) {
	if (found) return;
	if (take[x]) {
		int all = 0;
		int mx = 0;
		if (n - sz[x] == cntTake - cnt[x]) {
			all += n - sz[x];
		} else {
			mx = max(mx, pmaxS);
		}
		for (int i = 0; i < (int)g[x].size(); i++) {
			int y = g[x][i];
			if (y != px) {
				if (cnt[y] == sz[y]) {
					all += sz[y];
				} else {
					mx = max(mx, maxS[y]);
				}
			}
		}
		if (1 + all + mx >= k) {
			found = true;
			return;
		}
	}
	int mx1 = 0, mx2 = 0;
	int all = 0;
	if (n - sz[x] == cntTake - cnt[x]) {
		all += n - sz[x];
	} else {
		upd(mx1, mx2, pmaxS);
	}
	for (int i = 0; i < (int)g[x].size(); i++) {
		int y = g[x][i];
		if (y != px) {
			if (sz[y] == cnt[y]) {
				all += sz[y];
			} else {
				upd(mx1, mx2, maxS[y]);				
			}
		}
	}
	for (int i = 0; i < (int)g[x].size(); i++) {
		int y = g[x][i];
		if (y != px) {
			int nall = all;
			int nmx = mx1;
			if (cnt[y] == sz[y]) {
				nall -= sz[y];
			} else {
				if (maxS[y] == mx1) nmx = mx2;
			}
			int nmS = nmx + nall + 1;
			if (!take[x]) nmS = 0;
			dfs1(y, x, nmS);
		}
	}
}

bool ok(int M) {
	cntTake = 0;
	for (int i = 0; i < n; i++) {
		take[i] = (a[i] >= M);
		cntTake += take[i];
	}
	found = false;
	dfs0(0, -1);
	dfs1(0, -1, 0);
	return found;
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	sort(b, b + n);
	int m = unique(b, b + n) - b;
	int ll = 0, rr = m;
	while (ll < rr - 1) {
		int mid = (ll+rr)/2;
		// cerr << mid << endl;
		if (ok(b[mid])) {
			ll = mid;
		} else {
			rr = mid;
		}
	}
	cout << b[ll] << endl;
	return 0;
}