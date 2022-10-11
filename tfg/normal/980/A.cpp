#include <iostream>
#include <vector>

int main() {
	std::string str;
	std::cin >> str;
	int freq[2] = {0, 0};
	for (auto c : str) {
		freq[c == 'o' ? 1 : 0]++;
	}
	if(freq[1] == 0 || freq[0] % freq[1] == 0) std::cout << "YES\n";
	else std::cout << "NO\n";
}