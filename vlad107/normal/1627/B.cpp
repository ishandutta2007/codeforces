#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calc(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> cost;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int curCost = max(
					max(calc(i, j, 0, 0), calc(i, j, 0, m - 1)),
					max(calc(i, j, n - 1, 0), calc(i, j, n - 1, m - 1))
				);
				cost.push_back(curCost);

			}
		}
		sort(cost.begin(), cost.end());
		for (int i : cost) cout << i << " ";
		cout << "\n";
	}
	return 0;
}