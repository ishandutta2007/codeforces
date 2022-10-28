#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		string s; cin >> s;
		int n = s.size();
		int low = 0, high = n;
		while (low < high) {
			int mid = (low + high) / 2;

			int right = n, ones = 0, zeroes = count(s.begin(), s.end(), '0');
			while (right > 0 && ones + (s[right - 1] == '1') <= mid)
				--right, ones += s[right] == '1', zeroes -= s[right] == '0';

			bool ok = max(ones, zeroes) <= mid;
			for (int left = 0; left < n; ++left) {
				ones += s[left] == '1';
				zeroes -= s[left] == '0';
				while (right < n && ones > mid) {
					ones -= s[right] == '1';
					zeroes += s[right] == '0';
					++right;
				}

				ok |= max(ones, zeroes) <= mid;
			}

			if (ok) high = mid;
			else low = mid + 1;
		}

		cout << low << "\n";
	}
}