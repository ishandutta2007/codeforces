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

const int N = 1100;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> cost(N, N);
	cost[1] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= i; j++) {
		  if (i + i/j < N) {
			  cost[i + i/j] = min(cost[i + i/j], cost[i] + 1);
		  }
		}
	}
	int mx = 0;
	for (int i = 1; i < N; i++) mx = max(mx, cost[i]);

	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		k = min(k, n * mx);
		vector<int> b(n), c(n);
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) cin >> c[i];
		vector<int> p(k + 1, -1);
		p[0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = k - cost[b[i]]; j >= 0; j--) {
				if (p[j] != -1) p[j + cost[b[i]]] = max(p[j + cost[b[i]]], p[j] + c[i]);
			}
		}
		int res = 0;
		for (const auto &x : p) {
			res = max(res, x);
		}
		cout << res << "\n";
	}
	return 0;
}