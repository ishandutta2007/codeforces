#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int c[maxn];
vector<int> G[maxn], ans;

void dfs(int now, int fa) {
    ans.push_back(now);
    for (int u : G[now]) if (u != fa) {
        c[u] = (c[u] == -1 ? 1 : -1);
        dfs(u, now);
        ans.push_back(now);
        c[now] = (c[now] == -1 ? 1 : -1);
    }
    if (fa) {
        if (c[now] == -1) {
            ans.push_back(fa); ans.push_back(now);
            c[now] = 1;
            c[fa] = (c[fa] == -1 ? 1 : -1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
    if (c[1] == -1) {
        int g = G[1][0];
        ans.push_back(g); ans.push_back(1); ans.push_back(g);
    }
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}