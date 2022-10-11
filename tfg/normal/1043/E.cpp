#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <iostream>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	std::vector<int> b(n);
	std::vector<long long> c(n);
	std::vector<long long> sum(n + 1, 0);
	long long base = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		base += a[i];
		sum[i + 1] = (long long) b[i] - a[i];
		c[i] = (long long) b[i] - a[i];
	}
	std::sort(c.begin(), c.end());
	std::sort(sum.begin() + 1, sum.end());
	for(int i = 1; i <= n; i++) {
		sum[i] += sum[i - 1];
	}
	std::vector<long long> ans(n, 0);
	for(int i = 0; i < n; i++) {
		int idx = std::upper_bound(c.begin(), c.end(), (long long) b[i] - a[i]) - c.begin();
		ans[i] = base + (n - 2LL) * a[i];
		//std::cout << "base for " << i << " is " << ans[i] << "\n";
		// on left, using best c
		ans[i] += sum[idx];
		// on right, using current c
		ans[i] += (long long) (n - idx - 1) * ((long long) b[i] - a[i]);
	}
	while(m--) {
		//break;
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		int cost = std::min(a[u] + b[v], a[v] + b[u]);
		ans[u] -= cost;
		ans[v] -= cost;
	}
	for(int i = 0; i < n; i++) {
		//std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
		printf("%lld%c", ans[i], i + 1 == n ? '\n' : ' ');
	}
}