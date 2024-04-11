#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5e5 + 5;
const ll INF = 1e17;

int n, q;
ll s[3][N], dp[N], tL[N], tR[N];

struct Node {
	int l, r;
	ll w;
	void input() {
		scanf("%d%d%lld", &l, &r, &w);
	}
}x;

void solve(int l, int r, vector < Node > Q, ll mn) {
	int mid = (l + r) >> 1;
	vector < Node > L, R;
	for(auto &x : Q) {
		x.l = max(x.l, l); x.r = min(x.r, r);
		if(x.l <= l && x.r >= r) {
			mn = min(mn, x.w);
			continue;
		}
		if(x.l <= mid) L.push_back(x);
		if(x.r > mid) R.push_back(x);
	}
	if(l == r) {
		dp[l] = max(dp[l], s[0][l] - mn + s[1][l] - s[1][l - 1]);
		dp[l] = max(dp[l], dp[l - 1] - mn + s[1][l] - s[1][l - 1]);
		return;
	}
	for(int i = l; i <= r; ++ i) {
		tL[i] = tR[i] = -INF;
	}
	solve(l, mid, L, mn);
	
	for(int i = mid; i >= l - 1; -- i) {
		tL[i] = max(tL[i + 1], max(dp[i], s[0][i + 1]) - s[1][i]);
	}
	for(auto x : Q) {
		tR[x.r] = max(tR[x.r], tL[x.l - 1] - x.w);
	}
	ll cur = tL[l - 1] - mn;
	for(int i = r; i >= mid + 1; -- i) {
		cur = max(cur, tR[i]);
		dp[i] = max(dp[i], cur + s[1][i]);
	}
	solve(mid + 1, r, R, mn);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < 3; ++ i) {
		for(int j = 1; j <= n; ++ j) scanf("%lld", &s[i][j]);
		for(int j = 1; j <= n; ++ j) s[i][j] += s[i][j - 1];
	}
	for(int i = 0; i <= n; ++ i) dp[i] = -INF;
	vector < Node > Q;
	for(int i = 1; i <= q; ++ i) {
		x.input();
		Q.push_back(x);
	}
	solve(1, n, Q, INF);
	ll ans = -INF;
	for(int i = 1; i <= n; ++ i) {
		ans = max(ans, dp[i] + s[2][n] - s[2][i - 1]);
	}
	cout << ans << endl;
}