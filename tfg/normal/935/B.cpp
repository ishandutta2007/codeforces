#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	int x = 0, y = 0;
	int ans = 0;
	for(int i = 0; i < str.size(); i++) {
		if(x == y && i && str[i] == str[i - 1]) {
			ans++;
		}
		(str[i] == 'R' ? x : y)++;
	}
	std::cout << ans << '\n';
}