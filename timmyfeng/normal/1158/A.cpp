#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	long long ans = 0;
	vector<int> b(n);
	for (auto& i : b) {
		cin >> i;
		ans += 1LL * i * m;
	}
	sort(b.rbegin(), b.rend());

	long long sum = 0;
	vector<int> g(m);
	for (auto& i : g) {
		cin >> i;
		sum += i;
	}
	sort(g.rbegin(), g.rend());

	if (g[m - 1] < b[0]) {
		cout << -1 << "\n";
		return 0;
	} else if (g[m - 1] == b[0]) {
		ans += sum - 1LL * b[0] * m;
	} else {
		ans += sum - 1LL * b[0] * (m - 1) - b[1];
	}

	cout << ans << "\n";
}