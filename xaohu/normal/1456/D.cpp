#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;

const int N = 5050;
const ll INF = 1e18;

int n;
ll min_time[N], t[N], x[N];
bool dp[N][N];

void umin(ll &a, ll b) {
	a = min(a, b);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> x[i];
		min_time[i] = INF;
	}
	for (int i = 0; i < n; ++i) {
		if (min_time[i] <= t[i]) {
			for (int j = i + 1; j < n; ++j)
				if (min_time[i] + 2 * abs(x[i] - x[j]) <= t[i])
					dp[i][j] = 1;
			umin(min_time[i + 1], max(t[i], min_time[i] + abs(x[i] - x[i + 1])));
			for (int j = i + 2; j <= n; ++j)
				if (max(t[i], min_time[i] + abs(x[i] - x[j])) + abs(x[j] - x[i + 1]) <= t[i + 1]) 
					dp[i + 1][j] = 1;
		}
		
		for (int j = i + 1; j <= n; ++j) {
			if (!dp[i][j]) continue;
			if (i + 1 < j) {
				if (t[i] + abs(x[i] - x[i + 1]) <= t[i + 1])
					dp[i + 1][j] = 1;
			}
			if (i + 1 == j) {
				umin(min_time[i + 2], max(t[i + 1], t[i] + abs(x[i] - x[i + 2])));
				
				for (int k = i + 3; k <= n; ++k)
					if (max(t[j], t[i] + abs(x[i] - x[k])) + abs(x[k] - x[i + 2]) <= t[i + 2])
						dp[i + 2][k] = 1;
			}
		}
	}
	printf(min_time[n] <= t[n] || dp[n - 1][n] ? "YES" : "NO");
	return 0;
}