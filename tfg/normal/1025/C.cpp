#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	str += str;
	int ans = 0;
	int cur = 1;
	for(int i = 1; i < str.size(); i++) {
		if(str[i] != str[i - 1]) {
			cur++;
		} else {
			cur = 1;
		}
		ans = std::max(cur, ans);
	}
	ans = std::min(ans, (int)str.size() / 2);
	std::cout << ans << std::endl;
}