#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
set<int> G[maxn];
bool v[maxn];
int cnt[maxn];
vector<int> ans;

void dfs(int now, int p) {
    v[now] = true;
    ans.emplace_back(now);
    for (int u : G[now]) if (!v[u]) {
        if (p && G[p].count(u) == 0) continue;
        int cnt = 0;
        for (int k : G[now]) cnt += G[u].count(k);
        if (cnt >= 2) {
            dfs(u, now);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n << 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].insert(b); G[b].insert(a);
        ++cnt[a]; ++cnt[b];
    }
    for (int i = 1; i <= n; ++i) if (cnt[i] < 4) return cout << "-1" << endl, 0;
    dfs(1, 0); 
    if (ans.size() != n) return cout << "-1" << endl, 0;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}