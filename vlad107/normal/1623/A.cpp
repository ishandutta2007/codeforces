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
		int n, m, rx, cx, ry, cy;
		cin >> n >> m >> rx >> cx >> ry >> cy;
		int cnt = 0;
		int vx = 1, vy = 1;
		while ((rx != ry) && (cx != cy)) {
			if ((rx + vx > n) || (rx + vx < 1)) {
				vx = -vx;
			}
			if ((cx + vy > m) || (cx + vy < 1)) {
				vy = -vy;
			}
			rx += vx;
			cx += vy;
			++cnt;
		}
		cout << cnt << "\n";
	}
	return 0;
}