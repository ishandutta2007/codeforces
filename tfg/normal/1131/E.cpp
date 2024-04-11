#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int len[26];
	for(int i = 0; i < 26; i++) {
		len[i] = 0;
	}
	std::vector<std::string> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		std::string str = a[i];
		int Len[26];
		for(int j = 0; j < 26; j++) {
			Len[j] = 0;
		}
		int got = 0;
		int fi = -1, la = -1;
		for(int l = 0, r = 0; r < (int) str.size(); l = r) {
			while(r < (int) str.size() && str[r] == str[l]) r++;
			Len[str[l] - 'a'] = std::max(Len[str[l] - 'a'], r - l);
			la = r - l;
			if(l == 0) fi = r - l;
			got++;
		}
		if(got == 1) {
			Len[str[0] - 'a'] = Len[str[0] - 'a'] * (1 + len[str[0] - 'a']) + len[str[0] - 'a'];
		} else if(str[0] != str.back()) {
			Len[str[0] - 'a'] = std::max(Len[str[0] - 'a'], fi + (len[str[0] - 'a'] == 0 ? 0 : 1));
			Len[str.back() - 'a'] = std::max(Len[str.back() - 'a'], la + (len[str.back() - 'a'] == 0 ? 0 : 1));
		} else if(len[str[0] - 'a']) {
			Len[str[0] - 'a'] = std::max(Len[str[0] - 'a'], fi + la + 1);
		}
		for(int j = 0; j < 26; j++) {
			if(len[j]) {
				Len[j] = std::max(1, Len[j]);
			}
			len[j] = Len[j];
		}
	}
	for(int i = 0; i < 26; i++) {
		ans = std::max(ans, len[i]);
	}
	std::cout << ans << '\n';
}