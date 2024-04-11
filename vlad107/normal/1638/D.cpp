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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int  n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<bool>> added(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}

	auto getColor = [&](int x, int y) -> int {
		int val = -1;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (a[x + i][y + j] == -1) continue;
				if (val == -1) {
					val = a[x + i][y + j];
				}
				if (val != a[x + i][y + j]) {
					return -1;
				}
			}
		}
		return val;
	};

	stack<pair<int, int>> validMoves;
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			int col = getColor(i, j);
			if (col != -1) {
				validMoves.push({i, j});
				added[i][j] = true;
			}
		}
	}

	vector<tuple<int, int, int>> moves;
	while (!validMoves.empty()) {
		auto [x, y] = validMoves.top();
		validMoves.pop();

		int col = getColor(x, y);
		if (col == -1) {
			continue;
		}
		moves.push_back({x, y, col});
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				a[x + i][y + j] = -1;
			}
		}
		for (int dx = -1; dx < 2; dx++) {
			for (int dy = -1; dy < 2; dy++) {
				int vx = x + dx;
				int vy = y + dy;
				if ((0 <= vx) && (vx + 1 < n) && (0 <= vy) && (vy + 1 < m)) {
					if (!added[vx][vy]) {
						int col = getColor(vx, vy);
						if (col != -1) {
							validMoves.push({vx, vy});
							added[vx][vy] = true;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != -1) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	reverse(moves.begin(), moves.end());
	cout << moves.size() << "\n";
	for (auto &[x, y, col] : moves) {
		cout << x + 1 << " " << y + 1 << " " << col << "\n";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				a[x + i][y + j] = col;
			}
		}
	}

	// for (int i =0 ; i < n; i++) {
	// 	for (int j = 0; j < m; j++) cout << a[i][j] << " ";
	// 	cout << endl;
	// }
	return 0;
}