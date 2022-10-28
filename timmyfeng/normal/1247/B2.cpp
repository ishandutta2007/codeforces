#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6;
int a[MX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k, d;
		cin >> n >> k >> d;
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		map<int, int> freq;
		int ct = 0;
		for (int i = 0; i < d; ++i) {
			if (!freq[a[i]]) {
				++ct;
			}
			++freq[a[i]];
		}
		int ans = ct;
		for (int i = 0; i + d < n; ++i) {
			--freq[a[i]];
			if (!freq[a[i]]) {
				--ct;
			}
			if (!freq[a[i + d]]) {
				++ct;
			}
			++freq[a[i + d]];
			ans = min(ans, ct);
		}
		cout << ans << '\n';
	}
}