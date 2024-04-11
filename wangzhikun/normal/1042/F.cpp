#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(a) int((a).size())

const int N = 1000 * 1000 + 13;

int n, k;
vector<int> g[N];
int ans;

int dfs(int v, int p = -1){
	if (g[v].size() == 1)
		return 0;
	vector<int> cur;
	for (auto u : g[v]){
		if (u == p) continue;
		cur.push_back(dfs(u, v) + 1);
	}
	sort(cur.begin(), cur.end());
	
	while (sz(cur) >= 2){
		if (cur.back() + cur[sz(cur) - 2] <= k) break;
		++ans;
		cur.pop_back();
	}
	
	return cur.back();
}

int v, u;
int main(){
	scanf("%d%d", &n, &k);
	forn(i, n - 1){
		scanf("%d%d", &v, &u);--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	forn(i, n){
		if (sz(g[i]) > 1){
			dfs(i);
			break;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}