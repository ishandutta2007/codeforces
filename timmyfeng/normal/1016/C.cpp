#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 3e5 + 2;

ll a[2][MX], ps[2][MX], pss[2][MX], ss[2][MX], sss[2][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int j = 0; j < 2; ++j) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[j][i];
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= n; ++j) {
			ps[i][j] = ps[i][j - 1] + a[i][j];
			pss[i][j] = pss[i][j - 1] + (j - 1) * a[i][j];
		}
		for (int j = n; j; --j) {
			ss[i][j] = ss[i][j + 1] + a[i][j];
			sss[i][j] = sss[i][j + 1] + (n - j) * a[i][j];
		}
	}

	ll cur = 0, ans = pss[0][n] + sss[1][1] + ss[1][1] * n;
	for (int i = 1; i <= n; ++i) {
		int r = !(i % 2);
		cur += (i * 2 - 2) * a[r][i];
		cur += (i * 2 - 1) * a[!r][i];
		ll a = pss[!r][n] - pss[!r][i];
		ll b = (ps[!r][n] - ps[!r][i]) * i;
		ll c = sss[r][i + 1] + ss[r][i + 1] * (n + i);
		ans = max(ans, cur + a + b + c);
	}
	cout << ans << '\n';
}