#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 1e9;
		array<int, 3> triple;
		for (int i = 1; i < 2 * a; ++i) {
			for (int j = i; j < 2 * b; j += i) {
				int k = c / j * j;
				if (k < j || abs(c - k) > abs(c - (k + j))) {
					k += j;
				}
				int res = abs(a - i) + abs(b - j) + abs(c - k);
				if (res < ans) {
					ans = res;
					triple = {i, j, k};
				}
			}
		}
		cout << ans << '\n';
		for (auto i : triple) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}