#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), c(m);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : c) {
		cin >> i;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (ans < m && c[ans] >= a[i]) {
			++ans;
		}
	}
	cout << ans << '\n';
}