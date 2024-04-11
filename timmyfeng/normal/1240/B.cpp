#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int cnt = 0;
	vector<int> a(n), first(n + 1, -1), last(n + 1);
	for (auto& i : a) {
		cin >> i;
	}
	for (int i = 0; i < n; ++i) {
		if (first[a[i]] == -1) {
			first[a[i]] = i;
			++cnt;
		}
		last[a[i]] = i;
	}
	
	int cur = 0, prev = -1, best = 0;
	for (int i = 1; i <= n; ++i) {
		if (first[i] == -1) continue;
		if (first[i] > prev) {
			best = max(best, ++cur);
		} else {
			cur = 1;
		}
		prev = last[i];
	}
	cout << cnt - best << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}