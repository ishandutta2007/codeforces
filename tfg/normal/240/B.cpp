#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 203;
const int mv = 40400;
const int INF = 1e9;

int n;
int a[ms];
int memo[ms][mv][2];

int dp(int on, int A, int B, int last) {
	if(A < 0 || B < 0) return INF;
	if(on > n) return 0;
	int &ans = memo[on][A][last];
	if(ans != -1) return ans;
	return ans = std::min(dp(on+1, A, B-a[on], 1) + (last == 0 ? std::min(a[on], a[on-1]) : 0), dp(on+1, A-a[on], B, 0) + (last == 1 ? std::min(a[on], a[on-1]) : 0));
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	memset(memo, -1, sizeof memo);
	std::cin >> n;
	int A, B;
	std::cin >> A >> B;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int ans = dp(1, A, B, 0);
	if(ans >= INF) ans = -1;
	std::cout << ans << '\n';
}