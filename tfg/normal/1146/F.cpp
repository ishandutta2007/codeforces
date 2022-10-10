#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const int MOD = 998244353;

std::vector<int> edges[ms];

template <int mod = MOD>
struct modBase {
	modBase(int vval = 0) : val(vval) {}
	int val;

	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val > mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

modBase<> dp[ms][3];

void dfs(int on) {
	if(edges[on].empty()) {
		dp[on][2] = 1;
		return;
	}
	dp[on][0] = 1;
	for(auto to : edges[on]) {
		dfs(to);
		modBase<> wtf[3];
		// 0 is ways to get 0 * (ways to get below)
		wtf[0] = dp[on][0] * (dp[to][0] + dp[to][2]);
		// 1 is ways to get 1 * ways to get 0 + ways to get 0 * (ways to get 1 + ways to get 2)
		wtf[1] = dp[on][1] * (dp[to][0] + dp[to][2]) + dp[on][0] * (dp[to][1] + dp[to][2]);
		// 2 is (ways to get 1 + ways to get 2) * (ways to get 1 + ways to get 2)
		wtf[2] = (dp[on][1] + dp[on][2]) * (dp[to][1] + dp[to][2]) + dp[on][2] * (dp[to][2] + dp[to][0]);
		dp[on][0] = wtf[0];
		dp[on][1] = wtf[1];
		dp[on][2] = wtf[2];
		//std::cout << "after including " << to << " got " << wtf[0].val << ", " << wtf[1].val << ", " << wtf[2].val << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int x;
		std::cin >> x;
		x--;
		edges[x].push_back(i);
	}
	dfs(0);
	std::cout << (dp[0][2] + dp[0][0]).val << '\n';
}