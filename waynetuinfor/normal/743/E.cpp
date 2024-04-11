#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, maxv = 8;
int a[maxn], n, prv[maxn][2], longest;
bool dp[maxn][maxv][1 << maxv], v[maxn][maxv][1 << maxv];
deque<int> dq[2][maxv];

bool dfs(int now, int k, int mask, int need) {
    if (k < 0) return false;
    if (now < 0) return false;
    if (now == 0) {
        if (k == 0 && mask == 0) return true;
        return false;
    }
    if (v[now][k][mask]) return dp[now][k][mask];
    v[now][k][mask] = true;
    dp[now][k][mask] = dfs(now - 1, k, mask, need);
    if ((1 << a[now]) & mask) {
        dp[now][k][mask] |= dfs(prv[now][0] - 1, k, mask ^ (1 << a[now]), need);
        dp[now][k][mask] |= dfs(prv[now][1] - 1, k - 1, mask ^ (1 << a[now]), need);
    }
    return dp[now][k][mask];
}

bool check(int now) {
    // cout << "check " << now << endl;
    memset(prv, 0, sizeof(prv));
    for (int i = 0; i < maxv; ++i) dq[0][i].clear(), dq[1][i].clear();
    for (int i = 1; i <= n; ++i) {
        dq[0][a[i]].push_back(i), dq[1][a[i]].push_back(i);
        if (dq[0][a[i]].size() == now) prv[i][0] = dq[0][a[i]].front(), dq[0][a[i]].pop_front();
        if (dq[1][a[i]].size() == now + 1) prv[i][1] = dq[1][a[i]].front(), dq[1][a[i]].pop_front();
    }
    // for (int i = 1; i <= n; ++i) cout << prv[i][0] << ' ' << prv[i][1] << endl;
    memset(v, false, sizeof(v)); memset(dp, false, sizeof(dp));
    bool ret = false;
    longest = 0;
    for (int i = 0; i < maxv; ++i)  {
        if (dfs(n, i, (1 << maxv) - 1, now)) {
            ret = true;
            longest = now * maxv + i;
        }
    }
    return ret;
}

bool used[maxv];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], --a[i];
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[a[i]]) ++c;
        used[a[i]] = true;
    }
    int d = 11, ans = 0; 
    while (d--) if (ans + (1 << d) <= n) if (check(ans + (1 << d))) ans += (1 << d);
    // cout << "ans = " << ans << endl;
    check(ans);
    cout << max(c, longest) << endl;
    return 0;
}