#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> pos(n + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pos[a] = i;
	}
	
	vector<int> cnt(n, 1);
	vector<bool> vstd(n);
	multiset<int> s;
	for (auto i : cnt) {
		s.insert(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (cnt[pos[i]] != *s.rbegin()) {
			cout << "No" << '\n';
			return;
		}
		if (pos[i] + 1 < n && !vstd[pos[i] + 1]) {
			s.erase(s.find(cnt[pos[i] + 1]));
			cnt[pos[i] + 1] += cnt[pos[i]];
			s.insert(cnt[pos[i] + 1]);
		}
		s.erase(s.find(cnt[pos[i]]));
		cnt[pos[i]] = 0;
		vstd[pos[i]] = true;
	}
	cout << "Yes" << '\n';
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