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

const int BASE = 998244353;
const int MAXN = 200010;

std::array<int, MAXN> used_row, used_column;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k, q;
		std::cin >> n >> m >> k >> q;
		std::vector<std::pair<int, int>> qs(q);
		for (size_t i = 0; i < qs.size(); ++i) {
			std::cin >> qs[i].first >> qs[i].second;
			--qs[i].first;
			--qs[i].second;
		}
		int res = 1;
		int filled_rows = 0;
		int filled_cols = 0;
		for (size_t i = 0; i < qs.size(); i++) {
			int row = qs[qs.size() - 1 - i].first;
			int col = qs[qs.size() - 1 - i].second;
			if ((!used_row[row]) || (!used_column[col])) {
				res = (res * 1LL * k) % BASE;
			}
			filled_rows += (!used_row[row]);
			filled_cols += (!used_column[col]);
			used_row[row] = true;
			used_column[col] = true;
			if (filled_rows == n) break;
			if (filled_cols == m) break;
		}
		std::cout << res << "\n";

		for (size_t i = 0; i < qs.size(); i++) {
			used_row[qs[i].first] = false;
			used_column[qs[i].second] = false;
		}
	}
	return 0;
}