#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ps(n + 1);
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			++ps[a];
		}
		int ans = 0;
		for (int i = n; i; --i) {
			ps[i - 1] += ps[i];
			if (ps[i] >= i) {
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}
}