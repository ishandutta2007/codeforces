#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> cnt(20);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int j = 0; j < 20; ++j) {
			if (a & (1 << j)) {
				++cnt[j];
			}
		}
	}

	long long ans=  0;
	while (count(cnt.begin(), cnt.end(), 0) != 20) {
		long long num = 0;
		for (int i = 0; i < 20; ++i) {
			if (cnt[i]) {
				--cnt[i];
				num |= 1 << i;
			}
		}
		ans += num * num;
	}
	cout << ans << "\n";
}