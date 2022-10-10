#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	{
		int bal = 0;
		for(auto c : str) {
			bal += c == '(' ? 1 : -1;
		}
		if(bal != -2 && bal != 2) {
			//std::cout << "balance is " << bal << "\n";
			std::cout << "0\n";
			return 0;
		}
		if(bal == -2) {
			std::reverse(str.begin(), str.end());
			for(auto &c : str) {
				c = c == '(' ? ')' : '(';
			}
		}
	}
	//std::cout << "testing " << str << '\n';
	int r = n-1;
	int bal = 0;
	while(r >= 0 && bal >= 0) {
		bal += str[r--] == ')' ? 1 : -1; 
	}
	//std::cout << "r is " << r << "\n";
	bal = 0;
	int ans = 0;
	for(int i = 0; i < n && bal >= 0; i++) {
		// test position i
		if(i > r && str[i] == '(' && bal > 0) {
			ans++;
		}
		// add balance
		bal += str[i] == '(' ? 1 : -1;
	}
	std::cout << ans << '\n';
}