#include <iostream>

bool pali(std::string str) {
    //std::cout << str << "\n";
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != str[str.size() - 1 - i]) {
		    //std::cout << "got false\n";
			return false;
		}
	}
	//std::cout << "got true\n";
	return true;
}

int main() {
	std::string str;
	int k;
	std::cin >> str >> k;
	if(str.size() % k != 0) {
		std::cout << "NO\n";
		return 0;
	}
	bool valid = true;
	for(int i = 0; i < k; i++) {
		valid = valid && pali(str.substr(i * (str.size() / k), str.size() / k));
	}
	if(valid) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}