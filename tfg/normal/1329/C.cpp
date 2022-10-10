#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int me = 21;
const int ms = 1 << me;

int a[ms], p[ms], rev[ms];

int check(int on) {
	if(a[on+on] == 0 && a[on+on+1] == 0) {
		return on;
	} else if(a[on+on] > a[on+on+1]) {
		return check(on+on);
	} else {
		return check(on+on+1);
	}
}

void go(int on) {
	if(a[on+on] == 0 && a[on+on+1] == 0) {
		a[on] = 0;
	} else if(a[on+on] > a[on+on+1]) {
		p[rev[on+on]] = on;
		rev[on] = rev[on+on];
		a[on] = a[on+on];
		go(on+on);
	} else {
		p[rev[on+on+1]] = on;
		rev[on] = rev[on+on+1];
		a[on] = a[on+on+1];
		go(on+on+1);
	}
}

void solve() {
	int h, g;
	std::cin >> h >> g;
	int limit = 1 << g;
	long long sum = 0;
	for(int i = 1; i < (1 << h); i++) {
		std::cin >> a[i];
		sum += a[i];
		p[i] = i;
	}
	for(int i = (1 << h); i < (1 << (h+1)); i++) {
		a[i] = 0;
	}
	std::sort(p+1, p+(1<<h), [&](int v1, int v2) { return a[v1] > a[v2]; });
	for(int i = 1; i < (1 << h); i++) {
		rev[p[i]] = i;
	}
	h = (1 << h) - 1;
	g = (1 << g) - 1;
	std::vector<int> ans;
	int lel = h;
	for(int i = 1; h > g; i++) {
		assert(i < lel);
		if(check(p[i]) >= limit) {
			//std::cout << "getting value " << a[p[i]] << ", was " << i << "-thm value!" << std::endl;
			sum -= a[p[i]];
			ans.push_back(p[i]);
			go(p[i]);
			h--;
		} else {
			//std::cout << "not getting " << a[p[i]] << "!" << std::endl;
		}
	}
	std::cout << sum << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}