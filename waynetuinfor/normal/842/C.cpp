#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int a[maxn], ans[maxn], cnt[maxn];
vector<int> fac[maxn];

void dfs(int now, int fa, int d, int e) {
    for (int i : fac[a[now]]) ++cnt[i];
    ans[now] = e; int cure = 0;
    for (int i : fac[a[now]]) {
        if (cnt[i] == d + 1) {
            ans[now] = max(ans[now], i);
            cure = max(cure, i);
        } else if (cnt[i] == d) {
            ans[now] = max(ans[now], i);
        }
    }    
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1, cure);
    }    
    for (int i : fac[a[now]]) --cnt[i];
}

void init() {
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; i * j < maxn; ++j) fac[i * j].push_back(i);
    }
}

int main() {
    int n; cin >> n;
    init();
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    dfs(1, 0, 0, 0);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}