#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1e5 + 1;
const int INF = 0x3f3f3f3f;
const int M = 4;
string T = "hard";

ll dp[MX][M];
int a[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	memset(dp, INF, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < M; ++j) {
			if (dp[i][j] == INF)
				continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i]);
			int nj = j + (s[i] == T[j]);
			if (nj < M) {
				dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j]);
			}
		}
	}
	cout << *min_element(dp[n], dp[n] + M) << '\n';
}