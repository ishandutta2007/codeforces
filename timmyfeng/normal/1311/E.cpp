#include <bits/stdc++.h>
using namespace std;

int ans[5001];
int head[5000];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			ans[i] = i / 2;
			d -= 32 - __builtin_clz(i) - 1;
		}
		for (int i = 0, j = 1; j <= n; ++i, j *= 2) {
			head[i] = j;
		}
		int mx = 32 - __builtin_clz(n) - 1;
		for (int i = n; i && d > 0; --i) {
			if ((i & (i - 1)) == 0) continue;
			++mx;
			head[mx] = i;
			for (int j = 32 - __builtin_clz(i) - 1; j < mx && d > 0; ++j) {
				--d;
				ans[i] = head[j];
			}
		}
		if (d) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			for (int i = 2; i <= n; ++i) {
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
	}
}