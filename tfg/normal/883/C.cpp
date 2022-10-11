#include <iostream>
#include <algorithm>

typedef long long ll;

ll size;

struct plan {
	ll rate, cost, size;
	void read() {
		std::cin >> size >> rate >> cost;
	}
};

bool cmp(plan a, plan b) {
	return a.rate < b.rate;
}

plan plans[3];

ll can(ll f, ll s) {
	ll cur = size;
	ll ans = 0;
	ll use = std::min(f * plans[1].size, cur);
	cur -= use;
	ans += use * plans[1].rate;
	use = std::min(s * plans[2].size, cur);
	cur -= use;
	ans += use * plans[2].rate;
	ans += cur * plans[0].rate;
	//std::cout << "for (" << f << ", " << s << ") returning " << ans << "\n";
	return ans;
}

int main() {
	ll limit;
	std::cin >> size >> limit >> plans[0].rate;
	plans[0].cost = 0;
	plans[0].size = size;
	for(int i = 1; i <= 2; i++) {
		plans[i].read();
	}
	std::sort(plans + 1, plans + 3, cmp);
	ll ans = 1e18;
	for(int i = 0; i <= size; i++) {
		if(can(i, 0) <= limit) {
			ans = std::min(ans, i * plans[1].cost);
		}
	}
	for(int i = 0; i <= size; i++) {
		if(can(0, i) <= limit) {
			ans = std::min(ans, i * plans[2].cost);
		}
	}
	for(int i = 0, j = size; i <= size; i++) {
		while(j && can(j - 1, i) <= limit) {
			j--;
		}
		if(can(j, i) <= limit) {
			ans = std::min(ans, i * plans[2].cost + j * plans[1].cost);
		}
	}
	for(int i = 0, j = size; i <= size; i++) {
		while(j && can(i, j - 1) <= limit) {
			j--;
		}
		if(can(i, j) <= limit) {
			ans = std::min(ans, i * plans[1].cost + j * plans[2].cost);
		}
	}
	if(ans >= 1e18) {
		ans = -1;
	}
	std::cout << ans << '\n';
}