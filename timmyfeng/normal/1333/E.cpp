#include <bits/stdc++.h>
using namespace std;

const int MX = 500;
const int ANS[3][3] = {
	{1, 3, 2},
	{8, 6, 4},
	{7, 5, 9}
};

int ans[MX][MX];
int cur = 0;

void solve(int n, int r, int c) {
	if (n == 3) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				ans[r + i][c + j] = cur + ANS[i][j];
			}
		}
		return;
	}
	for (int i = n - 1; ~i; --i) {
		ans[r][c + i] = ++cur;
	}
	for (int i = n - 1; i; --i) {
		ans[r + i][c] = ++cur;
	}
	solve(n - 1, r + 1, c + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if (n < 3) {
		cout << -1 << '\n';
		return 0;
	}
	solve(n, 0, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}