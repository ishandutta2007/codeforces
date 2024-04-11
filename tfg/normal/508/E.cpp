#include <iostream>
#include <vector>
#include <bitset>

const int ms = 600 + 1;

std::bitset<ms> dp[ms], dp2[ms], mask[ms];
std::string ans;

void dfs(int l, int r, int idx = 0) {
	if(l >= r) {
		return;
	}
	if(dp[l + 1][r] && mask[l][r]) {
		ans[idx] = '(';
		ans[idx + 2 * (r - l) - 1] = ')';
		dfs(l + 1, r, idx + 1);
		return;
	}
	for(int i = l + 1; i < r; i++) {
		if(mask[l][i] && dp[l][i] && dp[i][r]) {
			dfs(l, i, idx);
			dfs(i, r, idx + (i - l) * 2);
			return;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> l(n);
	std::vector<int> r(n);
	for(int i = 0; i < n; i++) {
		std::cin >> l[i] >> r[i];
		dp[i][i] = dp2[i][i] = true;
		for(int j = 1; i + j <= n; j++) {
			mask[i][i + j] = l[i] <= 2 * j - 1 && 2 * j - 1 <= r[i];
		}
		if(l[i] == 1) {
			//dp[i][i + 1] = dp2[i + 1][n - i] = true;
		}
		for(int j = 0; j <= n; j++) {
			//std::cout << mask[i][j] << (j == n ? '\n' : ' ');
		}
	}
	dp[n][n] = dp2[n][n] = true;
	//std::cout << "--------------------------\n";
	for(int len = 1; len <= n; len++) {
		for(int i = 0; i + len <= n; i++) {
			bool got = false;
			got = got || (l[i] <= 2 * len - 1 && 2 * len - 1 <= r[i] && dp[i + 1][i + len]);
			got = got || (dp[i] & dp2[i + len] & mask[i]).count() > 0;
			//std::cout << "on [" << i << ", " << i + len << ") uses " << i << " and " << n - i - len << " got " << got << std::endl;
			if(got) {
				dp[i][i + len] = dp2[i + len][i] = true;
			}
		}
	}
	/*for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			std::cout << dp[i][j] << (j == n ? '\n' : ' ');
		}
	}
	std::cout << "--------------------------\n";
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			std::cout << dp2[i][j] << (j == n ? '\n' : ' ');
		}
	}*/
	if(dp[0][n]) {
		ans = std::string(2 * n, '.');
		dfs(0, n);
		std::cout << ans << std::endl;
	} else {
		std::cout << "IMPOSSIBLE\n";
	}
}