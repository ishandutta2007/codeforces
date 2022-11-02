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
		int n, x;
		std::cin >> n >> x;
		std::vector<int> a(n);
		for (size_t i = 0; i < a.size(); ++i) {
			std::cin >> a[i];
		}
		std::vector<int> pref_sum(n + 1);
		for (size_t i = 0; i < a.size(); ++i) {
			pref_sum[i + 1] = pref_sum[i] + a[i];
		}

		std::vector<int> max_s(n + 1);
		for (size_t len = 1; len <= a.size(); ++len) {
			max_s[len] = pref_sum[len];
			for (int i = 1; i + len <= a.size(); ++i) {
				max_s[len] = std::max(max_s[len], pref_sum[i + len] - pref_sum[i]);
			}
		}

		std::vector<int> f(n + 1);
		f.back() = max_s.back();
		for (size_t i = 1; i < f.size(); ++i) {
			f[f.size() - 1 - i] = std::max(f[f.size() - i], max_s[f.size() - 1 - i]);
		}
		for (size_t i = 0; i < f.size(); ++i) {
			f[i] = f[i] + x * i;
		}
		for (size_t i = 1; i < f.size(); ++i) {
			f[i] = std::max(f[i], f[i - 1]);
		}
		for (size_t i = 0; i < f.size(); ++i) {
			std::cout << f[i] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}