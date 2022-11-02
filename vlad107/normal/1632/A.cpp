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
		int len;
		cin >> len;
		string s;
		cin >> s;
		int cnt0 = count(s.begin(), s.end(), '0');
		int cnt1 = len - cnt0;
		if (s.size() > 2) {
			cout << "NO\n";
		} else if (s.size() == 1) {
			cout << "YES\n";
		} else if ((cnt0 == 2) || (cnt1 == 2)) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
	return 0;
}