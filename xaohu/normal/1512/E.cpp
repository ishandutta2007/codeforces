#include <bits/stdc++.h>

using namespace std;

int t, n, l, r, s, ans[505];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> l >> r >> s;
		int len = r - l + 1;
		int cur = len * (len + 1) / 2;
		map<int, int> vis;
		ans[len + 1] = n + 1;
		for (int i = len; 1 <= i; i--) {
			ans[i] = i;
			while (cur < s && ans[i] + 1 < ans[i + 1]) {
				ans[i]++;
				cur++;
			}
			vis[ans[i]] = 1;
		}
		if (cur != s) {
			cout << "-1\n";
			continue;
		}
		auto output = [&](int cnt) {
			for (int i = 1; i <= n; i++) {
				if (!vis[i] && cnt){ 
					vis[i] = 1;
					cnt--;
					cout << i << " ";
				}
			}
		};
		output(l - 1);
		for (int i = 1; i <= len; i++)
			cout << ans[i] << " ";
		output(n - r);
		cout << '\n';
	}
	return 0;
}