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
		bool bad = false;
		int maxA[2] {-1, -1};
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			int par = x % 2;
			if (maxA[par] > x) {
				bad = true;
			}
			maxA[par] = max(maxA[par], x);
		}
		puts(bad ? "No" : "Yes");
	}
	return 0;
}