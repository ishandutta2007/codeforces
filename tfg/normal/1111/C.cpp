#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long A, B;

long long a[100100];

long long solve(int l, int r, int pl, int pr) {
	//std::cout << "on [" << l << ", " << r << "), [" << pl << ", " << pr << ")\n";
	long long ans = 0;
	if(pr == pl) {
		ans = A;
	} else {
		ans = (long long) (r - l) * (pr - pl) * B;
	}
	if(l + 1 == r) return ans;
	if(pr == pl) return ans;
	int mid = l + (r - l) / 2;
	int pm = pl;
	while(pm < pr && a[pm] < mid) {
		pm++;
	}
	return std::min(ans, solve(l, mid, pl, pm) + solve(mid, r, pm, pr));
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int e, k;
	std::cin >> e >> k >> A >> B;
	for(int i = 0; i < k; i++) {
		std::cin >> a[i];
		a[i]--;
	}
	std::sort(a, a + k);
	std::cout << solve(0, 1 << e, 0, k) << '\n';
}