#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 510;

int mp[N][N];
int vis[N], cnt[N];
char res[N];
int n, m, u, v;

int dfs (int u, int c) {
    vis[u] = c;
    for (int i = 1; i <= n; i++) if (mp[u][i]) {
        if (vis[i] == c) return 0;
        if (!vis[i]) if (dfs (i, -c) == 0) return 0;
    }
    return 1;
}

int jug () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i != j) {
            if (!mp[i][j]) {
//                cout << i << ' ' << j <<endl;
                if (res[i] == 'a' && res[j] == 'c' || res[i] == 'c' && res[j] == 'a') return 0;
//                return 0;
            }
        }
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cnt[i] = n - 1;
        for (int j = 1; j <= n; j++) if (i != j) {
            mp[i][j] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &u, &v);
        mp[u][v] = mp[v][u] = 0;
        cnt[u]--;
        cnt[v]--;
    }
    for (int i = 1; i <= n; i++) if (cnt[i] && vis[i] == 0) {
        if (dfs (i, 1) == 0) {
            cout << "No\n";
            return 0;
        }
    }
//    cout << 'x';
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) res[i] = 'b';
        if (vis[i] == 1) res[i] = 'a';
        if (vis[i] == -1) res[i] = 'c';
    }
//    for (int i = 1; i <= n; i++) cout << res[i];
    if (jug ()) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) cout << res[i];
    } else cout << "No\n";
}