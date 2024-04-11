#include <bits/stdc++.h>
using namespace std;

const int DR[] = {0, 1, 0, -1};
const int DC[] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> grid(n);
	for (auto& i : grid) {
		cin >> i;
	}

	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			bool ok = (grid[i][j] == '.');
			for (int k = 0; k < 4; ++k) {
				ok &= (grid[i + DR[k]][j + DC[k]] == '.');
			}
			if (ok) {
				grid[i][j] = '#';
				for (int k = 0; k < 4; ++k) {
					grid[i + DR[k]][j + DC[k]] = '#';
				}
			}
		}
	}

	bool ok = true;
	for (auto& i : grid) {
		for (auto j : i) {
			ok &= (j == '#');
		}
	}
	cout << (ok ? "YES" : "NO") << "\n";
}