#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <array>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// copied from https://github.com/kth-competitive-programming/kactl/blob/master/content/strings/Manacher.h
std::array<std::vector<int>, 2> manacher(const std::string& s) {
	int n = (int) s.size();
	std::array<std::vector<int>, 2> p = {std::vector<int>(n+1), std::vector<int>(n)};
	for(int z = 0; z < 2; z++) for (int i = 0, l = 0, r = 0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = std::min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	if(0) {
		std::string str;
		std::cin >> str;
		auto x = manacher(str);
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < (int) x[i].size(); j++) {
				std::cout << x[i][j] << (j + 1 == (int) x[i].size() ? '\n' : ' ');
			}
		}
	}
	int t;
	std::cin >> t;
	while(t--) {
		std::string str;
		std::cin >> str;
		if(0){

			auto x = manacher(str);
			for(int i = 0; i < 2; i++) {
				for(int j = 0; j < (int) x[i].size(); j++) {
					std::cout << x[i][j] << (j + 1 == (int) x[i].size() ? '\n' : ' ');
				}
			}
		}
		int n = (int) str.size();
		int l = 0, r = n-1;
		while(l <= r && str[l] == str[r]) {
			l++;
			r--;
		}
		if(l >= r) {
			std::cout << str << '\n';
			continue;
		}
		struct Answer {
			Answer(int a = 0, int b = 0, int c = 0, int d = 0) {
				l[0] = a, l[1] = c;
				r[0] = b, r[1] = d;
			}
			int l[2], r[2];
			int size() const { return r[0] + r[1] - l[0] - l[1]; }
			bool operator > (const Answer &o) const { return size() > o.size(); }
			bool operator < (const Answer &o) const { return size() < o.size(); }
		};
		Answer ans(0, l+1, r+1, n);
		auto man = manacher(str);
		// testing for odd rest
		for(int i = 0; i < n; i++) {
			int left = i - man[1][i];
			int right = i + 1 + man[1][i];
			int use = std::max(l - left, right - (r+1));
			if(use < 0) continue;
			left += use;
			right -= use;
			if(left >= right) continue;
			if(left == l) {
				ans = std::max(ans, Answer(0, right, r+1, n));
			} else {
				ans = std::max(ans, Answer(0, l, left, n));
			}
		}
		// testing for even rest
		for(int i = 0; i < n; i++) {
			if(!man[0][i+1]) continue;
			int left = i - man[0][i+1] + 1;
			int right = i + 1 + man[0][i+1];
			int use = std::max(l - left, right - (r+1));
			if(use < 0) continue;
			left += use;
			right -= use;
			if(left >= right) continue;
			if(left == l) {
				ans = std::max(ans, Answer(0, right, r+1, n));
			} else {
				ans = std::max(ans, Answer(0, l, left, n));
			}
		}
		//std::cout << ans.l[0] << ", " << ans.r[0] << '\n';
		//std::cout << ans.l[1] << ", " << ans.r[1] << '\n';
		std::cout << str.substr(ans.l[0], ans.r[0] - ans.l[0]) + str.substr(ans.l[1], ans.r[1] - ans.l[1]) << '\n';
	}
}