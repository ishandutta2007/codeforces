#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 1;

int dp[MX], dpRet[MX], hi[MX], dep, k;
vector<int> chd[MX];

void dfs(int u) {
	hi[u] = 1e9;
	int mx = 0, sum = 0;
	for (auto c : chd[u]) {
		++dep;
		dfs(c);
		--dep;
		hi[u] = min(hi[u], hi[c]);
		sum += dpRet[c];
		mx = max(mx, dp[c] - dpRet[c]);
	}
	if (hi[u] == 1e9) {
		hi[u] = dep;
		sum = 1;
	}
	if (hi[u] - dep < k) {
		dpRet[u] = sum;
	}
	dp[u] = mx + sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> k;
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		chd[p].push_back(i);
	}

	dfs(1);
	cout << dp[1] << '\n';
}