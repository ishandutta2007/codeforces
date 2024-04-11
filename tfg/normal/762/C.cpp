#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string a, b;
	std::cin >> b >> a;
	std::vector<int> pref((int) a.size() + 1);
	auto suf = pref;
	pref[0] = -1;
	suf.back() = (int) b.size();
	{
		int i = 0;
		int j = 1;
		for(auto c : a) {
			while(i < (int) b.size() && c != b[i]) i++;
			if(i < (int) b.size()) pref[j++] = i++;
			else pref[j++] = i;
		}
	}
	{
		int i = (int) b.size() - 1;
		int j = (int) a.size() - 1;
		std::reverse(a.begin(), a.end());
		for(auto c : a) {
			while(i >= 0 && c != b[i]) i--;
			if(i >= 0) suf[j--] = i--;
			else suf[j--] = i;
		}
		std::reverse(a.begin(), a.end());
	}
	auto check = [&](int x) {
		for(int i = 0; i + x <= (int) a.size(); i++) {
			if(pref[i] < suf[i + x]) return a.substr(0, i) + a.substr(i + x, (int) a.size() - (i + x));
		}
		return std::string("");
	};
	int l = 0, r = (int) a.size();
	while(l != r) {
		int mid = (l + r) / 2;
		if(!check(mid).empty()) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if(l == (int) a.size()) {
		std::cout << "-\n";
	} else {
		std::cout << check(l) << '\n';
	}
}