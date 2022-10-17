#include <cstdio>
#include <map>
#include <vector>

const int md = 998244353;

inline int add(int a, int b) {
	return a + b < md ? a + b : a + b - md;
}

const int N = 1000;
int t, n, m, a[N], ord[N], last[N];
bool u[N];
std::vector<int> g[N];
std::map<int, int> mp[N];

int take(int x) {
	return std::min(x, 1070000000);
}

int dt;
void dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) if (!u[g[v][i]]) dfs(g[v][i]);
	ord[dt++] = v;
}

void add(int id, int l, int len, int lenmd) {
	std::map<int, int>::iterator it = mp[id].upper_bound(l);
	if (it != mp[id].begin() && (--it, it->first + it->second >= l)) {
		if (next(it) == mp[id].end()) last[id] = add(last[id], lenmd);
		lenmd = add(lenmd, it->second);
		it->second = take(it->second + len);
	} else {
		it = mp[id].insert(std::make_pair(l, len)).first;
		if (next(it) == mp[id].end()) last[id] = lenmd;
	}
	while (next(it) != mp[id].end() && next(it)->first <= it->first + it->second) {
		if (next(next(it)) == mp[id].end()) last[id] = add(last[id], lenmd);
		lenmd = add(lenmd, next(it)->second);
		it->second = take(it->second + next(it)->second);
		mp[id].erase(next(it));
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			g[i].clear();
			u[i] = 0;
			last[i] = 0;
			mp[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			g[a - 1].push_back(b - 1);
		}
		dt = 0;
		for (int i = 0; i < n; ++i) if (!u[i]) dfs(i);
		for (int i = n - 1; i >= 0; --i) {
			int id = ord[i];
			if (a[id]) add(id, 0, a[id], a[id] % md);
			for (int j = 0; j < (int)g[id].size(); ++j) for (std::map<int, int>::iterator it = mp[id].begin(); it != mp[id].end(); ++it) add(g[id][j], it->first + 1, it->second, next(it) == mp[id].end() ? last[id] : it->second);
		}
		int id = ord[0];
		printf("%d\n", mp[id].empty() ? 0 : add((--mp[id].end())->first, last[id]));
	}
	return 0;
}