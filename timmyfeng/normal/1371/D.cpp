#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		int cnt = 0;
		vector<string> grid(n, string(n, '0'));
		for (int i = 0; i < n && cnt < k; ++i) {
			for (int j = 0; j < n && cnt < k; ++j) {
				grid[j][(i + j) % n] = '1';
				++cnt;
			}
		}

		cout << (k % n ? 2 : 0) << "\n";
		for (auto& i : grid) {
			cout << i << "\n";
		}
	}
}