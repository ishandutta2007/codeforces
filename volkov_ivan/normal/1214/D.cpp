#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 7;
vector <int> g[MAX_N], g_prime[MAX_N];
bool vis1[MAX_N], vis2[MAX_N];
int diff[MAX_N];
int n, m;


int to_num(int i, int j) {
    return (i - 1) * m + j;
}

bool ok(int i, int j) {
    return (i > 0 && j > 0 && i <= n && j <= m);
}

void dfs1(int v) {
    vis1[v] = 1;
    for (int u : g[v]) {
        if (!vis1[u]) dfs1(u);
    }
}

void dfs2(int v) {
    vis2[v] = 1;
    for (int u : g_prime[v]) {
        if (!vis2[u]) dfs2(u);
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(diff, 0, sizeof(diff));
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    int finish = n * m;
    char field[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> field[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (field[i][j] == '.' && ok(i - 1, j) && field[i - 1][j] == '.') g_prime[to_num(i, j)].push_back(to_num(i - 1, j));
            if (field[i][j] == '.' && ok(i + 1, j) && field[i + 1][j] == '.') g[to_num(i, j)].push_back(to_num(i + 1, j));
            if (field[i][j] == '.' && ok(i, j - 1) && field[i][j - 1] == '.') g_prime[to_num(i, j)].push_back(to_num(i, j - 1));
            if (field[i][j] == '.' && ok(i, j + 1) && field[i][j + 1] == '.') g[to_num(i, j)].push_back(to_num(i, j + 1));
        }
    }
    dfs1(1);
    dfs2(finish);
    if (!vis1[finish]) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= finish; i++) {
        for (int u : g[i]) {
            if (vis1[i] && vis2[u]) {
                diff[i + 1]++;
                diff[u]--;
            }
        }
    }
    int cur = 0;
    for (int i = 1; i <= finish; i++) {
        cur += diff[i];
        if (cur == 0 && i != 1 && i != finish) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    return 0;
}