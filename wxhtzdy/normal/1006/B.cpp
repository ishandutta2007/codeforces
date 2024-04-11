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
	sort(b.rbegin(), b.rend());
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += b[i].first;
	}
	vector<int> c;
	c.push_back(-1);
	for (int i = 0; i < k; i++) {
		c.push_back(b[i].second);
	}
	sort(c.begin(), c.end());
	cout << ans << '\n';
	for (int i = 1; i < (int) c.size() - 1; i++) {
		cout << c[i] - c[i - 1] << " ";
	}
	cout << c[(int) c.size() - 1] - c[(int) c.size() - 2] + n - c[(int) c.size() - 1] - 1; 
	return 0;
}