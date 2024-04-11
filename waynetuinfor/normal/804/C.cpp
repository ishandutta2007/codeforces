#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
vector<int> s[maxn], G[maxn];
int color, c[maxn];

void dfs(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int cnt; cin >> cnt; while (cnt--) {
            int x; cin >> x; s[i].push_back(x);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; ++i) if (!c[i]) c[i] = 1;
    if (!color) color = 1;
    cout << color << '\n';
    for (int i = 1; i <= m; ++i) cout << c[i] << ' ';
    return 0;
}
void dfs(int x, int fa) {
    int ind = 1;
    bitset<maxn> used;
    vector<int> paint;
    for (int i : s[x]) {
        if (!c[i]) paint.push_back(i);
        else used[c[i]] = true;
        color = max(color, c[i]);
    }
    for (int i : paint) {
        while (used[ind]) ++ind;
        c[i] = ind; used[c[i]] = true;
        color = max(color, c[i]);
    }
    for (int u : G[x]) if (u != fa) {
        dfs(u, x);
    }
}