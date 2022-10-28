#include <bits/stdc++.h> 
using namespace std;

vector<int> calc(vector<pair<int, int>> vals, const vector<int>& a) {
	int n = a.size();
	int m = vals.size();
	vector<int> res(m);
	for (int i = m - 1; i >= 0; --i) {
		int cur = i;
		for (int j = n - 1; j >= 0; --j) {
			if (a[j] == vals[cur].first) {
				++res[i];
				--cur;
			}
		}
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for (auto& i : a) {
		cin >> i;
		++mp[i];
	}

	vector<pair<int, int>> vals(mp.begin(), mp.end());	
	vector<int> pre = calc(vals, a);
	reverse(vals.begin(), vals.end());
	reverse(a.begin(), a.end());
	vector<int> suf = calc(vals, a);
	reverse(suf.begin(), suf.end());

	int ans = n - max(pre.back(), suf[0]);
	for (int i = 1; i < int(vals.size()); ++i) {
		ans = min(ans, n - max(suf[i], pre[i - 1]));
	}
	cout << ans << "\n";
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