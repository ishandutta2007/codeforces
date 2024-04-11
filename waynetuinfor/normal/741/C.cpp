#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int a[maxn], b[maxn], c[maxn];
bool v[maxn];
vector<int> vec;

int dfs(int now, int col) {
    c[now] = col;
    for (int u : G[now]) if (!c[u]) dfs(u, 3 - col);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]); G[b[i]].push_back(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int p = 2 * i, q = 2 * i + 1;
        if (q > 2 * n) q = 1;
        G[p].push_back(q); G[q].push_back(p);
    }
    for (int i = 1; i <= 2 * n; ++i) if (!c[i]) dfs(i, 1); 
    for (int i = 1; i <= n; ++i) cout << c[a[i]] << ' ' << c[b[i]] << endl;
    return 0;
}