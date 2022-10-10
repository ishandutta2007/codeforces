#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<const char ch, class T>
std::vector<T> FWHT(std::vector<T> a, const bool inv = false) {
	int n = (int) a.size();
	for(int len = 1; len < n; len += len) {
		for(int i = 0; i < n; i += 2 * len) {
			for(int j = 0; j < len; j++) {
				auto u = a[i + j], v = a[i + j + len];
				if(ch == '^') {
					a[i + j] = u + v;
					a[i + j + len] = u - v;
				}
				if(ch == '|') {
					if(!inv) {
						a[i + j + len] += a[i + j];
					} else {
						a[i + j + len] -= a[i + j];
					}
				}
				if(ch == '&') {
					if(!inv) {
						a[i + j] += a[i + j + len];
					} else {
						a[i + j] -= a[i + j + len];
					}
				}
			}
		}
	}
	if(ch == '^' && inv) {
		for(int i = 0; i < n; i++) {
			a[i] = a[i] / n;
		}
	}
	return a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	const int me = 9;
	const int ms = 1 << me;
	std::vector<int> cnt(ms, 0);
	auto readMask = []() {
		int x;
		std::cin >> x;
		int ans = 0;
		while(x--) {
			int y;
			std::cin >> y;
			ans |= 1 << (y-1);
		}
		return ans;
	};
	for(int i = 0; i < n; i++) {
		cnt[readMask()]++;
	}
	struct Pizza {
		int cost, mask, id;
	};
	std::vector<int> f(ms, 0);
	std::vector<Pizza> haha(m);
	for(int i = 0; i < m; i++) {
		std::cin >> haha[i].cost;
		haha[i].mask = readMask();
		haha[i].id = i + 1;
	}
	std::sort(haha.begin(), haha.end(), [](Pizza v1, Pizza v2) { return v1.cost < v2.cost; });
	std::vector<Pizza> wtf;
	for(auto pizza : haha) {
		if(f[pizza.mask] < 2) {
			f[pizza.mask]++;
			wtf.emplace_back(pizza);
		}
	}
	std::pair<int, int> ans(-1, -1);
	int x = -1, y = -1;
	m = (int) wtf.size();
	cnt = FWHT<'|'>(cnt);
	for(int i = 0; i < m; i++) {
		for(int j = i+1; j < m; j++) {
			int m1 = wtf[i].mask, m2 = wtf[j].mask;
			std::pair<int, int> got(cnt[m1|m2], -wtf[i].cost - wtf[j].cost);
			if(got > ans) {
				ans = got;
				x = wtf[i].id, y = wtf[j].id;
			}
		}
	}
	std::cout << x << ' ' << y << '\n';
}