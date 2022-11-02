#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>

using namespace std;

const int MIN_INT = numeric_limits<int>::min();

vector<int> solve(const int &n, vector<vector<int>> &g) {
	vector<int> depth(n);
	vector<int> pred(n);

	function<void(int, int)> dfs = [&](int x, int px) {
		depth[x] = 0;
		pred[x] = px;

		for (int &y : g[x]) {
			if (y == px) continue;
			dfs(y, x);

			depth[x] = max(depth[x], depth[y] + 1);
		}
	};
	dfs(0, -1);

	vector<pair<int, int>> maxDepth(n), maxDepth2(n);
	for (int x = 0; x < n; x++) {
		maxDepth[x] = {0, x};
		maxDepth2[x] = {0, x};
		for (int y : g[x]) {
			if (y == pred[x]) continue;
			if (depth[y] + 1 >= maxDepth[x].first) {
				maxDepth2[x] = maxDepth[x];
				maxDepth[x] = {depth[y] + 1, y};
			} else if (depth[y] + 1 > maxDepth2[x].first) {
				maxDepth2[x] = {depth[y] + 1, y};
			}
		}
	}

	vector<int> path;
	for (int x = 0; ; x = maxDepth[x].second) {
		path.push_back(x);
		if (depth[x] == 0) break;
	}

	vector<int> pref(path.size()), b(path.size());
	for (int i = 1; i < path.size(); i++) {
		pref[i] = pref[i - 1];
		int dUp;
		if (maxDepth[path[i - 1]].second == path[i]) {
			dUp = maxDepth2[path[i - 1]].first;
		} else {
			dUp = maxDepth[path[i - 1]].first;
		}
		pref[i] = max(pref[i], dUp + i - 1);
		b[i] = dUp - (i - 1);
	}

	int LG = 0;
	while ((1<<LG) <= path.size()) ++LG;

	vector<vector<int>> jump(path.size(), vector<int>(LG, MIN_INT));
	for (int i = 0; i < path.size(); i++) {
		jump[i][0] = b[i];
		int curI = i;
		for (int j = 1; j < LG; j++) {
			jump[i][j] = jump[i][j - 1];
			int lenJ = (1<<(j-1));
			if (i >= lenJ) {
				jump[i][j] = max(jump[i][j], jump[i - lenJ][j - 1]);
			}
		}
	}

	auto check = [&](int L, int cost) -> bool {
		if (L < cost) {
			return false;
		}
		int y = path.size() - 1 - (L - cost);
		int k = max((y - cost) / 2, 0);
		int maxB = MIN_INT;
		int curY = y;
		for (int j = LG - 1; j >= 0; j--) {
			int lenJ = (1<<j);
			if (lenJ <= k) {
				maxB = max(maxB, jump[curY][j]);
				curY -= lenJ;
				k -= lenJ;
			}
		}
		if (k != 0) {
			throw "";
		}
		int res = max(maxB + y + cost, pref[curY]);
		return res <= L;
	};
	int L = 1;
	vector<int> res(n);
	for (int x = 1; x <= n; x++) {
		if (x >= path.size() - 1) {
			res[x - 1] = path.size() - 1;
		} else {
			while (!check(L, x)) ++L;
			res[x - 1] = L;
		}
	}
	return res;
}

vector<int> slowSolve(int n, vector<vector<int>> &g) {
	vector<int> res(n);
	for (int cost = 1; cost <= n; cost++) {
		res[cost - 1] = numeric_limits<int>::max();
		for (int i = 0; i < 1; i++) {
			for (int j = i + 1; j < n; j++) {
				vector<int> dist(n, numeric_limits<int>::max());
				dist[0] = 0;
				function<void(int, int)> dfs = [&](int x, int px) {
					for (int y : g[x]) {
						if (y == px) continue;
						if (dist[x] + 1 < dist[y]) {
							dist[y] = dist[x] + 1;
							dfs(y, x);
						}
					}
				};
				dfs(0, -1);
				if (cost < dist[j]) {
					dist[j] = cost;
					dfs(j, 0);
				}
				int maxDist = numeric_limits<int>::min();
				for (int i = 0; i < n; i++) {
					if (dist[i] > maxDist) maxDist = dist[i];
				}
				res[cost - 1] = min(res[cost - 1], maxDist);
			}
		}
	}
	return res;
}

void stressTest(int n) {
	while (1) {
		vector<vector<int>> g(n);
		vector<pair<int, int>> edges;
		for (int i = 1; i <= n - 1; i++) {
			int prev = rand() % i;
			g[prev].push_back(i);
			g[i].push_back(prev);
			edges.push_back({prev + 1, i + 1});
		}
		auto resSlow = slowSolve(n, g);
		auto res = solve(n, g);
		if (res != resSlow) {
			cout << "correct: ";
			for (int i = 0; i < n; i++) cout << resSlow[i] << " ";
			cout << endl;

			cout << "ans: ";
			for (int i = 0; i < n; i++) cout << res[i] << " ";
			cout << endl;

			cout << n << endl;
			for (int i = 0; i < n - 1; i++) cout << edges[i].first << " " << edges[i].second << endl;
			exit(0);
		} else {
			cout << "ok" << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// stressTest(255);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<vector<int>> g(n);
		g.clear();
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			--x; --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		auto res = solve(n, g);
		for (int &x : res) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}