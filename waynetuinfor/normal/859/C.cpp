#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
int dp[2][maxn], sz[maxn], n;

int go(int t, int now) {
    if (now == n + 1) return 0;
    if (dp[t][now]) return dp[t][now];
    if (t == 0) dp[t][now] = max(sz[now] + go(t ^ 1, now + 1), -sz[now] + go(t, now + 1));
    else dp[t][now] = min(-sz[now] + go(t ^ 1, now + 1), sz[now] + go(t, now + 1));
    return dp[t][now];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; ++i) cin >> sz[i], s += sz[i];
    int diff = go(1, 0);
    cout << (s - diff) / 2 + diff << ' ' << (s - diff) / 2 << endl;
    return 0;
}