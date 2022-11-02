#include <bits/stdc++.h>

int main() {
	int T; std::cin >> T;
	while (T--) {
		int n; std::string s; std::cin >> n >> s;
		std::sort(s.begin(), s.end());
		std::cout << s << std::endl;
	}
}