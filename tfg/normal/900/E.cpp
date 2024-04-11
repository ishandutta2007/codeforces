#include <iostream>
#include <cstdio>

const int ms = 100100;
const int INF = 1e9;

int n, m;

char buffer[ms];
int count[ms][2];
int dp[ms][2];
int ans[ms][2];

bool match(int i) {
	char x = buffer[i];
	if(x == '?') {
		return true;
	} else if(i % 2 == 1 && x == 'a') {
		return true;
	} else if(i % 2 == 0 && x == 'b') {
		return true;
	} else {
		return false;
	}
}

int cost(int x) {
	if(x < m) {
		//std::cout << "on x died here\n";
		return -1;
	}
	if(count[x][1 - (x - m) % 2] - count[x - m][1 - (x - m) % 2] > 0) {
		//std::cout << "second death, " << count[x][(x - m) % 2] - count[x - m][(x - m) % 2] << '\n';
		return -1;
	}
	return m - (count[x][(x - m) % 2] - count[x - m][(x - m) % 2]);
}

int main() {
	std::cin >> n;
	scanf(" %s", buffer + 1);
	std::cin >> m;
	for(int i = 1; i <= n; i++) {
		//std::cout << buffer[i] << '\n';
		for(int j = 0; j < 2; j++) {
			count[i][j] = count[i - 1][j];
		}
		if(buffer[i] != '?') {
			if(match(i)) {
				//std::cout << "yes\n";
				count[i][0]++;
			} else {
				//std::cout << "not\n";
				count[i][1]++;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][1];
		ans[i][1] = ans[i - 1][1];
		if(cost(i) != -1 && (dp[i][1] < dp[i - m][1] + 1 || (dp[i][1] == dp[i - m][1] + 1 && ans[i][1] > ans[i - m][1] + cost(i)))) {
			dp[i][1] = dp[i - m][1] + 1;
			ans[i][1] = ans[i - m][1] + cost(i);
		}
		//std::cout << "(" << dp[i][0] << ", " << ans[i][0] << "), (" << dp[i][1] << ", " << ans[i][1] << ")\n";
	}
	int tot[2];
	tot[0] = 0;
	tot[1] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 2; j++) {
			if(dp[i][j] > tot[0]) {
				tot[0] = dp[i][j];
				tot[1] = ans[i][j];
			} else if(dp[i][j] == tot[0]) {
				tot[1] = std::min(tot[1], ans[i][j]);
			}
		}
	}
	std::cout << tot[1] << '\n';
}