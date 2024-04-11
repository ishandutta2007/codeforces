#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	long long a, b;
	std::cin >> str >> a >> b;
	int n = (int) str.size();
	std::vector<int> pref(n + 1, 0);
	for(int i = 0; i < n; i++) {
		pref[i+1] = (pref[i] * 10 + str[i] - '0') % a;
	}
	long long cur = 1;
	long long sum = 0;
	for(int i = n-1; i > 0; i--) {
		sum = (sum + cur * (str[i] - '0')) % b;
		cur = cur * 10 % b;
		if(sum % b == 0 && pref[i] % a == 0 && (str[i] != '0') && str[0] != '0') {
			std::cout << "YES\n" << str.substr(0, i) << "\n" << str.substr(i, n-i) << '\n';
			return 0;
		}
	}
	std::cout << "NO\n";
}