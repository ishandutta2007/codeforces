#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Person {
	int a[5];

	bool better(Person o) {
		int ans = 0;
		for(int i = 0; i < 5; i++) {
			if(a[i] < o.a[i]) {
				ans++;
			}
		}
		return ans >= 3;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<Person> a(n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 5; j++) {
				std::cin >> a[i].a[j];
			}
		}
		Person best = a[0];
		int id = 0;
		for(int i = 1; i < n; i++) {
			if(a[i].better(best)) {
				best = a[i];
				id = i;
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(best.better(a[i])) cnt++;
		}
		std::cout << (cnt == n-1 ? id+1 : -1) << '\n';
	}
}