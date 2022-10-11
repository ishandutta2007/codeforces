#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dp[15][15];
void solve() {
	int r, c, n, k;
	cin >> r >> c >> n >> k;
	while(n--) {
		int x, y;
		cin >> x >> y;
		dp[x][y]++;
	}
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			dp[i][j] += dp[i-1][j];
			dp[i][j] += dp[i][j-1];
			dp[i][j] -= dp[i-1][j-1];
		}
	}
	int ret = 0;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			for(int a = i+1; a <= r; a++) {
				for(int b = j+1; b <= c; b++) {
					if(dp[a][b] - dp[i][b] - dp[a][j] + dp[i][j] >= k) ret++;
				}
			}
		}
	}
	cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}