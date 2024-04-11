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
		int n, x;
		long long y;
		cin >> n >> x >> y;
		int u = x % 2;
		int v = y % 2;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			a %= 2;
			u ^= a;
		}
		if (u == v) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
	return 0;
}