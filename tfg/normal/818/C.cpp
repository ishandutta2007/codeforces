#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<std::pair<int, int>> solve(std::vector<std::pair<int, int>> a) {
	int n = (int) a.size();
	const int ms = 100100;
	std::vector<int> mn(ms, 0), mx(ms, 0);
	for(auto &p : a) {
		if(p.first > p.second) std::swap(p.first, p.second);
		mn[p.first]++;
		mx[p.second]++;
	}
	for(int i = 1; i < ms; i++) {
		mn[i] += mn[i-1];
		mx[ms-i-1] += mx[ms-i];
	}
	std::vector<std::pair<int, int>> ans;
	for(int i = 0; i < n; i++) {
		ans.emplace_back(mn[a[i].second-1], mx[a[i].first+1]);
		if(a[i].first != a[i].second) {
			ans.back().first--;
			ans.back().second--;
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	{
		int trash;
		std::cin >> trash;
		std::cin >> trash;
	}
	std::vector<std::pair<int, int>> X(n), Y(n);
	for(int i = 0; i < n; i++) {
		std::cin >> X[i].first >> Y[i].first >> X[i].second >> Y[i].second;
	}
	std::vector<std::pair<int, int>> got[2] = {solve(X), solve(Y)};
	std::pair<int, int> want[2];
	std::cin >> want[0].first >> want[0].second;
	std::cin >> want[1].first >> want[1].second;
	for(int i = 0; i < n; i++) {
		if(want[0] == got[0][i] && want[1] == got[1][i]) {
			std::cout << i + 1 << std::endl;
			return 0;
		}
	}
	std::cout << "-1\n";
}