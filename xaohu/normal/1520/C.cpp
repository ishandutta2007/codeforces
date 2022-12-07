#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)

using namespace std;

int t, n, ans[105][105];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 2) {
			cout << "-1\n";
			continue;
		}
		vector<pair<int, int>> v[2];
		rep(i, 1, n)
			rep(j, 1, n)
				v[(i + j) % 2].emplace_back(i, j);
		int x = 0;
		for (auto z : {0, 1})
			for (auto [a, b] : v[z])
				ans[a][b] = ++x;
		rep(i, 1, n) {
			rep(j, 1, n)
				cout << ans[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}