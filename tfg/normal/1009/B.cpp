#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	std::string ans;
	int n = str.size();
	int ones = 0;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && str[r] != '2') {
			if(str[r] == '0') ans += '0';
			else ones++;
			r++;
		}
		if(r < n) {
			ans += '2';
			r++;
		}
	}
	int pos = 0;
	while(pos < ans.size() && ans[pos] == '0') {
		pos++;
	}
	ans = ans.substr(0, pos) + std::string(ones, '1') + ans.substr(pos, ans.size() - pos);
	std::cout << ans << std::endl;
}