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
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (a[n - 2] > a[n - 1]) {
			cout << "-1\n";
			continue;
		}
		vector<int> res;
		bool bad = false;
		for (int i = n - 3; i >= 0; i--) {
			if (a[i] > a[i + 1]) {
				res.push_back(i);
				a[i] = a[i + 1] - a.back();
				if (a[i] > a[i + 1]) {
					bad = true;
					break;
				}
			}
		}
		if (bad) {
			cout << "-1\n";
			continue;
		}
		cout << res.size() << "\n";
		for (int x : res) {
			cout << x + 1 << " " << x + 2 << " " << n << "\n";
		}
	}
	return 0;
}