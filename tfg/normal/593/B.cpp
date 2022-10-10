#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long x1, x2;
	std::cin >> x1 >> x2;
	std::vector<std::pair<long long, long long>> lines(n);
	std::vector<int> p1(n), p2(n);
	for(int i = 0; i < n; i++) {
		std::cin >> lines[i].first >> lines[i].second;
		p1[i] = p2[i] = i;
	}
	long long pivot = x1;
	auto test1 = [&](int a, int b) {
		if(lines[a].first * pivot + lines[a].second == lines[b].first * pivot + lines[b].second) {
			return lines[a].first > lines[b].first;
		}
		return lines[a].first * pivot + lines[a].second > lines[b].first * pivot + lines[b].second;
	};
	auto test2 = [&](int a, int b) {
		if(lines[a].first * pivot + lines[a].second == lines[b].first * pivot + lines[b].second) {
			return lines[a].first < lines[b].first;
		}
		return lines[a].first * pivot + lines[a].second > lines[b].first * pivot + lines[b].second;
	};
	std::sort(p1.begin(), p1.end(), test1);
	pivot = x2;
	std::sort(p2.begin(), p2.end(), test2);
	std::cout << (p1 == p2 ? "No\n" : "Yes\n");
}