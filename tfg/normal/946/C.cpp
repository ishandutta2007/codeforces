#include <iostream>
#include <string>

int main() {
	std::string str;
	std::cin >> str;
	char cur = 'a';
	for(int i = 0; i < str.size(); i++) {
		if(str[i] <= cur) {
			str[i] = cur++;
			if(cur > 'z') {
				std::cout << str << '\n';
				return 0;
			}
		}
	}
	std::cout << "-1\n";
}