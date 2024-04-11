#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::string str;
	std::cin >> n >> str;
	auto want = str;
	std::sort(want.begin(), want.end());
	//std::cout << str << " wants " << want << '\n';
	for(char i = '0'; i <= '9'; i++) {
		std::string a, b;
		std::string ans;
		for(auto c : str) {
			if(c < i) {
				a += c;
				ans += '1';
			} else if(c > i) {
				b += c;
				ans += '2';
			} else if(b.empty() || b.back() <= i) {
				b += c;
				ans += '2';
			} else {
				a += c;
				ans += '1';
			}
		}
		if(a + b == want) {
			std::cout << ans << '\n';
			//std::cout << a << '\n' << b << '\n';
			return;
		}
	}
	std::cout << "-\n";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}