#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<int> inc(n), dec(n);
	inc[n - 1] = 1;
	for (int i = n - 2; ~i; --i) {
		if (a[i] < a[i + 1]) {
			inc[i] = inc[i + 1] + 1;
		} else {
			inc[i] = 1;
		}
	}
	dec[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) {
			dec[i] = dec[i - 1] + 1;
		} else {
			dec[i] = 1;
		}
	}

	int ans = *max_element(inc.begin(), inc.end());
	for (int i = 1; i < n - 1; ++i) {
		if (a[i - 1] < a[i + 1]) {
			ans = max(ans, dec[i - 1] + inc[i + 1]);
		}
	}
	cout << ans << '\n';
}