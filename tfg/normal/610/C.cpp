#include <iostream>
#include <cstdio>
#include <vector>

std::string inv(std::string str) {
	for(int i = 0; i < str.size(); i++) {
		str[i] = (str[i] == '*' ? '+' : '*');
	}
	return str;
}

std::vector<std::string> ans[10];

int main() {
	int n;
	std::cin >> n;
	ans[0].push_back("+");
	for(int i = 1; i <= n; i++) {
		for(auto a : ans[i - 1]) {
			ans[i].push_back(a + a);
			ans[i].push_back(a + inv(a));
		}
	}
	for(auto a : ans[n]) {
		printf("%s\n", a.c_str());
	}
}