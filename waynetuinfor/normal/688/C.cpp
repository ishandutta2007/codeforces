#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;

bool v[maxn], in[maxn];
vector<int> G[maxn];
set<int> s[2];

void dfs(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        in[a] = true; in[b] = true;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!v[i]) dfs(i, 0);
    for (int i = 1; i <= n; ++i) if (s[0].count(i) && s[1].count(i)) return cout << "-1\n", 0;
    cout << s[0].size() << '\n';
    for (int i : s[0]) cout << i << ' '; cout << '\n';
    cout << s[1].size() << '\n';
    for (int i : s[1]) cout << i << ' '; cout << '\n';
    return 0;
}

void dfs(int x, int id) {
    if (in[x]) s[id].insert(x);
    if (v[x]) return;
    v[x] = true;
    for (int u : G[x]) dfs(u, id ^ 1);
}