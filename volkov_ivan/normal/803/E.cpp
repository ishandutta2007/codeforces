#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	string mask;
	cin >> n >> k >> mask;
	bool dp[n + 1][2 * k + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 2 * k; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][k] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 2 * k; j++) {
			if (mask[i - 1] == 'D' && j > 0 && j <= 2 * k) {
				dp[i][j] = dp[i - 1][j];
			}
			if (mask[i - 1] == 'W' && j > 1) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			if (mask[i - 1] == 'L' && j < 2 * k - 1) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			if (mask[i - 1] == '?') {
				dp[i][j] = (j > 0 && j < 2 * k) ? dp[i - 1][j] : 0;
				dp[i][j] |= j > 1 ? dp[i - 1][j - 1] : 0;
				dp[i][j] |= j < 2 * k - 1 ? dp[i - 1][j + 1] : 0;
			}
		}
	}
	vector <char> ans;
	if (!(dp[n][0] | dp[n][2 * k])) {
		cout << "NO" << endl;
		return 0;
	}
	int j = dp[n][0] ? 0 : 2 * k;
	for (int i = n; i > 0; i--) {
		if (mask[i - 1] != '?') {
			ans.push_back(mask[i - 1]);
			if (mask[i - 1] == 'W') {
				j--;
			}
			if (mask[i - 1] == 'L') {
				j++;
			}
			continue;
		}
		if (j > 1 && dp[i - 1][j - 1]) {
			ans.push_back('W');
			j--;
			continue;
		}
		if (j < 2 * k - 1 && dp[i - 1][j + 1]) {
			ans.push_back('L');
			j++;
			continue;
		}
		ans.push_back('D');
	}
	for (int i = n - 1; i >= 0; i--) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}