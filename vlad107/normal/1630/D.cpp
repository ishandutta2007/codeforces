#include <numeric>
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

const long long MIN = numeric_limits<long long>::min();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int l = 0;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			l = gcd(l, x);
		}
		vector<array<long long, 2>> f(l, {0, MIN});
		for (int i = 0; i < n; i++) {
			int j = i % l;
			long long nf0 = f[j][0] + a[i];
			long long nf1 = f[j][0] - a[i];
			if (f[j][1] != MIN) {
				nf0 = max(nf0, f[j][1] - a[i]);
				nf1 = max(nf1, f[j][1] + a[i]);
			}
			f[j][0] = nf0;
			f[j][1] = nf1;
		}
		array<long long, 2> sumf {0, 0};
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < 2; j++) {
				if (f[i][j] == MIN) sumf[j] = MIN;
				if (sumf[j] == MIN) continue;
				sumf[j] += f[i][j];
			}
		}
		cout << max(sumf[0], sumf[1]) << "\n";
	}
	return 0;
}