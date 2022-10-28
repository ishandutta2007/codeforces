#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> pos_a(n);
	vector<int> pos_b(n);
	for (int i = 0 ; i < n; ++i) {
		int a;
		cin >> a;
		pos_a[a - 1] = i;
	}
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		pos_b[b - 1] = i;
	}

	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		++mp[(pos_b[i] - pos_a[i] + n) % n];
	}

	int ans = 0;
	for (auto i : mp) {
		ans = max(ans, i.second);
	}

	cout << ans << '\n';
}