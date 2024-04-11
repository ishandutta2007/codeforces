#include <bits/stdc++.h>
using namespace std;

int _prev[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			_prev[i] = -1;
		}
		int ans = 1e9;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if (_prev[a] != -1) {
				ans = min(ans, i - _prev[a] + 1);
			}
			_prev[a] = i;
		}
		cout << (ans == 1e9 ? -1 : ans) << '\n';
	}
}