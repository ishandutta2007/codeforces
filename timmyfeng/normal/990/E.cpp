#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e6 + 1;

bool blocked[MX];
int a[MX], pre[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int s;
		cin >> s;
		blocked[s] = true;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		if (!blocked[i]) {
			pre[i] = i;
		} else {
			pre[i] = i ? pre[i - 1] : -1;
		}
	}
	
	ll ans = 1e13;
	for (int len = 1; len <= k; ++len) {
		int res = 0, i = 0;
		while (i < n) {
			if (pre[i] == -1 || pre[i] + len <= i)
				break;
			i = pre[i] + len;
			++res;
		}
		if (i >= n) {
			ans = min(ans, (ll)res * a[len]);
		}
	}
	cout << (ans == 1e13 ? -1 : ans) << '\n';
}