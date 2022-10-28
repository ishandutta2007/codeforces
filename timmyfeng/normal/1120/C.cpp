#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
	int n = s.size();
	vector<int> pi(n);
	int link = 0;
	for (int i = 1; i < n; ++i) {
		while (link && s[i] != s[link]) {
			link = pi[link - 1];
		}
		if (s[i] == s[link]) {
			++link;
		}
		pi[i] = link;
	}
	return pi;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;

	vector<int> dp(n + 1, 1e9);
	dp[0] = 0;

	for (int i = 0; i < n; ++i) {
		dp[i + 1] = min(dp[i + 1], dp[i] + a);

		int lb = i + 1;
		int rb = n;
		while (lb <= rb) {
			int mb = (lb + rb) / 2;
			vector<int> pi = prefix_function(s.substr(i, mb - i) + "#" + s.substr(0, i));

			bool res = false;
			for (int j = mb - i; j < pi.size(); ++j) {
				res |= (pi[j] == mb - i);
			}

			if (res) {
				lb = mb + 1;
			} else {
				rb = mb - 1;
			}
		}

		dp[rb] = min(dp[rb], dp[i] + b);
	}
	cout << dp[n] << "\n";
}