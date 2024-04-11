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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		unordered_map<int, int> lastIndex;
		int mn = n + 1;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			auto it = lastIndex.find(x);
			if (it != lastIndex.end()) {
				mn = min(mn, i - it->second);
			}
			lastIndex[x] = i;
		}
		cout << n - mn << "\n";
	}
	return 0;
}