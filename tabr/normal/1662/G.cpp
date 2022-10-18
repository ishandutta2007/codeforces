#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int n;
long long ans;
vector<int> g[1000010];
/*
int sz_0[1000010];
long long dp[1000010];
set<int> st;

void Dfs(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        Dfs(to, v);
        sz[v] += sz[to];
        dp[v] += dp[to];
    }
    dp[v] += sz[v];
}

void Reroot(int v, int p) {
    multiset<int> c;
    for (int to : g[v]) {
        c.emplace(sz[to]);
    }
    long long t = 0;
    if (st.count(v)) {
        bitset<1000010> b;
        b[0] = 1;
        vector<int> d;
        while (!c.empty()) {
            int x = *c.begin();
            int cnt = (int) c.count(x);
            if (cnt % 2 == 0) {
                d.emplace_back(x);
                d.emplace_back(x);
                for (int i = 0; i < (cnt - 2) / 2; i++) {
                    c.emplace(x * 2);
                }
            } else {
                d.emplace_back(x);
                for (int i = 0; i < (cnt - 1) / 2; i++) {
                    c.emplace(x * 2);
                }
            }
            c.erase(x);
        }
        for (int i : d) {
            b |= b << i;
        }
        for (int i = 0; i < n - 1; i++) {
            if (b[i]) {
                t = max(t, 1LL * i * (n - 1 - i));
            }
        }
    }
    t += dp[v];
    ans = max(ans, t);
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        int sz_to = sz[to];
        int sz_v = sz[v];
        long long dp_to = dp[to];
        long long dp_v = dp[v];
        dp[v] -= dp[to] + sz[to];
        sz[v] -= sz[to];
        sz[to] = n;
        dp[to] += dp[v] + sz[v];
        Reroot(to, v);
        sz[to] = sz_to;
        sz[v] = sz_v;
        dp[to] = dp_to;
        dp[v] = dp_v;
    }
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int j;
        cin >> j;
        j--;
        g[i].emplace_back(j);
        g[j].emplace_back(i);
    }
    ans = 0;
    auto GetSize = [&](int r) {
        queue<int> que;
        que.emplace(r);
        vector<int> order;
        vector<int> vis(n);
        vector<int> pv(n, -1);
        vis[r] = 1;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int to : g[v]) {
                if (vis[to]) {
                    continue;
                }
                vis[to] = 1;
                pv[to] = v;
                order.emplace_back(to);
                que.emplace(to);
            }
        }
        vector<int> sz(n, 1);
        reverse(order.begin(), order.end());
        for (int v : order) {
            sz[pv[v]] += sz[v];
        }
        return sz;
    };
    auto Check = [&](vector<int> e, int r) {
        multiset<int> c;
        for (int i : g[r]) {
            c.emplace(e[i]);
        }
        bitset<1000010> b;
        b[0] = 1;
        vector<int> d;
        long long t = 0;
        while (!c.empty()) {
            int x = *c.begin();
            int cnt = (int) c.count(x);
            if (cnt % 2 == 0) {
                d.emplace_back(x);
                d.emplace_back(x);
                for (int i = 0; i < (cnt - 2) / 2; i++) {
                    c.emplace(x * 2);
                }
            } else {
                d.emplace_back(x);
                for (int i = 0; i < (cnt - 1) / 2; i++) {
                    c.emplace(x * 2);
                }
            }
            c.erase(x);
        }
        for (int i : d) {
            b |= b << i;
        }
        for (int i = 0; i < n - 1; i++) {
            if (b[i]) {
                t = max(t, 1LL * i * (n - 1 - i));
            }
        }
        t += accumulate(e.begin(), e.end(), 0LL);
        debug(r, t);
        ans = max(ans, t);
    };
    auto sz_0 = GetSize(0);
    debug(sz_0);
    for (int i = 0; i < n; i++) {
        int mx = n - sz_0[i];
        for (int j : g[i]) {
            if (sz_0[j] > sz_0[i]) {
                continue;
            }
            mx = max(mx, sz_0[j]);
        }
        if (mx < n / 2 + 3) {
            auto e = GetSize(i);
            Check(e, i);
        }
    }
    cout << ans << '\n';
    return 0;
}