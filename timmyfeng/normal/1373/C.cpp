#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();

		int init = 0;
		int cur = 0;
		long long res = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '+') {
				++cur;
			} else {
				--cur;
			}
			if (init + cur < 0) {
				++init;
				res += i + 1;
			}
		}
		res += n;

		cout << res << "\n";
	}
}