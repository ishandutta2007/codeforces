#include <iostream>
#include <vector>

int main() {
	std::string s, t;
	std::cin >> s >> t;
	int n = std::min(s.size(), t.size());
	int ans = 0;
	while(ans < n && s[s.size() - ans - 1] == t[t.size() - ans - 1]) ans++;
	//std::cout << ans << std::endl;
	std::cout << (s.size() + t.size()) - 2 * ans << std::endl;
}