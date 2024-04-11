#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <tuple>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int size;
int closest(int x) {
	x = (x % size + size) % size;
	return std::min(x, size - x);
}
int closest(int a, int b) {
	return closest(a-b);
}
struct Group {
	std::vector<int> a;
	int n = 0;

	void push_back(int x) {
		a.push_back(x);
		n++;
	}

	std::vector<std::vector<int>> dp;
	std::vector<std::vector<std::pair<int, int>>> to;

	void init() {
		dp.assign(2 * n + 1, std::vector<int>(2*n+1, -1));
		to.assign(2 * n + 1, std::vector<std::pair<int, int>>(2*n+1));
		for(int i = 0; i < n; i++) {
			a.push_back(a[i] + size);
		}
	}

	int dist(int i, int j) {
		return closest(a[j] - a[i]);
	}

	template<class F>
	void calc(F f) {
		init();
		for(int d = 1; d <= 2 * n; d++) {
			for(int l = 0; l + d <= 2 * n; l++) {
				int r = l + d;
				if(d == 1) {
					auto got = f(a[l]);
					dp[l][r] = dp[r][l] = got.first;
					to[l][r] = to[r][l] = got.second;
				} else {
					dp[l][r] = std::min(dp[l+1][r] + dist(l, l+1), dp[r][l+1] + dist(l, r-1));
					if(dp[l][r] == dp[l+1][r] + dist(l, l+1)) {
						to[l][r] = std::pair<int, int>(l+1, r);
					} else {
						to[l][r] = std::pair<int, int>(r, l+1);
					}
					dp[r][l] = std::min(dp[l][r-1] + dist(r-1, l), dp[r-1][l] + dist(r-1, r-2));
					if(dp[r][l] == dp[l][r-1] + dist(r-1, l)) {
						to[r][l] = std::pair<int, int>(l, r-1);
					} else {
						to[r][l] = std::pair<int, int>(r-1, l);
					}
				}
			}
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, s;
	std::cin >> n >> s;
	size = n;
	std::map<int, Group> mp;
	mp[-1000000100].push_back(s-1);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		mp[x].push_back(i);
	}
	std::vector<Group> a;
	for(auto it : mp) a.push_back(it.second);
	n = (int) a.size();
	for(int i = n-1; i >= 0; i--) {
		//std::cout << "group " << i << " has: ";
		//for(auto x : a[i].a) std::cout << x << ' ';
		//std::cout << std::endl;
		if(i+1 == n) {
			a[i].calc([](int x){ return std::pair<int, std::pair<int, int>>(0, std::pair<int, int>(x, x)); });
		} else {
			a[i].calc([&](int x) {
				std::pair<int, std::pair<int, int>> ans(1e9, std::pair<int, int>(-1, -1));
				for(int j = 0; j < a[i+1].n; j++) {
					int d = closest(x, a[i+1].a[j]) + a[i+1].dp[j][j+a[i+1].n];
					if(d < ans.first) {
						ans.first = d;
						ans.second = std::pair<int, int>(j, j+a[i+1].n);
					}
				}
				return ans;
			});
		}
	}

	std::cout << a[0].dp[0][a[0].n] << '\n';
	s--;
	for(int i = 0, l = 0, r = a[0].n; i < n; i++) {
		for(int rep = 0; rep < a[i].n; rep++) {
			//std::cout << s << ", [" << l << ", " << r << ")\n";
			std::tie(l, r) = a[i].to[l][r];
			if(l != r) {
				int nxt = l < r ? l : l-1;
				nxt = rep+1 == a[i].n ? a[i+1].a[nxt] : a[i].a[nxt];
				nxt %= size;
				int dist = (nxt - s + 3 * size) % size;
				if(dist <= size - dist) {
					std::cout << "+" << dist << '\n';
				} else {
					std::cout << "-" << size - dist << '\n';
				}
				s = nxt;
			}
		}
	}
}