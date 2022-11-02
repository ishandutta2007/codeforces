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
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int first = -1, last = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] != i + 1) {
				first = i;
				break;
			}
		}
		if (first != -1) {
			for (int i = first; i < n; i++) {
				if (a[i] == first + 1) {
					last = i;
					break;
				}
			}
			reverse(a.begin() + first, a.begin() + last + 1);
		}
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}