#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Operation {
	int i, j, x;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		int sum = 0;
		std::cin >> n;
		std::vector<int> a(n+1);
		for(int i = 1; i <= n; i++) {
			std::cin >> a[i];
			sum += a[i];
		}
		if(sum % n != 0) {
			std::cout << "-1\n";
			continue;
		}
		std::vector<Operation> ans;
		auto doOp = [&](int i, int j, int x) {
			if(x == 0) return;
			a[i] -= x * i;
			a[j] += x * i;
			assert(a[i] >= 0 && (int) ans.size() <= 3 * n);
			Operation cur;
			cur.i = i, cur.j = j, cur.x = x;
			ans.push_back(cur);
		};
		for(int i = 2; i <= n; i++) {
			doOp(1, i, (i - a[i] % i) % i);
			doOp(i, 1, a[i] / i);
			assert(a[i] == 0);
		}
		for(int i = 2; i <= n; i++) {
			doOp(1, i, sum / n);
		}
		std::cout << ans.size() << '\n';
		for(auto op : ans) {
			std::cout << op.i << ' ' << op.j << ' ' << op.x << '\n';
		}
	}
}