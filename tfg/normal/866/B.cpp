#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long S;
	std::cin >> n >> S;
	std::vector<std::pair<int, int>> A, B;
	long long fA = 0, fB = 0;
	long long ans = 0;
	while(n--) {
		int s, a, b;
		std::cin >> s >> a >> b;
		if(a > b) {
			fA += s;
			ans += (long long) b * s;
			A.emplace_back(a - b, s);
		} else {
			fB += s;
			ans += (long long) a * s;
			B.emplace_back(b - a, s);
		}
	}
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	long long target;
	target = fA % S;
	while(fA > target) {
		auto p = A.back();
		A.pop_back();
		int used = (int) std::min((long long) p.second, fA - target);
		fA -= used;
		p.second -= used;
		ans += (long long) used * p.first;
		//std::cout << "removing " << used << " of cost " << p.first << "\n";
		if(p.second) {
			A.push_back(p);
		}
	}
	target = fB % S;
	while(fB > target) {
		auto p = B.back();
		B.pop_back();
		int used = (int) std::min((long long) p.second, fB - target);
		fB -= used;
		p.second -= used;
		ans += (long long) used * p.first;
		//std::cout << "removing " << used << " of cost " << p.first << "\n";
		if(p.second) {
			B.push_back(p);
		}
	}
	//std::cout << "(" << fA << ", " << fB << "), " << S << "\n";
	if(fA + fB <= S) {
		long long cost[2] = {0, 0};
		for(auto p : A) cost[0] += (long long) p.first * p.second;
		for(auto p : B) cost[1] += (long long) p.first * p.second;
		ans += std::max(cost[0], cost[1]);
	} else {
		long long cost[2] = {0, 0};
		for(auto p : A) cost[0] += (long long) p.first * p.second;
		for(auto p : B) cost[1] += (long long) p.first * p.second;
		ans += cost[0] + cost[1];
	}
	std::cout << ans << '\n';
}