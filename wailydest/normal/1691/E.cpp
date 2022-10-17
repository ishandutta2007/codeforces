#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

const int N = 100000;
int T, n, m, val[N * 2], c[N], l[N], r[N];
bool u[N];

struct tree {
	std::vector<std::vector<int> > vec;
	void add(int l, int r, int x) {
		for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
			if (l & 1) vec[l++].push_back(x);
			if (r & 1) vec[--r].push_back(x);
		}
	}
	void run(int i);
} t[2];

std::set<std::pair<int, int> > st[2];

void dfs(int i) {
	if (u[i]) return;
	u[i] = 1;
	t[!c[i]].run(l[i]);
	t[!c[i]].run(r[i] - 1);
	std::set<std::pair<int, int> >::iterator it;
	while (it = st[!c[i]].lower_bound(std::make_pair(l[i], 0)), it != st[!c[i]].end() && it->first < r[i]) {
		int ind = it->second;
		st[!c[i]].erase(it);
		dfs(ind);
	}
}

void tree::run(int i) {
	for (i += m; i; i >>= 1) {
		while (!vec[i].empty()) {
			int ind = vec[i].back();
			vec[i].pop_back();
			dfs(ind);
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			u[i] = 0;
			scanf("%d%d%d", c + i, l + i, r + i);
			--l[i];
			val[i << 1] = l[i];
			val[i << 1 | 1] = r[i];
		}
		std::sort(val, val + n * 2);
		m = std::unique(val, val + n * 2) - val;
		for (int i = 0; i < 2; ++i) {
			st[i].clear();
			t[i].vec.assign(m * 2, std::vector<int>());
		}
		for (int i = 0; i < n; ++i) {
			l[i] = std::lower_bound(val, val + m, l[i]) - val;
			r[i] = std::lower_bound(val, val + m, r[i]) - val;
			st[c[i]].insert(std::make_pair(l[i], i));
			t[c[i]].add(l[i], r[i], i);
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) if (!u[i]) {
			++ans;
			dfs(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}