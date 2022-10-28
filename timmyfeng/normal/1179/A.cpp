#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	deque<int> dq;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		dq.push_back(a);
	}

	vector<pair<int, int>> ans(n);
	for (int i = 0; i < n; ++i) {
		int a = dq[0];
		int b = dq[1];
		dq.pop_front();
		dq.pop_front();
		ans[i] = {a, b};

		if (a > b) {
			swap(a, b);
		}
		dq.push_front(b);
		dq.push_back(a);
	}

	for (int i = 0; i < q; ++i) {
		long long m;
		cin >> m;
		--m;
		if (m < n) {
			cout << ans[m].first << " " << ans[m].second << "\n";
		} else {
			m -= n;
			cout << dq[0] << " " << dq[1 + m % (n - 1)] << "\n";
		}
	}
}