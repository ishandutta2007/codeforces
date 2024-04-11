#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, maxx = 1e4 + 10, inf = 1e7 + 10;
int dp[maxn][maxx], c[maxn], n;

int go(int now, int f) {
    // cout << "now = " << now << " f = " << f << endl;
    if (f < 0) return -inf;
    if (now == 0) return 0;
    if (dp[now][f]) return dp[now][f];
    return dp[now][f] = max(go(now - 1, f), go(now - 1, f - c[now] * (n - now + 1)) + 1);
}

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x; cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    cout << go(n, x) << endl;
    return 0;
}