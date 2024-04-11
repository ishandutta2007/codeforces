#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
const long long inf = 1e15;
int a[maxn], fr[2][maxn][maxn], t[2][maxn][maxn];
long long dp[maxn][maxn];

inline void update(int oi, int oj, int ni, int nj, int ti, int tj) {
    if (dp[oi][oj] <= dp[ni][nj] + max(a[ti], a[tj])) return;
    dp[oi][oj] = dp[ni][nj] + max(a[ti], a[tj]);
    fr[0][oi][oj] = ni; fr[1][oi][oj] = nj;
    t[0][oi][oj] = ti; t[1][oi][oj] = tj;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    fill(a, a + maxn, inf);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n == 1) {
        cout << a[1] << endl;
        cout << 1 << endl;
        return 0;
    }
    fill(&dp[0][0], &dp[maxn - 1][maxn - 1] + 1, inf);
    dp[0][0] = 0; fr[0][0][0] = -1; fr[1][0][0] = -1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j == 0) {
                if (i + 2 <= n) update(i + 2, 0, i, j, i + 1, i + 2);
                if (i + 3 <= n) update(i + 3, i + 1, i, j, i + 2, i + 3);
                if (i + 3 <= n) update(i + 3, i + 2, i, j, i + 1, i + 3);
            } else {
                if (i + 1 <= n) update(i + 1, 0, i, j, j, i + 1);
                if (i + 2 <= n) update(i + 2, i + 1, i, j, j, i + 2);
                if (i + 2 <= n) update(i + 2, j, i, j, i + 1, i + 2);
            }
        }
    }
    long long ans = inf;
    int bi = -1, bj = -1, li = -1, lj = -1;
    for (int i = 0; i <= n; ++i) {
        if (i == 0 && (n & 1)) continue;
        if (dp[n][i] + a[i] < ans) {
            ans = dp[n][i] + a[i];
            bi = n; bj = i;
            li = i;
        }
    }
    if ((n & 1) && dp[n - 1][0] + a[n] < ans) {
        ans = dp[n - 1][0] + a[n];
        bi = n - 1, bj = 0;
        li = n;
    }
    stack<pair<int, int>> stk;
    while (bi >= 0) {
        stk.push(make_pair(li, lj));
        int fi = fr[0][bi][bj], fj = fr[1][bi][bj];
        li = t[0][bi][bj], lj = t[1][bi][bj];
        bi = fi; bj = fj;
    }
    cout << ans << endl;
    while (stk.size()) {
        bool opt = false;
        if (stk.top().first > 0) cout << stk.top().first << ' ', opt = true;
        if (stk.top().second > 0) cout << stk.top().second << ' ', opt = true;
        if (opt) cout << endl;
        stk.pop();
    }
    return 0;
}