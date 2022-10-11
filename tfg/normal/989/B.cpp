#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, p;
	std::string str;
	std::cin >> n >> p >> str;
	std::vector<int> freq[2];
	freq[0] = freq[1] = std::vector<int>(p, 0);
	for(int i = 0; i < n; i++) {
		char c = str[i];
		if(c != '.') {
			freq[c - '0'][i % p]++;
		}
	}
	for(int i = 0; i < n; i++) {
		char c = str[i];
		if(c == '.') {
			int f = freq[0][i % p] ? 1 : 0;
			str[i] = '0' + f;
			freq[f][i % p]++;
		}
	}
	bool valid = false;
	for(int i = 0; i + p < n; i++) {
		valid = valid || str[i] != str[i + p];
	}
	std::cout << (valid ? str : "No") << std::endl;
}