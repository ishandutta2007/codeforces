#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i=  0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end(), greater<pair<int, int>>());

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += i * a[i].first + 1;
	}
	cout << ans << '\n';
	for (int i = 0 ;i < n; ++i) {
		cout << a[i].second + 1 << ' ';
	}
	cout << '\n';
}