#include <bits/stdc++.h>
using namespace std;

int ans[10][10];
int cost[10][10][10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				cost[k][i][j] = 1e9;
				for (int a = 0; a < 10; ++a) {
					for (int b = 0; b < 10; ++b) {
						if (a + b == 0) continue;
						if ((a * i + b * j) % 10 == k) {
							cost[k][i][j] = min(cost[k][i][j], a + b - 1);
						}
					}
				}
				if (cost[k][i][j] == 1e9) {
					cost[k][i][j] = -1;
				}
			}
		}
	}

	int prev = 0;
	for (int i = 1; i < s.size(); ++i) {
		int cur = s[i] - '0';
		int delta = (cur - prev + 10) % 10;
		for (int r = 0; r < 10; ++r) {
			for (int c = 0; c < 10; ++c) {
				if (cost[delta][r][c] == -1) {
					ans[r][c] = -1;
				} else {
					if (ans[r][c] != -1) {
						ans[r][c] += cost[delta][r][c];
					}
				}
			}
		}
		prev = cur;
	}

	for (auto& i : ans) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}