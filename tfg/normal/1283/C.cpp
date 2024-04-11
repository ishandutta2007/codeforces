#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<bool> b(n, false);
	int f = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i]--;
		if(a[i] != -1) {
			b[a[i]] = true;
		} else {
			f++;
		}
	}
	std::vector<int> o;
	for(int i = 0; i < n; i++) {
		if(!b[i]) {
			o.push_back(i);
		}
	}
	std::vector<int> wtf;
	for(int i = 0; i < n; i++) {
		if(a[i] == -1 && f > 2) {
			if(i == o.back()) {
				std::swap(o.back(), o[0]);
			}
			a[i] = o.back();
			o.pop_back();
			f--;
		} else if(a[i] == -1) {
			wtf.push_back(i);
		}
	}
	for(int i = 0; i < f; i++) {
		a[wtf[i]] = o[i];
	}
	if(f == 2 && (a[wtf[0]] == wtf[0] || a[wtf[1]] == wtf[1])) {
		std::swap(a[wtf[0]], a[wtf[1]]);
	}
	for(int i = 0; i < n; i++) {
		std::cout << a[i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}