#include <iostream>
#include <cstdio>
#include <vector>

typedef long long ll;

const int MOD = 1e9 + 7;
const int ms = 200200;

ll a[ms];
std::vector<int> edges[ms];

ll paths[ms][2];
ll sum[ms][2];

ll dfs(int on = 0, int par = -1) {
	ll ans = 0;
	paths[on][1] = 1;
	sum[on][1] = a[on];
	for(auto to : edges[on]) {
		if(to == par) {
			continue;
		}
		ans += dfs(to, on);
		ans %= MOD;
		ans -= paths[on][1] * sum[to][0] + sum[on][0] * paths[to][1];
		ans %= MOD;
		ans += sum[on][1] * paths[to][0] + paths[on][0] * sum[to][1];
		ans %= MOD;
		sum[on][1] += a[on] * paths[to][0] - sum[to][0];
		sum[on][0] += a[on] * paths[to][1] - sum[to][1];
		sum[on][1] %= MOD;
		sum[on][0] %= MOD;
		paths[on][0] += paths[to][1];
		paths[on][1] += paths[to][0];
		paths[on][1] %= MOD;
		paths[on][0] %= MOD;
		ans = ans % MOD;
	}
	//std::cout << "on " << on << ", got (" << paths[on][0] << ", " << paths[on][1] << "), (" << sum[on][0] << ", " << sum[on][1] << ")\n";
	return (ans % MOD + MOD) % MOD;
}

int main() {
	int n;
	std::cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lld", a + i);
		sum += a[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	std::cout << (sum % MOD + 2 * dfs() + MOD) % MOD << '\n';
}