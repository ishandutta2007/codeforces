#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 505;
int dp[MAX_N][MAX_N][30];

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector <int> st;
	n = s.length();
	for (int i = 0; i < n; i++) {
		if (st.empty() || st.back() != s[i] - 'a') st.push_back(s[i] - 'a');
	}
	n = st.size();
	for (int i = 1; i <= n; i++) {
		//dp[i][i] = 1;
		//dp[i][i - 1] = 0;
		for (int c = 0; c < 26; c++) {
			if (c == st[i - 1]) {
				dp[i][i][c] = 0;
				dp[i][i - 1][c] = 0;
			} else {
				dp[i][i][c] = 1;
				dp[i][i - 1][c] = 0;
			}
		}
		dp[i][i][27] = 1;
		dp[i][i - 1][27] = 0;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= n; i++) {
			int j = i + len - 1;
			if (j > n) break;
			for (int k = 0; k <= 27; k++) dp[i][j][k] = MAX_N;
			for (int t = i; t <= j; t++) {
				dp[i][j][st[t - 1]] = min(dp[i][j][st[t - 1]], dp[i][t - 1][27] + dp[t + 1][j][st[t - 1]]); 
				//dp[i][j][27] = 
			}
			for (int k = 0; k < 26; k++) dp[i][j][27] = min(dp[i][j][27], dp[i][j][k] + 1); 
			//dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
			//if (s[i - 1] == s[j - 1]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + 1);
		}
	}
	cout << dp[1][n][27] << endl;
	return 0;
}