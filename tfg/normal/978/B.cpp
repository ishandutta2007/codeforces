#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	int ans = 0;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && str[l] == str[r]) r++;
		if(str[l] == 'x') ans += std::max(0, r - l - 2);
	}
	std::cout << ans << std::endl;
}