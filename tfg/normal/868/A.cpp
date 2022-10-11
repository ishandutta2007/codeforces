#include <iostream>
#include  <string>

const int ms = 1010;

std::string str[ms];

int main() {
	int n;
	bool ans = false;
	std::string pw;
	std::cin >> pw >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> str[i];
		ans = ans || str[i] == pw;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ans = ans || (str[i][1] == pw[0] && str[j][0] == pw[1]);
		}
	}
	std::cout << (ans ? "YES\n" : "NO\n");
}