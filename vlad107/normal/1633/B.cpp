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

bool check(const vector<vector<int>> &a, int m, int c) {
	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		while ((j + 1 < a.size()) && (a[j + 1][c] - a[i][c] <= m)) ++j;
		if ((a[j][c] == m) && (a[j][c^1] > m)) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;

		vector<vector<int>> a(s.size() + 1, vector<int>(2));
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < 2; j++) {
				a[i + 1][j] = a[i][j] + (s[i] - '0' == j);
			}
		}

		int l = 0;
		int r = (int)a.size();
		while (l < r - 1) {
			int m = (l + r) / 2;
			if (check(a, m, 0) || check(a, m, 1)) {
				l = m;
			} else {
				r = m;
			}
		}
		cout << l << "\n";
	}
	return 0;
}