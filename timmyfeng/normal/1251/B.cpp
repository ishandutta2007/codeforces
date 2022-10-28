#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int odd = 0, even = 0, one = 0;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			if ((int)s.size() % 2) {
				++odd;
			} else {
				++even;
			}
			one += count(s.begin(), s.end(), '1');
		}
		if (odd || one % 2 == 0) {
			cout << n << '\n';
		} else {
			cout << n - 1 << '\n';
		}
	}
}