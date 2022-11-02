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
		int mn = 1e9 + 1, mx = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mx = max(mx, x);
			mn = min(mn, x);
		}
		cout << mx - mn << "\n";
	}
	return 0;
}