#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int c[maxn];
bitset<maxn> used;

void dfs(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y; cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x);
    }
    c[1] = 1; dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, c[i]);
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) cout << c[i] << ' '; cout << endl;
    return 0;
}

void dfs(int x, int fa) {
    int ind = 1;
    for (int u : G[x]) if (u != fa) {
        while (ind == c[x] || ind == c[fa]) ++ind;
        c[u] = ind++;
        dfs(u, x);
    }
}