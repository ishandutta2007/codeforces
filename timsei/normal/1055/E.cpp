#include <bits/stdc++.h>
using namespace std;

const int N = 1.5e3 + 5;

int n, s, m, k, A[N], S[N];

struct Seg {
	int l, r;
	void input() {
		scanf("%d%d", &l, &r);
	}
}L[N];

int dp[N][N];

int Seg[N];

bool pd(int x) {
	for(int i = 1; i <= n; ++ i) {
		S[i] = (A[i] <= x) + S[i - 1];
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j <= m; ++ j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if(Seg[i] >= i)
			dp[Seg[i] + 1][j + 1] = max(dp[Seg[i] + 1][j + 1], dp[i][j] + (S[Seg[i]] - S[i - 1]));
		}
	}
	return dp[n + 1][m] >= k;
}

int main() {
	cin >> n >> s >> m >> k;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1; i <= s; ++ i) L[i].input(), Seg[L[i].l] = max(Seg[L[i].l], L[i].r);
	for(int i = 1; i <= n; ++ i) Seg[i] = max(Seg[i], Seg[i - 1]);
	int l = 0, r = 1e9, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(pd(mid)) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res << endl;
}