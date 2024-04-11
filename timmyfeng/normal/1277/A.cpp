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

		int ans = 0;
		for (int i = 1; i <= 9; ++i) {
			long long cur = i;
			while (cur <= n) {
				++ans;
				cur = cur * 10 + i;
			}
		}
		cout << ans << "\n";
	}
}