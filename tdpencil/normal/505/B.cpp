#include <bits/stdc++.h>
using namespace std;

int G[100][100][100];
// graph to x, y, color
bool vis[100];

bool dfs(int val, int target, int exit) {
    if(target==exit) {
        return 1;
    }
    if(vis[target]) return 0;
    vis[target]=1;
    bool works = 0;
    for(int i = 0; i < 100; i++) {
        if(G[target][i][val]&&!vis[i]) {
            works |= dfs(val, i, exit);
        }
    }

    return works;
}
void run_case() {
    int n, m;
    cin >> n >> m;

    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c, --a, --b, --c;
        G[a][b][c]=1;
        G[b][a][c]=1;
    }

    int q; cin >> q;
    while(q--) {
        int r, v; cin >> r >> v, --r, --v;
        int ans = 0;
        for(int i=0;i<100;i++) {
            ans += dfs(i, r, v);
            memset(vis, 0, sizeof vis);
        }
        cout << ans << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

#ifdef RUN_CASE
    cin >> T;
#endif

    for(int test_case = 0; test_case < T; test_case++)
        run_case();
}