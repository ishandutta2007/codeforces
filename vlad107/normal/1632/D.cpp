#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <numeric>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <array>
#include <limits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int m = 1;
	while ((1<<m) <= n) ++m;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		g[i][0] = a[i];
		for (int j = 1; j < m; j++) {
			int pi = (i - (1<<(j - 1)));
			if (pi >= 0) {
				g[i][j] = gcd(g[i][j - 1], g[pi][j - 1]);
			} else {
				g[i][j] = g[i][j - 1];
			}
		}
	}
	vector<int> delta(n);
	int lastRemoved = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			++delta[i];
			lastRemoved = i;
		} else {
			int x = a[i];
			bool bad = false;
			int pj = i;
			while (pj > lastRemoved) {
				int len = 0;
				for (int j = m - 1; j >= 0; j--) {
					if ((i - (len + (1<<j)) + 1 > lastRemoved) && (g[i-len][j] % x == 0)) {
						len += (1<<j);
					}
				}
				int pi = i - len + 1;
				// for [pi;i]..[pj;i] gcd is x
				int px = i - x + 1;
				if ((pi <= px) && (px <= pj)) {
					bad = true;
					break;
				}
				pj = pi - 1;
				if (pj > lastRemoved) {
					x = gcd(x, a[pj]);
				}
			}
			if (bad) {
				++delta[i];
				lastRemoved = i;
			}
		}
	}
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += delta[i];
		cout << total << " ";
	}
	cout << endl;
	return 0;
}