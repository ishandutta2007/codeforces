#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 607, INF = 1e9 + 2007;
int f[N][N];
//int f_mod[N][N];
int dist[N];
bool vis[N];

void calc(int s, int n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[s] = 0;
    int v = s;
    while (v != -1) {
        //cout << v << endl;
        vis[v] = 1;
        int tm = dist[v] % n;
        int zero_cannon = n - tm;
        if (zero_cannon == n)
            zero_cannon = 0;

        int pos = zero_cannon;
        int cur_best = f[v][pos];
        for (int i = 0; i < n - 1; i++) {
            if (pos == 0)
                pos = n;
            pos--;
            cur_best = min(cur_best, f[v][pos] + i + 1);
        }
        pos = zero_cannon;
        int nxt = -1;
        dist[0] = min(dist[0], dist[v] + cur_best);
        if (!vis[0])
            nxt = 0;
        for (int i = 1; i < n; i++) {
            cur_best++;
            zero_cannon++;
            if (zero_cannon == n)
                zero_cannon = 0;
            cur_best = min(cur_best, f[v][zero_cannon]);
            dist[i] = min(dist[i], dist[v] + cur_best);
            if (!vis[i] && (nxt == -1 || dist[i] < dist[nxt])) {
                nxt = i;
            }
        }
        v = nxt;
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        f[a][b] = c;
    }
    for (int i = 0; i < n; i++)
        calc(i, n);
    return 0;
}