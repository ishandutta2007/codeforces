#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdio>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;
const int MOD = int(1e9) + 7;

std::vector<int> edges[ms];

int a[ms];
long long sum[ms];

void dfs(int on) {
	sum[on] = a[on];
	for(auto to : edges[on]) {
		dfs(to);
		sum[on] += sum[to];
	}
}

long long gcd(long long aa, long long b) {
	if(b == 0) {
		return aa;
	} else {
		return gcd(b, aa % b);
	}
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for(int i = 1; i < n; i++) {
		int v;
		scanf("%d", &v);
		v--;
		edges[v].push_back(i);
	}
	dfs(0);
	std::vector<int> freq(n + 1, 0);
	for(int i = 1; i < n; i++) {
		sum[i] = sum[0] / gcd(sum[0], sum[i]);
		if(sum[i] <= n) {
			freq[(int)sum[i]]++;
		}
	}
	freq[1]++;
	for(int i = n; i > 0; i--) {
		for(int j = i + i; j <= n; j += i) {
			freq[j] += freq[i];
		}
	}
	std::vector<int> dp(n + 1, 0);
	for(int i = n; i > 0; i--) {
		if(freq[i] != i) {
			continue;
		}
		dp[i] = 1;
		for(int j = i + i; j <= n; j += i) {
			dp[i] = (dp[i] + dp[j]) % MOD;
		}
	}
	std::cout << dp[1] << std::endl;
}