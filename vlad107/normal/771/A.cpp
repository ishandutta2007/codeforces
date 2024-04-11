#include <functional>
#include <iostream>
#include <cmath>
#include <vector>
#include <memory.h>
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

const int N = 5e5;

bool used[N];
vector<int> g[N];
int n, m;

pair<int, int> dfs(int x) {
	used[x] = 1;
	pair<int, int> res = {1, (int)g[x].size()};
	for (int y : g[x]) {
		if (used[y]) continue;
		auto cr = dfs(y);
		res = {res.first + cr.first, res.second + cr.second};
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	set<pair<int, int>> ee;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		if (ee.find({x, y}) != ee.end()) continue;
		ee.insert({x, y});
		ee.insert({y, x});
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		pair<int, int> ff = dfs(i);
		long long cnt = ff.first * 1LL * (ff.first - 1);
		if (cnt != ff.second) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}