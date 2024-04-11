#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <functional>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> col(n);
	for (int &x : col) cin >> x;
	vector<vector<int>> g(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		if (col[i] == 1) {
			res[i] = 1;
			for (int y: g[i]) {
				res[y] = 1;
			}
		}
	}

	vector<int> cntBlack(n, -1);
	vector<int> pred(n, -1);
	function<void(int, int)> dfs = [&](int x, int px) -> void {
		pred[x] = px;
		cntBlack[x] = (col[x] == 1);
		for (int &y : g[x]) {
			if (y != px) {
				dfs(y, x);
				cntBlack[x] += cntBlack[y];
			}
		}
	};
	dfs(0, -1);

	auto calcBlack = [&](int x, int y) -> int {
		if (y == pred[x]) {
			return cntBlack[0] - cntBlack[x];
		} else {
			return cntBlack[y];
		}
	};

	vector<int> was(n);
	function<void(int, int)> dfs2 = [&](int x, int px) -> void {
		if (was[x]) return;
		was[x] = 1;
		res[x] = 1;
		for (int &y : g[x]) {
			if ((y != px) && (calcBlack(y, x) > 1)) {
				dfs2(y, x);
			}
		}
	};
	for (int i = 0; i < n; i++) {
		if (res[i] == 1) dfs2(i, -1);
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}