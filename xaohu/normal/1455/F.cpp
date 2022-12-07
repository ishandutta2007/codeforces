#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;

const int N = 505;

int n, k;
string s, dp[N], w;

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		w = s;
		for (int i = 0; i < n; ++i) {
			dp[i + 1] = string(i + 1, 'z');
			int j = s[i] - 'a';
			w[i] = (char)('a' + min({(j - 1 + k) % k, j, (j + 1) % k}));
		}
		dp[0] = "";
		for (int i = 0; i < n; ++i) {
			dp[i + 1] = min(dp[i + 1], dp[i] + w[i]);
			if (i > 0) {
				string cur = dp[i] + s[i];
				swap(cur[i - 1], cur[i]);
				dp[i + 1] = min(dp[i + 1], cur);
			}
			if (i + 1 < n) {
				string cur = dp[i] + s[i] + s[i + 1];
				swap(cur[i], cur[i + 1]);
				if (i > 0) {
					swap(cur[i - 1], cur[i]);
					dp[i + 2] = cur;
					swap(cur[i - 1], cur[i]);
				}
				cur[i] = w[i + 1];
				dp[i + 2] = min(dp[i + 2], cur);
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}