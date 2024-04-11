#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string s, t;
	std::cin >> s >> t;
	std::vector<int> freq1(26, 0), freq2(26, 0);
	for(auto c : s) {
		freq1[c - 'a']++;
	}
	for(auto c : t) {
		freq2[c - 'a']++;
	}
	int ans = -1;
	int on = 0;
	while(on < (int) t.size()) {
		int wtf = t[on] - 'a' + 1;
		while(wtf < 26 && !freq1[wtf]) wtf++;
		if(wtf < 26) {
			ans = on;
		}
		if(!freq1[t[on] - 'a'] || !freq2[t[on] - 'a']) break;
		freq1[t[on] - 'a']--;
		freq2[t[on] - 'a']--;
		on++;
	}
	if(on == (int) t.size() && s.size() > t.size()) ans = on;
	if(ans == -1) {
		std::cout << "-1\n";
		return 0;
	}
	//std::cout << "ans at " << ans << std::endl;
	freq1 = std::vector<int>(26, 0);
	for(auto c : s) {
		freq1[c - 'a']++;
	}
	std::string str = t.substr(0, ans);
	for(auto c : str) {
		freq1[c - 'a']--;
	}
	int wtf = ans == (int) t.size() ? 0 : t[ans] - 'a' + 1;
	assert(ans != (int) s.size());
	while(ans != (int) s.size()) {
		while(wtf < 26 && !freq1[wtf]) wtf++;
		assert(wtf != 26);
		str += char(wtf + 'a');
		ans++;
		freq1[wtf]--;
		wtf = 0;
	}
	std::cout << str << std::endl;
}