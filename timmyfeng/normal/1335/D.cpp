#include <bits/stdc++.h>
using namespace std;

const int ANS[9][2] = {{0, 0}, {1, 3}, {2, 6}, {3, 1}, {4, 4}, {5, 7}, {6, 2}, {7, 5}, {8, 8}};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector<string> grid(9);
		for (auto& i : grid) {
			cin >> i;
		}
		for (auto i : ANS) {
			grid[i[0]][i[1]] = ((grid[i[0]][i[1]] - '1') + 1) % 9 + '1';
		}
		for (auto& i : grid) {
			cout << i << '\n';
		}
	}
}