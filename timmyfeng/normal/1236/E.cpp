#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e5;

int dia[2 * MX + 2];
ll ps[MX + 2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (auto& i : a) {
		cin >> i;
	}
	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}

	fill(dia + 1, dia + 1 + n, 1);
	for (int i = 0; i < m + 1; ++i) {
		dia[i + 2] += dia[i + 1];
		dia[i + 1] = 0;
		if (i != m) {
			dia[a[i] + i + 2] += dia[a[i] + i + 1];
			dia[a[i] + i + 1] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		ps[i] += dia[i + m + 1];
	}

	memset(dia, 0, sizeof dia);
	fill(dia + m + 2, dia + n + m + 1, 1);
	for (int i = 0; i < m + 1; ++i) {
		dia[n + m - i] += dia[n + m - i + 1];
		dia[n + m - i + 1] = 0;
		if (i != m) {
			dia[a[i] + m - i - 1] += dia[a[i] + m - i];
			dia[a[i] + m - i] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		ps[i + 1] -= dia[i];
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ps[i] += ps[i - 1];
		ans += ps[i];
	}
	cout << ans << '\n';
}