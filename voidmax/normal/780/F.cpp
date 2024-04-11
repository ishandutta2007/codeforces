#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp push_back
#define all(a) a.begin(), a.end()
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)

using namespace std;

typedef long long base;
typedef pair <int, int> point;

const string FILENAME = "input";
const int MAXN = 2e5 + 1;
const long long INF = 1e18 + 1;

int n, m;
bitset <501> used[71][2][501];
long long dp[71][2][501];

long long sum(base a, base b) {
	if ((a + b) >= INF)
		return INF;
	return a + b;
}

int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n >> m;
	for (int i = m; i--;) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		used[0][c][a][b] = true;
	}
	for (int len = 0; len <= 61; ++len) {
		for (int c = 0; c < 2; ++c) {
			for (int i = 0; i < n; ++i) {
				bool OK = false;
				for (int j = 0; j < n; ++j) {
					if (used[len][c][i][j]) {
						OK = true;
						used[len + 1][c][i] |= used[len][!c][j];
					}
				}
				if (OK) {
					dp[len][c][i] = sum(1LL << len, 0);
				} else {
					if (len != 0) {
						long long M = 0;
						for (int j = 0; j < n; ++j) {
							if (used[len - 1][c][i][j])
								M = max(M, dp[len - 1][!c][j]);
						}
						dp[len][c][i] = sum(dp[len - 1][c][i], M);
					}
				}
			}
		}
	}
	if (dp[61][0][0] == INF) {
		cout << -1 << endl;
	} else {
		cout << dp[61][0][0] << endl;
	}
}