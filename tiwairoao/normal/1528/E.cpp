#include <bits/stdc++.h>

typedef long long ll;

const int N = 1000000;
const int P = 998244353;
const int IV2 = (P + 1) / 2;
const int IV6 = (P + 1) / 6;

inline int norm(int x) {if (x >= P) x -= P; return x;}
inline int reduce(int x) {if (x < 0) x += P; return x;}
inline void add(int &x, int y) {if ((x += y) >= P) x -= P;}
inline void sub(int &x, int y) {if ((x -= y) < 0) x += P;}
int mpow(int b, int p) {
	int r = 1;
	for (; p; p >>= 1, b = (ll)b * b % P)
		if (p & 1) r = (ll)r * b % P;
	return r;
}

int dp[N + 5], n;
void solve() {
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		dp[i] = (ll)(dp[i - 1] + 2) * (dp[i - 1] + 1) % P * IV2 % P;
}
int f(int k) {
	if (!k) return 0;
	
	int ans = (dp[k - 1] + 2ll * (dp[k] + P - dp[k - 1] - 1)) % P;
	int del = ((ll)(dp[k - 1] + 3) * dp[k - 1] % P + 2) * dp[k - 1] % P * IV6 % P;
	add(ans, del), add(ans, del);

	for (int i = 1; i < k; i++) {
		ans = (ans + (ll)(dp[i - 1] + P - dp[i - 2])
			* (dp[k - i] + P - dp[k - i - 1] - 1)) % P;
	}
	return ans;
}

int main() {
	scanf("%d", &n), solve();
	printf("%d\n", reduce(f(n) - f(n - 1)));
}