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

int cost(const vector<int> &p) {
	int maxDiff = 0;
	for (int i = 0; i + 1 < p.size(); i++) {
		int diff = p[i] ^ p[i + 1];
		maxDiff = max(maxDiff, diff);
	}
	return maxDiff;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> ans;
		int pw = 1;
		while (pw + pw < n) pw += pw;
		for (int i = pw - 1; i >= 0; i--) ans.push_back(i);
		for (int i = pw; i < n; i++) ans.push_back(i);
		for (int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}