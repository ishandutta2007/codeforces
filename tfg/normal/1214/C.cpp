#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	int sum = 0;
	int on = 0;
	while(on < n && sum >= 0) {
		sum += str[on++] == '(' ? 1 : -1;
	}
	if(sum < 0) {
		on = 0;
		while(str[on] == '(') {
			on++;
		}
		for(int i = on; i+1 < n; i++) {
			std::swap(str[i], str[i+1]);
		}
	}
	sum = on = 0;
	while(on < n && sum >= 0) {
		sum += str[on++] == '(' ? 1 : -1;
	}
	if(on == n && sum == 0) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}