#include <bits/stdc++.h>
using namespace std;

const int N = 4e3 + 5;

int n, m, A[N];

int fa[N], S[N];
long long tmp[N];
long long dp[N][N];

void Trans(int V, int x) {
	for(int i = 0; i <= S[x] + S[V]; ++ i) tmp[i] = 0;
	for(int a = 0; a <= S[V]; ++ a) {
		for(int b = 0; b <= S[x]; ++ b) {
			tmp[a + b] = 
			max(tmp[a + b], dp[V][a] + dp[x][b] + 1LL * a * (m - a) * (A[V] - A[x]));
		}
	}
	S[x] += S[V];
	for(int a = 0; a <= S[x] + S[V]; ++ a) {
		dp[x][a] = tmp[a];
	}
}

int solve(int l, int r) {
	if(l > r) return 0;
	if(l == r) {
		S[l] = 1;
		dp[l][0] = dp[l][1] = 0;
		return l;
	}
	int Min = l;
	for(int i = l; i <= r; ++ i) {
		if(A[i] < A[Min]) Min = i;
	}
	S[Min] = 1;
	dp[Min][0] = dp[Min][1] = 0;
	int lc = solve(l, Min - 1), rc = solve(Min + 1, r);
	if(lc)
		Trans(lc, Min);
	if(rc)
	Trans(rc, Min);
	return Min;
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j <= n; ++ j) 
		dp[i][j] = -1e18;
	}
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	cout << dp[solve(1, n)][m] << endl;
}