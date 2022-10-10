#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	std::vector<long long> poly(b-a+1, 1);
	long long ans = 0;
	for(int i = 0; poly.back() != 0 && i <= c-a+10; i++) {
		if(i >= (int) poly.size()) poly.push_back(0);
		if(i) poly[i] += poly[i-1];
		if(i - (c-b+1) >= 0 && i - (c-b+1) < b-a+1) poly[i]--;
		int l = c, r = d;
		r = std::min(r, i + a + b - 1);
		//std::cout << "at " << i + a + b << " got " << poly[i] << " ways\n";
		ans += std::max(0, r - l + 1) * poly[i];
	}
	std::cout << ans << '\n';
}