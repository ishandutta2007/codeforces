#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX_N = 2e3 + 4;
char f[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];

int main() {
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	ios_base :: sync_with_stdio(0);
//	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> f[i][j];
	}
	dp[0][0] = 0;
	if (f[0][0] == 'a') dp[0][0]++;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			dp[i][j] = 0;
			if (i != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j != 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (f[i][j] == 'a') dp[i][j]++;
		}
	}
	long long ans = 0;
	vector <pair <int, int>> best;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j + 1 == ans && dp[i][j] + k >= i + j + 1) best.push_back({i, j});
			if ((i + j + 1 > ans && dp[i][j] + k >= i + j + 1)) {
				best.clear();
				best.push_back({i, j});
				ans = i + j + 1;
				//cout << i << ' ' << j << ' ' << dp[i][j] << endl;
			}
		}
	}
	if (ans == 0) {
		best.push_back({0, 0});
	}
	//cout << best.size() << endl;
	//cout << ans << endl;
	string res = "";
	for (int i = 0; i < ans; i++) res += 'a';
	//cout << res << endl;
	for (int i = ans; i < 2 * n - 1; i++) res += (char) ('z' + 1);
	//cout << res << endl;
	if (k == 0) res[0] = f[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) vis[i][j] = 0;
	}
	deque <pair <int, int>> q;
	for (pair <int, int> elem : best) {
		q.push_back(elem);
		vis[elem.first][elem.second] = 1;
	}
	while (!q.empty()) {
		pair <int, int> elem = q.front();
		q.pop_front();
		int i = elem.first, j = elem.second;
		//cout << i << ' ' << j << endl;
		if (res[i + j] < f[i][j] && (i + j + 1 != ans)) continue;
	//	cout << 64 << endl;
		//cout << i << ' ' << j << endl;
		if (i < n - 1) {
			if (f[i + 1][j] < res[i + j + 1]) {
				res[i + j + 1] = f[i + 1][j];
			}
			if (f[i + 1][j] == res[i + j + 1] && !vis[i + 1][j]) {
				q.push_back({i + 1, j});
				vis[i + 1][j] = 1;
			}
		}
		if (j < n - 1) {
			if (f[i][j + 1] < res[i + j + 1]) {
				res[i + j + 1] = f[i][j + 1];
			}
			if (f[i][j + 1] == res[i + j + 1] && !vis[i][j + 1]) {
				q.push_back({i, j + 1});
				vis[i][j + 1] = 1;
			}
		}
		//cout << i + j + 1 << ' ' << res[i + j + 1] << endl;
	}
	cout << res << endl;
	return 0;
}