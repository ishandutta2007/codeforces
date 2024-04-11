#include <iostream>
#include <vector>

int main() {
	std::vector<long long> divs;
	int n;
	std::cin >> n;
	for(int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			divs.push_back(i);
			if(n / i != i) {
				divs.push_back(n / i);
			}
		}
	}
	long long ans[2] = {(long long)(2e18), 0};
	for(auto a : divs) {
		for(auto b : divs) {
			int need = n / a / b;
			if(need == 0 || n / a % b != 0) {
				continue;
			}
			//std::cout << "got " << a << ", " << b << ", " << need << "\n";
			ans[0] = std::min(ans[0], (a + 1) * (b + 2) * (need + 2) - n);
			ans[1] = std::max(ans[1], (a + 1) * (b + 2) * (need + 2) - n);
		}
	}
	std::cout << ans[0] << ' ' << ans[1] << '\n';
}