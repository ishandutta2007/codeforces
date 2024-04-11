#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 505;
const int INF = 1e8;

// dp for closing both borders
int dp1(int l, int r);
// dp for closing one side
int dp2(int l, int r);

int a[ms];
int memo1[ms][ms];
int memo2[ms][ms];


int dp1(int l, int r) {
	if(r < l) return 0;
	if(l == r) return 1;
	int &ans = memo1[l][r];
	if(ans != -1) return ans;
	if(a[l] == a[r] && dp1(l + 1, r - 1) <= 1) {
		//std::cout << "(" << l << ", " << r << ") is palindrome " << std::endl;
		return ans = 1;
	}
	ans = INF;
	if(a[l] == a[r]) {
		ans = std::min(ans, dp1(l + 1, r - 1));
	}
	for(int i = l; i < r; i++) {
		ans = std::min(ans, dp1(l, i) + dp1(i + 1, r));
	}
	//std::cout << "dp1(" << l << ", " << r << ") = " << ans << std::endl;
	return ans;
}

int dp2(int l, int r) {
	if(r < l) return 0;
	if(l == r) return 0;
	int &ans = memo2[l][r];
	if(ans != -1) return ans;
	ans = INF;
	for(int i = l; i < r; i++) {
		if(dp1(l, i) == 1) {
			ans = std::min(ans, dp1(i + 1, r));
		}
	}
	for(int i = r; i > l; i--) {
		if(dp1(i, r) == 1) {
			ans = std::min(ans, dp1(l, i - 1));
		}
	}
	//std::cout << "dp2(" << l << ", " << r << ") = " << ans << std::endl;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	memset(memo1, -1, sizeof memo1);
	memset(memo2, -1, sizeof memo2);
	std::cout << dp1(0, n - 1) << std::endl;
}