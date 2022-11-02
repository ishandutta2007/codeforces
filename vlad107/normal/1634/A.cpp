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
		string s;
		cin >> s;
		string revS(s.rbegin(), s.rend());
		if (k == 0) {
			cout << 1 << "\n";
		} else if (s == revS) {
			cout << 1 << "\n";
		} else {
			cout << 2 << "\n";
		}
	}
	return 0;
}