#include <iostream>
#include <cstring>
#include <algorithm>

const int eps = 'z' - 'a' + 1;
const int ms = eps * 100 + 1;
const int INF = 1e9;

std::string str;
int freq[eps];

int memo[ms][ms];
int way[ms][ms];
int k = 0;
int dp(int l, int r) {
	if(l > r) {
		return 0;
	} else if(l == r) {
		return k;
	}
	int &ans = memo[l][r];
	if(ans != -1) {
		return ans;
	}
	ans = 0;
	way[l][r] = 2;
	if(str[l] == str[r]) {
		ans = 2 + dp(l + 1, r - 1);
		way[l][r] = 1;
	}
	if(dp(l, r - 1) > ans) {
		ans = dp(l, r - 1);
		way[l][r] = 2;
	}
	if(dp(l + 1, r) > ans) {
		ans = dp(l + 1, r);
		way[l][r] = 3;
	}
	return ans;
}


int main() {
	std::cin >> str;
	for(auto a : str) {
		freq[a - 'a']++;
	}
	for(int i = 0; i < eps; i++) {
		if(freq[i] >= 100) {
			for(int j = 0; j < 100; j++) {
				std::cout << char(i + 'a');
			}
			std::cout << '\n';
			return 0;
		}
	}
	memset(memo, -1, sizeof memo);
	int l = 0, r = str.size() - 1;
	if(dp(0, str.size() - 1) >= 100) {
		std::string ans;
		while(ans.size() != 50) {
			if(way[l][r] == 1) {
				l++;
				r--;
				ans += str[l - 1];
			} else if(way[l][r] == 2) {
				r--;
			} else {
				l++;
			}
		}
		std::cout << ans;
		std::reverse(ans.begin(), ans.end());
		std::cout << ans << '\n';
		return 0;
	}
	k = 1;
	memset(memo, -1, sizeof memo);
	dp(0, str.size() - 1);
	std::string ans[2];
	while(l < r) {
		if(way[l][r] == 1) {
			l++;
			r--;
			ans[0] += str[l - 1];
			ans[1] += str[r + 1];
		} else if(way[l][r] == 2) {
			r--;
		} else {
			l++;
		}
	}
	if(l == r) {
		ans[0] += str[l];
	}
	std::reverse(ans[1].begin(), ans[1].end());
	std::cout << ans[0] << ans[1] << '\n';
}