#include <iostream>
#include <string>

int pal[60][60];

int main() {
	std::string str;
	std::cin >> str;
	int n = str.size();
	for(int i = 0; i < n; i++) {
		pal[i][i] = true;
		if(i + 1 < n && str[i] == str[i + 1]) {
			pal[i][i + 1] = true;
		}
	}
	int ans = 0;
	for(int i = n - 1; i >= 0; i--) {
		for(int j = i + 2; j < n; j++) {
			pal[i][j] = pal[i + 1][j - 1] && str[i] == str[j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			//std::cout << pal[i][j] << ' ';
			if(!pal[i][j]) {
				ans = std::max(ans, j - i + 1);
			}
		}
		//std::cout << std::endl;
	}
	std::cout << ans << std::endl;
}