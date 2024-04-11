#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = b; i >= a; --i)

using ll = long long;
using namespace std;

const int N = 1 << 18;

int p[N], n, P[N], P2[N], S[N], S2[N], dp[N], L[N], R[N], ans;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", p + i);
	rep(i, 2, n) dp[i] = (p[i - 1] > p[i] ? 1 + dp[i - 1] : 0);
	rep(i, 1, n) P[i] = max(P[i - 1], dp[i]);
	per(i, 1, n) S2[i] = max(S2[i + 1], dp[i]);
	dp[n] = 0;
	per(i, 1, n - 1) dp[i] = (p[i + 1] > p[i] ? 1 + dp[i + 1] : 0);
	per(i, 1, n) S[i] = max(S[i + 1], dp[i]);
	rep(i, 1, n) P2[i] = max(P2[i - 1], dp[i]);
	rep(i, 2, n) L[i] = (p[i - 1] < p[i] ? 1 + L[i - 1] : 0);
	per(i, 1, n - 1) R[i] = (p[i + 1] < p[i] ? 1 + R[i + 1] : 0);
	rep(i, 2, n - 1) {
		int a = max({P[i - 1], S[i + 1], P2[i - L[i] - 1], S2[i + R[i] + 1]});
		int b = max(L[i], R[i]);
		if (a >= b || !L[i] || !R[i]) continue;
		ans += (L[i] == R[i] && L[i] % 2 == 0);
	}
	printf("%d\n", ans);
	return 0;
}