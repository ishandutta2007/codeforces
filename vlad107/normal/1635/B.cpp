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
		vector<int> a(n);
		for (int &x : a) cin >> x;
		int cnt = 0;
		for (int i = 1; i + 1 < n; i++) {
			int mx = max(a[i - 1], a[i + 1]);
			if (a[i] > mx) {
				a[i + 1] = a[i];
				if ((i + 2 < n) && (a[i + 2] > a[i + 1])) {
					a[i + 1] = a[i + 2];
				}
				++cnt;
			}
		}
		cout << cnt << "\n";
		for (int i =0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}