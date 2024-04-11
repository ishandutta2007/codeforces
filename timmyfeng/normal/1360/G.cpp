#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		if (a * n != b * m || a > m || b > n) {
			cout << "NO" << '\n';
		} else {
			vector<string> grid(n, string(m, '0'));
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			for (int i = 0; i < m; ++i) {
				pq.emplace(0, i);
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < a; ++j) {
					auto [cnt, col] = pq.top();
					pq.pop();
					grid[i][col] = '1';
					pq.emplace(cnt + 1, col);
				}
			}
			cout << "YES" << '\n';
			for (auto& i : grid) {
				cout << i << '\n';
			}
		}
	}
}