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
		int n;
		cin >> n;
		int numX = -1, maxDiffX = -1;

		map<tuple<int, int, int>, int> memDiff;
		auto memorizeDiff = [&](int x, int y, int z, int diff) {
			if (y > z) swap(y, z);
			memDiff[{x, y, z}] = diff;
		};

		for (int x = 3; x <= n; x++) {
			int diff;
			cout << "? " << "1 2 " << x << endl;
			cin >> diff;
			memorizeDiff(1, 2, x, diff);
			if (diff > maxDiffX) {
				maxDiffX = diff;
				numX = x;
			}
		}
		int numY = -1, maxDiffY = -1;
		for (int y = 3; y <= n; y++) {
			if (y == numX) continue;
			int diff;
			cout << "? " << "1 " << numX << " " << y << endl;
			cin >> diff;
			memorizeDiff(1, numX, y, diff);
			if (diff > maxDiffY) {
				maxDiffY = diff;
				numY = y;
			}
		}
		int diff;
		cout << "? " << "2 " << numX << " " << numY << endl;
		cin >> diff;
		memorizeDiff(2, numX, numY, diff);

		vector<int> candidates {1, 2, numX, numY};
		int ansI = -1, ansJ = -1;
		int maxDiff = -1;
		for (int i = 0; i < candidates.size(); i++) {
			for (int j = i + 1; j < candidates.size(); j++) {
				vector<int> diffs;
				for (int k = 0; k < candidates.size(); k++) {
					if ((k == i) || (k == j)) continue;
					vector<int> v {candidates[i], candidates[j], candidates[k]};
					sort(v.begin(), v.end());
					diffs.push_back(memDiff[{v[0], v[1], v[2]}]);
				}
				if ((diffs.back() == diffs.front()) && (diffs.back() > maxDiff)) {
					maxDiff = diffs.back();
					ansI = candidates[i];
					ansJ = candidates[j];
				}
			}
		}
		cout << "! " << ansI << " " << ansJ << endl;
	}
	return 0;
}