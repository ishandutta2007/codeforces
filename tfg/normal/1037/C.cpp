#include <iostream>
#include <cstdio>
#include <vector>

const int ms = 1001000;
const int INF = 1e8;

char a[ms], b[ms];

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	scanf(" %s", a);
	scanf(" %s", b);
	int dp[2] = {INF, INF};
	dp[a[0] - '0'] = 0;
	for(int i = 0; i + 1 < n; i++) {
		//std::cout << "on " << i << " got (" << dp[0] << ", " << dp[1] << ")\n";
		int nxt[2] = {INF, INF};
		if(b[i] == '0') {
			if(i < n && a[i + 1] == '0') {
				nxt[0] = std::min(nxt[0], dp[0] + 1);
				nxt[1] = std::min(nxt[1], dp[1] + 1);
			}
			if(i < n) {
				nxt[a[i + 1] - '0'] = std::min(dp[1] + 1, nxt[a[i + 1] - '0']);
				nxt[a[i + 1] - '0'] = std::min(dp[0], nxt[a[i + 1] - '0']);
			}
		} else {
			if(i < n && a[i + 1] == '1') {
				nxt[0] = std::min(nxt[0], dp[0] + 1);
				nxt[1] = std::min(nxt[1], dp[1] + 1);
			}
			if(i < n) {
				nxt[a[i + 1] - '0'] = std::min(dp[0] + 1, nxt[a[i + 1] - '0']);
				nxt[a[i + 1] - '0'] = std::min(dp[1], nxt[a[i + 1] - '0']);
			}
		}
		dp[0] = nxt[0];
		dp[1] = nxt[1];
	}
	int want = b[n - 1] - '0';
	std::cout << std::min(dp[want], dp[want^1] + 1) << std::endl;
}