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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int x = n - 1;
		int cnt = 0;
		while (x > 0) {
			while ((x - 1 >= 0) && (a[x - 1] == a[n - 1])) --x;
			if (x == 0) break;
			++cnt;
			x -= (n - x);
		}
		cout << cnt << "\n";
	}
	return 0;
}