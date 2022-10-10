#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int n, k;

std::pair<int, int> qry(const std::set<int> &st) {
	assert((int) st.size() == k);
	std::cout << "?";
	for(auto t : st) {
		std::cout << ' ' << t + 1;
	}
	std::cout << std::endl;
	int pos, val;
	if(0) {
		int a[] = {9, 0, 1, 2};
		std::vector<int> wtf;
		for(auto x : st) {
			wtf.push_back(x);
		}
		std::sort(wtf.begin(), wtf.end(), [&](int v1, int v2){ return a[v1] < a[v2]; });
		pos = wtf[2] + 1;
		val = a[pos - 1];
		std::cout << pos << ' ' << val << '\n';
	} else {
		std::cin >> pos >> val;
	}
	return {pos-1, val};
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> k;
	if(k == 1) {
		std::cout << "! 1" << std::endl;
		return 0;
	}
	std::set<int> hmm;
	for(int i = 0; i < k; i++) {
		hmm.insert(i);
	}
	auto f = qry(hmm);
	hmm.erase(f.first);
	hmm.insert(k);
	auto s = qry(hmm);
	int delta, ans;
	if(f.second > s.second) {
		std::swap(f, s);
		ans = 1;
		delta = 1;
	} else {
		std::swap(f, s);
		ans = 1;
		delta = 0;
	}
	auto other = hmm;
	other.erase(f.first);
	hmm.insert(s.first);
	for(auto x : other) {
		hmm.erase(x);
		auto got = qry(hmm);
		hmm.insert(x);
		if(got.first != f.first) {
			ans += delta;
		} else {
			ans += 1 - delta;
		}
	}
	std::cout << "! " << ans << std::endl;
}