#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	a.push_back(MX);

	int ans = MX - a[0];
	for (int i = 0; i < n; ++i) {
		ans = min(ans, max(a[i] - 1, MX - a[i + 1]));
	}
	cout << ans << '\n';
}