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
#include <array>
#include <limits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string nStr = to_string(n);

		int ans = -1;
		int minCnt = nStr.size() + 1;
		for (int x = 1; x <= 999; x++) {
			if (x % 7 != 0) continue;
			string xStr = to_string(x);
			if (nStr.size() != xStr.size()) continue;
			int cnt = 0;
			for (int j = 0; j < nStr.size(); j++) {
				if (nStr[j] != xStr[j]) ++cnt;
			}
			if (cnt < minCnt) {
				minCnt = cnt;
				ans = x;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}