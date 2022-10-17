#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>

const int N = 131075;
const int LG = 17;
int t, val, l, r, to[N * LG][2], size, amt[N * LG], same;

std::vector<std::pair<int, int> > dfs(int v, int dep = LG) {
	if (!dep) return std::vector<std::pair<int, int> >(1, std::make_pair(0, 0));
	--dep;
	std::vector<std::pair<int, int> > vec[2];
	if (to[v][0]) vec[0] = dfs(to[v][0], dep);
	if (to[v][1]) vec[1] = dfs(to[v][1], dep);
	std::vector<std::pair<int, int> > res;
	for (int t = 0; t < 2; ++t) {
		if (dep <= same || t == ((l ^ val) >> dep & 1)) {
			if (vec[0].empty()) {
				for (int i = 0; i < (int)vec[1].size(); ++i) {
					res.push_back(vec[1][i]);
					res.back().first |= 1 << dep;
					if (t) res.back().second |= 1 << dep;
				}
			} else {
				for (int i = 0; i < (int)vec[0].size(); ++i) {
					if (vec[1].empty()) {
						res.push_back(vec[0][i]);
						if (t) res.back().second |= 1 << dep;
					} else if (vec[0][i].first + amt[to[v][t]] >> dep & 1) {
						int p = std::lower_bound(vec[1].begin(), vec[1].end(), std::make_pair(vec[0][i].first + amt[to[v][t]] & ~(1 << dep), vec[0][i].second)) - vec[1].begin();
						if (p < (int)vec[1].size() && vec[1][p].first == (vec[0][i].first + amt[to[v][t]] & ~(1 << dep)) && vec[1][p].second == vec[0][i].second) {
							res.push_back(vec[0][i]);
							if (t) res.back().second |= 1 << dep;
						}
					}
				}
			}
		}
		std::swap(vec[0], vec[1]);
	}
	std::sort(res.begin(), res.end());
	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &l, &r);
		size = 1;
		for (int i = 0; i <= r - l; ++i) {
			int x;
			scanf("%d", &x);
			val = x;
			int cur = 0;
			for (int j = LG - 1; j >= 0; --j) {
				if (!to[cur][x >> j & 1]) to[cur][x >> j & 1] = size++;
				cur = to[cur][x >> j & 1];
				++amt[cur];
			}
		}
		for (same = LG - 1; same >= 0 && (l ^ r) >> same & 1 ^ 1; --same);
		std::vector<std::pair<int, int> > vec = dfs(0);
		int i;
		for (i = 0; i < (int)vec.size() && vec[i].first != l; ++i);
		assert(i < (int)vec.size());
		printf("%d\n", vec[i].second);
		for (int i = 0; i < size; ++i) to[i][0] = to[i][1] = amt[i] = 0;
	}
	return 0;
}