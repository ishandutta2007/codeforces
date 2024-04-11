#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			++a[x];
		}
		for (int i = 1; i <= n; i++) {
			a[i] += a[i - 1];
		}

		vector<int> pwPos;
		int sz = 1;
		for (; sz <= n; sz *= 2) pwPos.push_back(0);

		vector<int> cost(sz + 1);
		for (int i = sz; i > 0; i--) {
			if ((i & (i - 1)) == 0) {
				cost[i] = 0;
			} else {
				cost[i] = cost[i + 1] + 1;
			}
		}
		cost[0] = 1;

		int ans = 6 * n;
		for (int x = 0; x <= n; x++) {
			int sz = 1;
			for (int &p : pwPos) {
				// [0; x]
				// [x + 1; p]
				// [p + 1; n]
				while ((p + 1 <= n) && (sz >= a[p + 1] - a[x])) ++p;
				int curCost = cost[a[x]] + cost[a[p] - a[x]] + cost[a[n] - a[p]];
				ans = min(ans, curCost);
				sz *= 2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}