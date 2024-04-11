#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>
#include <type_traits>
#include <exception>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::iota(a.begin(), a.end(), 1);
		if (a.size() >= 4) {
			std::swap(a[2], a[3]);
		}
		size_t cnt_printed = 0;
		do {
			bool is_anti_fib = true;
			for (size_t i = 2; i < a.size(); ++i) {
				if (a[i - 1] + a[i - 2] == a[i]) {
					is_anti_fib = false;
					break;
				}
			}
			if (is_anti_fib) {
				for (size_t i = 0; i < a.size(); i++) std::cout << a[i] << " ";
				std::cout << "\n";
				++cnt_printed;
				if (cnt_printed == n) {
					break;
				}
			}
		} while (std::next_permutation(a.begin(), a.end()));
	}
	return 0;
}