#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define PB push_back
const int N = 1e6+5;
mt19937 rng(time(0));
 
int T, n, m, x, y, start, no, mark, f[N];
vector<int> g[N];
 
void dfs(int x) {
    for (auto u : g[x])
        if (f[u] == -1)
            f[u] = f[x] ^ 1, dfs(u);
        else if (f[u] == f[x])
            no++, mark = !f[u];
}
 
bool check() {
    rep(i, 1, n) shuffle(g[i].begin(), g[i].end(), rng);
    rep(i, 1, n) f[i] = -1;
    start = rng() % n + 1, f[start] = no = mark = 0;
    dfs(start);
    if (no <= 2) {
        cout << "YES\n";
        rep(i, 1, n) cout << (f[i] ^ mark);
        cout << "\n";
    }
    return no <= 2;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        rep(i, 1, n) g[i].clear();
        rep(i, 1, m) cin >> x >> y, g[x].PB(y), g[y].PB(x);
        bool flag = false;
        rep(_, 1, 20) if (check()) {
            flag = true;
            break;
        }
        if (!flag)
            cout << "NO\n";
    }
    return 0;
}