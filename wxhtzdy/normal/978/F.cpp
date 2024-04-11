#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<pair<int, int> > b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
	}
	sort(b.begin(), b.end());
	vector<int> ans(n, 0);
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		ans[b[i].second] = i - cnt[b[i].first];
		cnt[b[i].first]++;
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		if (a[x] == a[y]) {
			continue;
		}
		if (a[x] > a[y]) {
			ans[x]--;
		} else {
			ans[y]--;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}