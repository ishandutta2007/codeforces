#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
vector<int> G[maxn];
int sz[maxn], n;
bitset<maxn> dp[maxn];

void pre(int now, int fa) {
    sz[now] = 1;
    for (int u : G[now]) if (u != fa) {
        pre(u, now);
        sz[now] += sz[u];
    }
}

void dfs(int now, int fa) {
    dp[now][0] = true;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        dp[now] |= dp[now] << sz[u];
    }
    for (int i = 0; i <= n; ++i) {
        if (n - i - 1 >= 0 && dp[now][i]) dp[now][n - i - 1] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    pre(1, 0); dfs(1, 0);
    bitset<maxn> ans;
    for (int i = 1; i <= n; ++i) ans |= dp[i];
    vector<int> v;
    for (int i = 1; i < n - 1; ++i) {
        if (ans[i]) v.push_back(i);
    }
    cout << v.size() << endl;
    for (int i : v) cout << i << ' ' << n - 1 - i << endl;
    return 0;
}