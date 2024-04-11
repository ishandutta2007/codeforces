#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int a[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int ans;
	std::cin >> ans;
	while(ans--) {
		int x;
		std::cin >> x;
		a[x]++;
	}
	int ansl = 0, ansr = 0;
	for(int l = 1, r = 1; l < ms; l = std::max(l + 1, r - 1))  {
		r = l;
		if(a[l] == 0) {
			r++;
			continue;
		}
		int sum = a[l];
		r++;
		while(a[r] >= 2) sum += a[r++];
		if(a[r] == 1) {
			sum += a[r++];
		}
		if(sum > ans) {
			ansl = l;
			ansr = r;
			ans = sum;
		}
	}
	std::vector<int> wtf;
	for(int i = ansl + 1; i < ansr - 1; i++) {
		while(a[i] > 1) {
			a[i]--;
			wtf.push_back(i);
		}
	}
	for(int i = ansr - 1; i >= ansl; i--) {
		while(a[i] > 0) {
			a[i]--;
			wtf.push_back(i);
		}
	}
	assert(ans == (int) wtf.size());
	std::cout << wtf.size() << '\n';
	for(int i = 0; i < ans; i++) {
		std::cout << wtf[i] << (i + 1 == ans ? '\n' : ' ');
	}
}