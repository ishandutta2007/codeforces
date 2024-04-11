#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	vector<int> a(n);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> events;
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> a[i] >> b;
		events.emplace(b, i);
	}

	int cnt = count(s.begin(), s.end(), '1');
	int ans = cnt;
	int pre = 0;
	while (!events.empty() && events.top().first <= 500) {
		auto [t, i] = events.top();
		events.pop();

		if (t != pre) {
			ans = max(ans, cnt);
		}
		events.emplace(t + a[i], i);

		if (s[i] == '1') {
			s[i] = '0';
			--cnt;
		} else {
			s[i] = '1';
			++cnt;
		}

		pre = t;
	}
	cout << ans << "\n";
}