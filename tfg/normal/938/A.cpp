#include <iostream>
#include <string>

bool vowel(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y';
}

int main() {
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	std::cout << str[0];
	for(int i = 1; i < n; i++) {
		if(vowel(str[i]) && vowel(str[i - 1])) {
			continue;
		}
		std::cout << str[i];
	}
	std::cout << '\n';
}