#include <iostream>
#include <string>
#include <cstdio>

bool dp[200200][10];
char buffer[200200];

std::string read_str() {
	scanf("%s", buffer);
	std::string str;
	for(int i = 0; buffer[i]; i++) {
		str += buffer[i];
	}
	return str;
}

int bits[1 << 10];

int main() {
	for(int i = 1; i < (1 << 10); i++) {
		bits[i] = bits[i / 2] + i % 2;
	}
	dp[0][0] = true;
	for(int i = 1; i < 200200; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][10] = dp[i - 1][9];
		for(int j = 1; j <= 9; j++) {
			dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j + 1];
		}
	}
	int t;
	std::cin >> t;
	while(t--) {
		std::string str = read_str();
		int n = str.size();
		int mask = 0;
		for(int i = 0; i < n; i++) {
			mask ^= 1 << (str[i] - '0');
		}
		bool special = str[0] == '1' && str.back() <= '1';
		for(int i = 1; i < n - 1; i++) {
			special = special && str[i] == '0';
		}
		if(special) {
			str = "";
			for(int i = 2; i < n; i++) {
				str += '9';
			}
			printf("%s\n", str.c_str());
			continue;
		}
		bool got = false;
		for(int i = n - 1; i >= 0 && !got; i--) {
			mask ^= 1 << (str[i] - '0');
			//std::cout << "mask for " << i << " is " << mask << "\n";
			for(int j = int(str[i] - '0') - 1; j >= 0 && !got; j--) {
				mask ^= 1 << j;
				//std::cout << "to " << j << " got mask " << mask << ", " << bits[mask] << "\n";
				if(dp[n - i - 1][bits[mask]]) {
					got = true;
					str[i] = j + '0';
					for(int k = i + 1; k < n; k++) {
						for(int d = 9; d >= 0; d--) {
							if(dp[n - k - 1][bits[mask ^ (1 << d)]]) {
								mask ^= 1 << d;
								str[k] = d + '0';
								break;
							}
						}
					}
				}
				mask ^= 1 << j;
			}
		}
		printf("%s\n", str.c_str());
	}
}