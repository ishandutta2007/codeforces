#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first;
	}
	for(int j = 0; j < n; j++) {
		std::cin >> a[j].second;
	}
	int t = -1, off = -1;
	for(int i = 0; i < n; i++) {
		if(a[i].first > a[i].second && t == 1) {
			t = off = -1;
		} else if(a[i].first < a[i].second && t == 0) {
			t = off = -1;
		}
		//std::cout << "got to (" << a[i].first << ", " << a[i].second << ") with (" << t << ", " << off << ")\n";
		if(t == 0) {
			a[i].first += off;
		} else if(t == 1) {
			a[i].second += off;
		}
		t = off = -1;
		if(t == -1) {
			// greedy solve
			int x = a[i].first, y = a[i].second;
			if(x < y) {
				std::swap(x, y);
			}
			y++;
			if((long long) y * k < x) {
				std::cout << "NO\n";
				return 0;
			}
			if((long long) y * k - x >= k) {
				continue;
			}
			off = k - (int) ((long long) y * k - x);
			t = a[i].first > a[i].second ? 0 : 1;
		}
	}
	std::cout << "YES\n";
}