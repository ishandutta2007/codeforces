#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

int main() {
	int n;
	std::string str;
	std::cin >> n >> str;
	std::map<std::string, int> freq;
	int ans = 0;
	std::string a;
	for(int i = 0; i + 1 < n; i++) {
		freq[str.substr(i, 2)]++;
		if(freq[str.substr(i, 2)] > ans) {
			ans = freq[str.substr(i, 2)];
			a = str.substr(i, 2);
		}
	}
	std::cout << a << std::endl;
}