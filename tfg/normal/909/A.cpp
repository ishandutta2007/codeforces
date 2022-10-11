#include <iostream>

int main() {
	std::string str[3];
	std::cin >> str[0] >> str[1];
	str[2] = str[0] + str[1];
	std::string cur;
	for(int i = 0; i < str[0].size(); i++) {
		cur += str[0][i];
		str[2] = std::min(cur + str[1][0], str[2]);
	}
	std::cout << str[2] << '\n';
}