#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int c[maxn], cnt[2];

void dfs(int now, int cnow, int fa) {
    c[now] = cnow;
    ++cnt[cnow];
    for (int u : G[now]) if (u != fa) {
        dfs(u, cnow ^ 1, now);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    } 
    dfs(1, 0, 0);
    long long ed = (long long)cnt[1] * (long long)cnt[0];
    cout << ed - n + 1 << endl;
    return 0;
}