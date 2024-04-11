#include <bits/stdc++.h>
using namespace std;

const int MX = 5200;

bool a[MX][MX];
int n;

bool chk(int k) {
	if (!k)
		return false;
	for (int i = 0; i < n; i += k) {
		for (int j = 0; j < n; j += k) {
			for (int u = i; u < i + k; ++u) {
				for (int v = j; v < j + k; ++v) {
					if (a[i][j] != a[u][v])
						return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n / 4; ++j) {
			int val = s[j] > '9' ? s[j] - 'A' + 10 : s[j] - '0';
			for (int k = 0; k < 4; ++k) {
				a[i][j * 4 + k] = (val & (1 << (3 - k)));
			}
		}
	}

	int ans = 1;
	int m = n;
	for (int i = 2; i * i <= m; ++i) {
		int cur = 1;
		while (m % i == 0) {
			cur *= i;
			m /= i;
			if (chk(cur)) {
				ans *= i;
			} else {
				cur = 0;
			}
		}
	}
	if (chk(m)) {
		ans *= m;
	}
	cout << ans << '\n';
}