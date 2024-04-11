#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	bool valid = false;
	for(int i = 0; i + 3 <= str.size(); i++) {
		std::string wut = str.substr(i, 3);
		std::sort(wut.begin(), wut.end());
		valid = valid || wut == "ABC";
	}
	std::cout << (valid ? "YES\n" : "NO\n");
}