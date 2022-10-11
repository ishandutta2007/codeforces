#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <set>
#include <cstdio>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int m;
std::set<int> edges[ms];
int deg[ms];

int memo[ms];

int dp(int on) {
	int &ans = memo[on];
	if(ans != -1) return ans;
	if(deg[on] < m || edges[on].size() != 1) {
		return ans = 1;
	} else {
		return ans = 1 + dp(*edges[on].begin());
	}
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int lst = 0;
		for(int j = 1; j <= n; j++) {
			deg[lst]++;
			int v;
			//std::cin >> v;
			scanf("%d", &v);
			edges[lst].insert(v);
			lst = v;
		}
	}
	for(int i = 0; i <= n; i++) {
		memo[i] = -1;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += dp(i);
	}
	std::cout << ans << '\n';
}