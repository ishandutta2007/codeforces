#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> s(n);
	for (auto& i : s) {
		cin >> i;
	}
	sort(s.begin(), s.end());

	map<long long, int> mp;
	for (int i = 1; i < n; ++i) {
		++mp[s[i] - s[i - 1]];
	}
	++mp[INF];

	int q;
	cin >> q;
	vector<pair<long long, int>> req;
	for (int i = 0; i < q; ++i) {
		long long l, r;
		cin >> l >> r;
		req.emplace_back(r - l + 1, i);
	}
	sort(req.begin(), req.end());

	int cur = 0;
	int cnt = n;
	long long sum = 0;
	vector<long long> ans(q);
	for (auto [x, y] : mp) {
		while (cur < q && req[cur].first <= x) {
			ans[req[cur].second] = cnt * req[cur].first + sum;
			++cur;
		}
		sum += x * y;
		cnt -= y;
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}