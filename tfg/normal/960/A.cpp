#include <iostream>
#include <algorithm>

int freq[3];

int main() {
	std::string str[2];
	std::cin >> str[0];
	str[1] = str[0];
	std::sort(str[1].begin(), str[1].end());
	for(auto a : str[0]) freq[a - 'a']++;
	if(std::min(freq[0], freq[1]) > 0 && (freq[2] == freq[0] || freq[2] == freq[1]) && str[1] == str[0]) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}