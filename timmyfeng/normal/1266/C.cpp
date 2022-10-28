#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	if (r == 1 && c == 1) {
		cout << 0 << "\n";
	} else if (c == 1) {
		for (int i = 1; i <= r; ++i) {
			cout << i + 1 << "\n";
		}
	} else {
		vector<vector<int>> ans(r, vector<int>(c, 1));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				ans[i][j] = ans[i][j] * (i + 1) / __gcd(ans[i][j], i + 1);
			}
		}
		for (int i = 0; i < c; ++i) {
			for (int j = 0; j < r; ++j) {
				ans[j][i] = ans[j][i] * (i + r + 1) / __gcd(ans[j][i], i + r + 1);
			}
		}
		for (auto& i : ans) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << "\n";
		}
	}
}