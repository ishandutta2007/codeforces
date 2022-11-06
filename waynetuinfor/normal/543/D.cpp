#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, mod = 1e9 + 7;
int dp[maxn], ans[maxn], z[maxn];
vector<int> G[maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

void dfs1(int now, int fa) {
    dp[now] = 1;
    for (int u : G[now]) if (u != fa) {
        dfs1(u, now);
        dp[now] = mul(dp[now], add(dp[u], 1));
        if (add(dp[u], 1) == 0) ++z[now];
    }
}

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int merge(int a, int b) {
    return add(1, mul(a, b));
}

void dfs2(int now, int fa, int v) {
    ans[now] = mul(dp[now], v);
    int zdp = 1;
    for (int u : G[now]) if (u != fa && add(dp[u], 1) != 0) zdp = mul(zdp, add(dp[u], 1));
    for (int u : G[now]) if (u != fa) {
        if (z[now] == 0) dfs2(u, now, merge(v, mul(dp[now], fpow(add(dp[u], 1), mod - 2))));
        else if (z[now] == 1 && add(dp[u], 1) == 0) dfs2(u, now, add(mul(zdp, v), 1));
        else dfs2(u, now, 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].push_back(i);
        G[i].push_back(p);
    }
    dfs1(1, 0); dfs2(1, 0, 1);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}