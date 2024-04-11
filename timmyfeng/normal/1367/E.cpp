#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		
		vector<int> freq(26);
		for (auto i : s) {
			++freq[i - 'a'];
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int res = 0;
			for (int j = 0; j < 26; ++j) {
				res += freq[j] / i;
			}
			for (int j = 1; j <= res; ++j) {
				if (k % j == 0) {
					ans = max(ans, i * j);
				}
			}
		}
		cout << ans << "\n";
	}
}