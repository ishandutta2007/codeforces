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
		std::string s;
		std::cin >> s;
		bool ok = true;
		for (size_t i = 0; i < s.size(); ++i) {
			if ((s[i] >= 'A') && (s[i] <= 'Z')) {
				char need = s[i] - 'A' + 'a';
				bool found = false;
				for (size_t j = 0; j < i; j++) {
					if (s[j] == need) {
						found = true;
						break;
					}
				}
				if (!found) {
					ok = false;
					break;
				}
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}