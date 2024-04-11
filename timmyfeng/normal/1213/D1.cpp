#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> cost(2e5 + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cost[a].push_back(0);
		int stp = 0;
		while (a) {
			a /= 2;
			cost[a].push_back(++stp);
		}
	}

	int ans = 1e9;
	for (auto& i : cost) {
		if ((int)i.size() >= k) {
			sort(i.begin(), i.end());
			int sum = 0;
			for (int j = 0; j < k; ++j) {
				sum += i[j];
			}
			ans = min(sum, ans);
		}
	}
	cout << ans << '\n';
}