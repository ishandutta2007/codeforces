#include <iostream>
#include <string>

int main() {
	int n;
	std::string str;
	std::cin >> n >> str;
	bool valid = true;
	for(int i = 0; i < n; i++) {
		if(str[i] == '1') {
			bool adj = false;
			if(i) {
				adj = adj || str[i - 1] == '1';
			}
			if(i + 1 < n) {
				adj = adj || str[i + 1] == '1';
			}
			valid = valid && !adj;
		} else {
			bool adj = false;
			if(i) {
				adj = adj || str[i - 1] == '1';
			}
			if(i + 1 < n) {
				adj = adj || str[i + 1] == '1';
			}
			valid = valid && adj;
		}
	}
	std::cout << (valid ? "Yes\n" : "No\n");
}