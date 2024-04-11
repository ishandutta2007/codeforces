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

bool check(int x, int y) {
	if (y == 0) return false;
	int m = abs(y) / abs(x);
	return (m * 1LL * x == y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b, c;
		cin >> a >> b >> c;
		int res = check(c, b + (b - a)) || check(a, b + (b - c));
		if ((c - a) % 2 == 0) {
			res = res || check(b, (a + c) / 2);
		}
		cout << (res ? "YES\n" : "NO\n");
	}
	return 0;
}