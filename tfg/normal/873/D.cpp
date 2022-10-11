#include <iostream>

const int ms = 100100;

int dp[ms];
int ans[ms];

int solve(int l, int r, int k) {
	int mid = (l + r) / 2;
	if(k <= 1 || l + 1 == r) {
		return 1;
	}
	if(k == 2) {
		return 1;
	}
	for(int i = 0; i + l < mid && mid + i < r; i++) {
		std::swap(ans[i + l], ans[i + mid]);
	}
	int got = 1;
	got += solve(l, mid, k - 2);
	got += solve(mid, r, k - got);
	return got;
}

int main() {
	dp[1] = 1;
	for(int i = 2; i < ms; i++) {
		int mid = i / 2;
		dp[i] = dp[mid] + dp[i - mid] + 1;
	}
	int n, k;
	std::cin >> n >> k;
	if(dp[n] < k) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		ans[i - 1] = i;
	}
	k -= solve(0, n, k);
	if(k != 0) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}