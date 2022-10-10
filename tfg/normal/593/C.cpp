#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::string wtf(int x) {
	if(x == 0) return "0";
	if(x < 0) return "(0-" + wtf(-x) + ")";
	if(x > 50) return "(50+" + wtf(x - 50) + ")";
	std::string ans;
	while(x) {
		ans += char('0' + x % 10);
		x /= 10;
	}
	std::reverse(ans.begin(), ans.end());
	return ans;
}

std::string solve(int t, std::vector<int> &v) {
	if(t == (int) v.size()) return std::string(1, '0');
	int got = v[t];
	if(got == 0) {
		return solve(t + 1, v);
	}
	//std::cout << "got " << got << " at " << t << std::endl;
	for(int i = t; i < (int) v.size(); i++) {
		v[i] -= (i - t + 1) * got;
	}
	//std::cout << "is now " << v[t] << "\n";
	// this is the result of getting
	// got * (abs(-(x - t + 1)) + (x - t + 1))
	// got * (abs(-x + t - 1) + (x - t + 1))
	std::string ans;
	std::string rest = solve(t + 1, v);
	ans = "(abs((" + wtf(t) + "-t))+(t-" + wtf(t) + "))";
	ans = "(" + wtf(got) + "*" + ans + ")";
	ans = "(" + ans + "+" + rest + ")";
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) {
		int r;
		std::cin >> x[i] >> y[i] >> r;
		if(x[i]&1) x[i]++;
		if(y[i]&1) y[i]++;
		x[i] /= 2;
		y[i] /= 2;
	}
	std::cout << solve(0, x) << '\n' << solve(0, y) << '\n';
}