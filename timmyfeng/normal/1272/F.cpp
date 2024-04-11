#include <bits/stdc++.h>
using namespace std;
const int MX = 200;

int dp[MX + 1][MX + 1][MX + 1];
tuple<int, int, int, char> pd[MX + 1][MX + 1][MX + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	string s, t;
	cin >> s >> t;
	memset(dp, -1, sizeof dp);
	queue<tuple<int, int, int>> bfs;
	dp[0][0][0] = 0;
	bfs.emplace(0, 0, 0);
	while (!bfs.empty()) {
		int i, j, k;
		tie(i, j, k) = bfs.front();
		bfs.pop();
		if (k) {
			int ni = (i < (int)s.size() && s[i] == ')' ? i + 1 : i);
			int nj = (j < (int)t.size() && t[j] == ')' ? j + 1 : j);
			if (dp[ni][nj][k - 1] == -1) {
				dp[ni][nj][k - 1] = dp[i][j][k] + 1;
				pd[ni][nj][k - 1] = make_tuple(i, j, k, ')');
				bfs.emplace(ni, nj, k - 1);
			}
		}
		if (k + 1 <= MX) {
			int ni = (i < (int)s.size() && s[i] == '(' ? i + 1 : i);
			int nj = (j < (int)t.size() && t[j] == '(' ? j + 1 : j);
			if (dp[ni][nj][k + 1] == -1) {
				dp[ni][nj][k + 1] = dp[i][j][k] + 1;
				pd[ni][nj][k + 1] = make_tuple(i, j, k, '(');
				bfs.emplace(ni, nj, k + 1);
			}
		}
	}
	string ans = "";
	for (int i = (int)s.size(), j = (int)t.size(), k = 0; i || j || k; tie(i, j, k, ignore) = pd[i][j][k]) {
		ans += get<3>(pd[i][j][k]);
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}