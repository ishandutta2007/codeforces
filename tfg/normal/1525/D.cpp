#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5050;

int n;
int a[ms];
bool visit[ms][ms];
int memo[ms][ms];
int dp(int on, int bal) {
	if(bal + ms / 2 < 0 || bal + ms / 2 >= ms) return 1e9;
	if(on == n) return bal == 0 ? 0 : 1e9;
	int &ans = memo[on][bal + ms / 2];
	if(visit[on][bal + ms / 2]) return ans;
	visit[on][bal + ms / 2] = true;
	if(a[on] == 0) {
		ans = dp(on+1, bal);
		if(bal > 0) {
			ans = std::min(ans, on + dp(on+1, bal - 1));
		} else {
			ans = std::min(ans, -on + dp(on+1, bal - 1));
		}
	} else {
		if(bal < 0) {
			ans = on + dp(on+1, bal + 1);
		} else {
			ans = -on + dp(on+1, bal + 1);
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cout << dp(0, 0) << '\n';
}