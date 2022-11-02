#include <bits/stdc++.h>
using namespace std;

const int Z = 4e4 + 1, MOD = 1e9+7;

int dp[Z] {1};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	vector<string> pal[6];
	pal[0].push_back("");
	for(int i = 0; i < 10; ++i) pal[1].push_back(string{char('0' + i)});

	for(int i = 0; i + 2 < 6; ++i) {
		for(string s : pal[i]) {
			for(int j = 0; j < 10; ++j) {
				pal[i + 2].push_back(char(j + '0') + s + char(j + '0'));
			}
		}
	}
	vector<int> g;
	for(int i = 1; i < 6; ++i) {
		for(string s : pal[i]) {
			int num = 0;
			reverse(begin(s), end(s));

			for(char c : s) {
				num *= 10;
				num += (c - '0');
			}
			if(s[0] != '0') {
				for(int k = num; k < Z; ++k)
					(dp[k] += dp[k-num]) %= MOD;
			}
		}
	}


	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
}