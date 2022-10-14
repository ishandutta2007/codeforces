
 #include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll n, m, p[200001], r[200001], sz[200001], spantree[200001], max_edge[200001];
vector<vector<ll>> g;
vector<int> took;
ll ans = 0;
map<int, int> ma;

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int size(int x) {
	return sz[find(x)];
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (r[x] > r[y]) p[y] = x, sz[x] += sz[y];
		else {
			p[x] = y, sz[y] += sz[x];
			if (r[x] == r[y]) r[y]++;
		}
	}
}

bool cmp(vector<ll> &a, vector<ll> &b) {
	return a[2] > b[2];
}

int main() {
	fast;
	cin >> n >> m;
	g.resize(m, vector<ll>(3));
	took.resize(200500, 0);
	for (int i = 0; i < m; i++)
		cin >> g[i][0] >> g[i][1] >> g[i][2];
    for (int i = 1; i <= n; i++) p[i] = i, r[i] = 0, sz[i] = 1;
	sort(g.begin(), g.end(), cmp);
	for (int i = 0; i < m; i++) {
		if (find(g[i][0]) != find(g[i][1])) {
            ll mx1 = max_edge[find(g[i][0])];
            ll mx2 = max_edge[find(g[i][1])];
            ll sp1 = spantree[find(g[i][0])];
            ll sp2 = spantree[find(g[i][1])];
            if (sp1 + sp2 + g[i][2] + max(mx1, mx2) >= mx1+mx2+sp1+sp2) {


                unite(g[i][0], g[i][1]);
                int p = find(g[i][0]);
                spantree[p] = sp1+sp2+g[i][2];
                max_edge[p] = max(mx1, mx2);
            }
		} else {
		    int p = find(g[i][0]);
		    max_edge[p] = max(max_edge[p], g[i][2]);
		}
	}
    ll ans = 0;
	for (int i = 1; i <= n; i++)
		if (!took[find(i)]) {
        int x = find(i);
        took[x] = 1;
        ans += max_edge[x]+spantree[x];
      }
	cout << ans << endl;
}