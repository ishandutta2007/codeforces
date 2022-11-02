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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long hc, dc;
		cin >> hc >> dc;
		long long hm, dm;
		cin >> hm >> dm;
		long long k, w, a;
		cin >> k >> w >> a;
		bool found = false;
		for (int i = 0; i <= k; i++) {
			long long Hc = hc + i * a;
			long long Dc = dc + (k - i) * w;
			long long stepC = (hm - 1) / Dc + 1;
			long long stepM = (Hc - 1) / dm + 2;
			if (stepC < stepM) {
				found = true;
				break;
			}
		}
		cout << (found ? "YES" : "NO") << "\n";
	}
	return 0;
}