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
		int n, k;
		cin >> n >> k;
		if ((n % 2 == 1) && (k > 1)) {
			cout << "NO\n";
			continue;
		}
		if (((n * k) % 2 == 1) && (k != 1)) {
			cout << "NO\n";
			continue;
		}
		vector<vector<int>> a(n, vector<int>(k));
		vector<bool> used(n * k + 1);
		int firstNotUsed = 1;
		for (int i = 0; i < n; i++) {
			while (used[firstNotUsed]) firstNotUsed++;
			used[firstNotUsed] = 1;
			a[i][0] = firstNotUsed;
			long long sum = a[i][0];
			for (int j = 1; j < k; j++) {
				a[i][j] = a[i][j - 1] + 2;
				used[a[i][j]] = 1;
				sum += a[i][j];
				if ((sum % (j + 1) != 0) || (a[i][j] > n * k)) {
					throw "fatal";
					return 0;
				}
			}
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}