#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> p(n), q(n);
	for (auto& i : p) {
		cin >> i;
	}
	for (auto& i : q) {
		cin >> i;
	}

	int cnt = 0, off = 0;
	vector<int> ans(n);
	vector<bool> seen_p(n + 1), seen_q(n + 1);
	for (int i = 0; i < n; ++i) {
		seen_p[p[i]] = true;
		if (seen_q[p[i]]) {
			--off;
			ans[p[i] - 1] = cnt;
		} else {
			++off;
		}

		seen_q[q[i]] = true;
		if (seen_p[q[i]]) {
			--off;
			ans[q[i] - 1] = cnt;
		} else {
			++off;
		}

		cnt += !off;
	}

	if (cnt < k) {
		cout << "NO" << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	for (auto i : ans) {
		if (i >= 26) {
			cout << 'z';
		} else {
			cout << char('a' + i);
		}
	}
}