#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int want = 0;
	std::cin >> want;
	std::vector<std::pair<int, std::string>> a;
	int sz = 0;
	for(int l = 0, r = 0; l < (int) str.size(); l = r) {
		r++;
		if(r < (int) str.size() && (str[r] == '?' || str[r] == '*')) {
			assert(str[r] == '?' || str[r] == '*');
			a.push_back({str[r] == '?' ? 1 : 0, str.substr(l, r - l)});
			r++;
			sz += r - l - 1;
		} else {
			a.push_back({-1, str.substr(l, r-l)});
			sz += r - l;
		}
	}
	std::string ans;
	for(auto &[val, st] : a) {
		while((val == 1 || val == 0) && (int) st.size() > 0 && sz > want) {
			sz--;
			st.pop_back();
		}
		while(val == 0 && !st.empty() && sz < want) {
			sz++;
			st += st.back();
		}
		ans += st;
	}
	if(want == sz) {
		std::cout << ans << '\n';
	} else {
		std::cout << "Impossible\n";
	}
}