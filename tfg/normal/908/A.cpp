#include <iostream>
#include <string>

int get(char x) {
	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || ('0' <= x && x <= '9' && int(x - '0') % 2 == 1)) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	std::string str;
	std::cin >> str;
	int ans = 0;
	for(auto a : str) {
		ans += get(a);
	}
	std::cout << ans << '\n';
}