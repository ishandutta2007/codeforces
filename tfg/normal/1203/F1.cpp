#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector< std::pair<int, int> > pos, neg;

int rating;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	// (al, bl) (ar, br)
	// al, ar >= rating
	// rating - bl >= ar, rating >= ar + bl
	// rating - br >= al, rating >= al + br
	int n;
	std::cin >> n >> rating;
	for(int i = 0; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		if(b >= 0) {
			pos.emplace_back(a, b);
		} else {
			neg.emplace_back(a, -b);
		}
	}
	std::sort(pos.begin(), pos.end());
	std::sort(neg.begin(), neg.end(), [](std::pair<int, int> v1, std::pair<int, int> v2) {
		return v1.second + v2.first < v2.second + v1.first;
	});
	// greedy
	int baseAns = 0;
	for(auto p : pos) {
		//std::cout << p.first << ", " << p.second << '\n';
		if(rating >= p.first) {
			rating += p.second;
			baseAns++;
		}
	}
	// dp
	n = (int) neg.size();
	std::vector<int> dp(1, rating);
	for(auto p : neg) {
		//std::cout << p.first << ", " << p.second << '\n';
		for(int j = (int) dp.size()-1; j >= 0; j--) {
			if(dp[j] >= p.first && dp[j] - p.second >= 0) {
				if(j + 1 == (int) dp.size()) {
					dp.push_back(-1);
				}
				dp[j+1] = std::max(dp[j+1], dp[j] - p.second);
			}
		}
	}
	int ans = baseAns + (int) dp.size() - 1;
	n = (int) pos.size() + neg.size();
	std::cout << (n == ans ? "YES\n" : "NO\n");
}