#include <bits/stdc++.h>

using namespace std;

const int maxn = 1015;

int n,k,dep[maxn];
vector<int> to[maxn],ans,ans2;
int vis[maxn];
int cur=0;

void dfs(int u) {
	cur++;
	ans.push_back(u);
	vis[u]++;
	for (auto v: to[u]) if (cur < k) {
		dfs(v);
		ans.push_back(u);
		vis[u]++;
	}
}

void clear() {
	cur = 0;
	for (int i = 1; i <= n; i++) {
		to[i].clear(); 
		vis[i] = 0;
	}
	ans.clear();
	ans2.clear();
}

void solve() {
	scanf("%d%d",&n,&k);
	for (int i = 2; i <= n; i++) {
		int fa;
		scanf("%d",&fa);
		to[fa].push_back(i);
		dep[i] = 0;
	}
	dep[1] = 0;

	for (int i = n; i>=1; i--) {
		sort(to[i].begin(), to[i].end(), [&](int x, int y) { return dep[x] > dep[y]; });
		//if (to[i].size() > 0) 
		//dep[i] = dep[ to[i][0] ] + 1;
		for(auto j: to[i]) dep[i] = std::max(dep[i], dep[j] + 1);
	}
	dfs(1);

	auto it = ans.begin();
	while (vis[*it] > 1) it++;
	while (it != ans.end()) {
		ans2.push_back(*it);
		it++;
	}

	reverse(ans2.begin(), ans2.end());
	printf("%d\n",ans2.size() - 1);
	for (auto x: ans2) printf("%d ",x);
	printf("\n");
}

int main() {
	int cs = 0;
	scanf("%d",&cs);
	for (int cc=1; cc<=cs;cc++) {
		solve();
		clear();
	}
	return 0;
}