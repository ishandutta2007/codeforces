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

int ans;

void slow(int a, int b, int cur) {
	if (cur >= ans) return;
	if (a == b) {
		ans = min(ans, cur);
		return;
	}
	slow(a + 1, b, cur + 1);
	slow(a, b + 1, cur + 1);
	slow(a | b, b, cur + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		int res = b - a;

		int pw = 1;
		while (pw <= b) {
			if ((pw & a) == 0) {
				int aa = pw | a;
				int pw2 = 1;
				while (pw2 != pw) {
					if ((aa & pw2) == pw2) {
						aa ^= pw2;
					}
					pw2 += pw2;
				}
				res = min(res, (aa - a) + 1 + ((b | aa) - b));
			}
			pw += pw;
		}

		for (int i = 0; i <= res; i++) {
			int bb = b + i;
			res = min(res, bb - a + i);
			res = min(res, (a | bb) - bb + 1 + i);
		}
		cout << res << "\n";
	}
	return 0;
}