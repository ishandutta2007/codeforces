#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int get(char c) {
	if('0' <= c && c <= '9') return 0;
	else if('a' <= c && c <= 'z') return 1;
	else return 2;
}

std::string solve(std::string str) {
	int freq[3] = {0, 0, 0};
	for(auto c : str) {
		freq[get(c)]++;
	}
	//std::cout << "freqs are (" << freq[0] << ", " << freq[1] << ", " << freq[2] << ")\n";
	if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
		return str;
	}
	int n = (int) str.size();
	for(int j = 1; j <= 3; j++) {
		for(int i = 0; i + j <= n; i++) {
			for(int k = 0; k < j; k++) {
				freq[get(str[i + k])]--;
			}
			int zero = 0;
			for(int k = 0; k < 3; k++) {
				if(freq[k] == 0) {
					zero++;
				}
			}
			if(zero <= j) {
				//std::cout << "entered here on " << i << ", " << j << std::endl;
				int need = 0;
				for(int k = 0; k < j; k++) {
					while(need < 2 && freq[need] > 0) {
						need++;
					}
					//std::cout << "needs " << need << std::endl;
					if(need == 0) {
						str[i + k] = '0';
					} else if(need == 1) {
						str[i + k] = 'a';
					} else {
						str[i + k] = 'A';
					}
					freq[need]++;
				}
				return str;
			}
			for(int k = 0; k < j; k++) {
				freq[get(str[i + k])]++;
			}
		}
	}
	return "!!!!!!!!";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::string str;
		std::cin >> str;
		std::cout << solve(str) << std::endl;
	}
}