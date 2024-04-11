// 1301F
// Super Jaber

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 998244353
#define maxn 1010

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
int c, d, mt[maxn][maxn], rs[100010], dist[maxn][maxn];
vector<array<int, 2>> cadj[maxn];
bool vis[maxn][maxn], cvis[maxn];
queue<array<int, 2>> q;
vector<array<int, 4>> v;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool oob(int x, int y) {
    if (x <= 0 || x > n || y <= 0 || y > m) return true;
    return false;
}

void nxt(int x, int y, int d) {
    if (oob(x, y) || vis[x][y]) return;
    vis[x][y] = true; dist[x][y] = d;
    q.push({x, y});
}

void bfs() {
    int i, x, y, c;
    while (!q.empty()) {
        array<int, 2> o = q.front(); q.pop();
        x = o[0]; y = o[1];
        for (i = 0; i < 4; i++) nxt(x + dx[i], y + dy[i], dist[x][y] + 1);

        c = mt[x][y];
        if (cvis[c]) continue;
        cvis[c] = true;
        for (auto u : cadj[c]) nxt(u[0], u[1], dist[x][y] + 1);
    }
}

void init(int c) {
    int i, j, x, y;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            vis[i][j] = false; dist[i][j] = INF;
        }
    }
    for (auto u : cadj[c]) {
        x = u[0]; y = u[1];
        vis[x][y] = true; dist[x][y] = 0; q.push({x, y});
    }

    for (i = 1; i <= k; i++) cvis[i] = false;
    cvis[c] = true;

    bfs();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> mt[i][j];
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cadj[mt[i][j]].pb({i, j});
        }
    }

    cin >> t; v.pb({0, 0, 0, 0});
    for (i = 1; i <= t; i++) {
        cin >> a >> b >> c >> d; v.pb({a, b, c, d});
    }

    for (j = 0; j <= k; j++) {
        if (j != 0) init(j);
        for (i = 1; i <= t; i++) {
            if (j == 0) rs[i] = abs(v[i][0] - v[i][2]) + abs(v[i][1] - v[i][3]);
            else rs[i] = min(rs[i], dist[v[i][0]][v[i][1]] + dist[v[i][2]][v[i][3]] + 1);
        }
    }

    for (i = 1; i <= t; i++) cout << rs[i] << nl;

    return 0;
}