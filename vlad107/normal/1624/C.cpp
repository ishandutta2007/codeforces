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
		vector<bool> used(n + 1);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			while (x > n) x /= 2;
			while ((x >= 1) && (used[x])) x /= 2;
			used[x] = true;
		}
		bool bad = false;
		for (int i = 1; i <= n; i++) {
			if (!used[i]) {
				bad = true;
			}
		}
		cout << (bad ? "NO" : "YES") << "\n";
	}
	return 0;
}