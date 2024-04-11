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

const int MAX = numeric_limits<int>::max();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, l, k;
	cin >> n >> l >> k;
	vector<int> d(n);
	vector<int> a(n);
	for (int &x : d) cin >> x;
	for (int &x : a) cin >> x;
	d.push_back(l);
	a.push_back(0);
	vector<vector<int>> f(n + 1, vector<int>(n + 1, MAX));
	f[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (f[i][j] != MAX) {
				for (int nextI = i + 1; (nextI <= n) && (j + nextI - i - 1 <= k); nextI++) {
					int nextK = j + (nextI - i - 1);
					f[nextI][nextK] = min(f[nextI][nextK], f[i][j] + a[i] * (d[nextI] - d[i]));
				}
			}
		}
	}
	int res = MAX;
	for (int i = 0; i <= k; i++) res = min(res, f[n][i]);
	cout << res << endl;
	return 0;
}