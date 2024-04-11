#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], val[maxn], dp[maxn], in[maxn];
vector<int> G[maxn];

void go(int now) {
    if (dp[now]) return;
    in[now] = 1;
    dp[now] = val[now];
    for (int u : G[now]) {
        if (in[u] == 1 || u == 1) {
            dp[now] = -1;
            return;
        }
        go(u);
        if (dp[u] == -1) {
            dp[now] = -1;
            return;
        }
        dp[now] += dp[u];
    }
    in[now] = 2;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        int now = i;
        val[i] += a[i];
        now -= a[now];
        if (now == 1) {
            G[i].push_back(1);
            continue;
        }
        if (now <= 0 || now > n) continue;
        val[i] += a[now];
        now += a[now];
        if (now == 1) {
            G[i].push_back(1);
            continue;
        }
        if (now <= 0 || now > n) continue;
        G[i].push_back(now);
    }
    for (int i = 1; i <= n; ++i) if (!in[i]) go(i);
    for (int i = 1; i <= n - 1; ++i) {
        if (dp[i + 1] == -1) cout << "-1" << endl;
        else cout << i + dp[i + 1] << endl;
    }
    return 0;
}