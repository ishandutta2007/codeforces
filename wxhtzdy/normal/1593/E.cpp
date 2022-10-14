#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int N = 400005;

int n, k;
int dep[N];
int cnt[N];
int deg[N];
vector<int> g[N];
bool was[N];

//void dfs(int u, int p) {
//	bool leaf = true;
//	was[u] = true;
//	if (g[u].size() <= 1) {
//		dep[u] = 0;
//	} else {
//		dep[u] = 1e9;
//	}
//	for (int v : g[u]) {
//		dep[u] = min(dep[u], dep[v] + 1);
//		if (v == p) {
//			continue;
//		}
//		dfs(v, u);
//		leaf = false;
//	}
//	if (leaf) {
//		dep[u] = 0;
//	}
//}

int main()
{
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) g[i].clear(), was[i] = false, cnt[i] = 0;
		cnt[n] = 0;
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			g[u].pb(v);
			g[v].pb(u);
		}
		for (int i = 0; i < n; i++) {
			deg[i] = g[i].size();
		}
		/*for (int i = 0; i < n; i++) {
			if (!was[i]) {
				dfs(i, i);
			}
		}*/
		deque<int> leaf;
		for (int i = 0; i < n; i++) {
			if (g[i].size() <= 1) {
				leaf.pb(i);
			}
		}
		int ans = 0;
		while (!leaf.empty()) {
			int u = leaf[0];
			leaf.pop_front();
			if (cnt[u] >= k) break;
			ans++;
			for (int v : g[u]) {
				deg[v]--;
				if (deg[v] == 1) {
					cnt[v] = cnt[u] + 1;
					leaf.pb(v);
				}
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}