#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;
	vector<int> cnt(n + 2);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cnt[a];
	}

	int mn = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i]) {
			++mn;
			i += 2;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!cnt[i])
			continue;
		if (!cnt[i - 1]) {
			--cnt[i];
			++cnt[i - 1];
		}
		if (cnt[i] > 1) {
			--cnt[i];
			++cnt[i + 1];
		}
	}

	cout << mn << ' ' << n + 2 - count(cnt.begin(), cnt.end(), 0) << '\n';
}