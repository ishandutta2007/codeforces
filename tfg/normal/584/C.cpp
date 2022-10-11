#include <iostream>
#include <string>

int main() {
	std::string str[2];
	int n, t;
	std::cin >> n >> t;
	int type[2];
	type[0] = type[1] = 0;
	std::cin >> str[0] >> str[1];
	for(int i = 0; i < n; i++) {
		type[str[0][i] == str[1][i] ? 0 : 1]++;
	}
	std::string ans = str[0];
	int state = 0;
	if(type[1] / 2 + type[0] < t || type[1] % 2 == 1) {
		state = -1;
	}
	//std::cout << "starting on " << state << '\n';
	if(t + state < 0 || t + state < type[1] / 2) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		if(str[0][i] != str[1][i]) {
			if(state == -1) {
				type[1]--;
				while(ans[i] == str[0][i] || ans[i] == str[1][i]) {
					ans[i] = ans[i] == 'z' ? 'a' : ans[i] + 1;
				}
				t--;
				if(type[1] & 1) {
					state = -1;
				} else if(t <= type[1] / 2 + type[0]) {
					state = 0;
				} else {
					state = -1;
				}
			} else if(state == 0) {
				state = 1;
			} else {
				state = 0;
				ans[i] = str[1][i];
				t--;
			}
		}
	}
	for(int i = 0; i < n && t; i++) {
		if(str[0][i] == str[1][i]) {
			t--;
			ans[i] = str[0][i] == 'a' ? 'b' : 'a';
		}
	}
	std::cout << ans << '\n';
}