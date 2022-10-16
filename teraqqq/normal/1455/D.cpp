#include <bits/stdc++.h>

using namespace std;

const int N = 501;

int n, x, a[N];
int16_t dp[N][N][N];

int solve(int i, int k, int x) {
    if (i == n) return 0;
    
    int16_t& res = dp[i][k][x];
    if (res) return res - 1;
    
    dp[i][k][x] = N + 2;
    if (a[i] > x && k <= x)
        res = min<int>(res, 1 + solve(i+1, x, a[i])); // +1 swap
    if (k <= a[i])
        res = min<int>(res, solve(i+1, a[i], x));
        
    return res++;
}

int solve() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < N; ++j)
        fill(dp[i][j], dp[i][j]+N, 0);
        
    int res = solve(0, 0, x);
    return res == N+2 ? -1 : res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) cout << solve() << '\n';
}