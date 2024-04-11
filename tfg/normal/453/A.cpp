#include <iostream>
#include <vector>
#include <iomanip>

typedef long double ld;

std::vector<ld> add(std::vector<ld> a, std::vector<ld> b) {
	std::vector<ld> ans(a.size(), 0);
	for(int i = 1; i < a.size(); i++) {
		ans[i] += a[i - 1] * b[i];
		b[i] += b[i - 1];
		ans[i] += a[i] * b[i];
		a[i] += a[i - 1];
	}
	return ans;
}

std::vector<ld> solve(int n, int e) {
	std::vector<ld> ans(n + 1, 0);
	ans[0] = 1;
	std::vector<ld> base(n + 1, 1.0 / n);
	base[0] = 0;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = add(ans, base);
		}
		base = add(base, base);
	}
	return ans;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	auto v = solve(n, k);
	ld ans = 0;
	for(int i = 1 ; i <= n; i++) {
		//std::cout << (double)v[i] << ' ';
		ans += i * v[i];
	}
	//std::cout << '\n';
	std::cout << std::fixed << std::setprecision(15) << (double)ans << '\n';
}