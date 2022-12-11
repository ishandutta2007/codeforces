#include <bits/stdc++.h>
//#define int long long

using namespace std;

struct query{
    pair <int, int> a, b, c;
    query() {}
    query(pair <int, int> a, pair <int, int> b, pair <int, int> c): a(a), b(b), c(c) {}
};

const int N = 107;
bool f[N][N];

vector <query> res;

void chng(pair <int, int> a, pair <int, int> b, pair <int, int> c) {
    f[a.first][a.second] ^= 1;
    f[b.first][b.second] ^= 1;
    f[c.first][c.second] ^= 1;
    res.push_back(query(a, b, c));
}

void solve_2(int n, int m) {
    int cnt = 0;
    cnt += f[n - 1][m - 1];
    cnt += f[n - 2][m - 1];
    cnt += f[n - 1][m - 2];
    cnt += f[n - 2][m - 2];
    //cout << cnt << endl;
    if (cnt == 0)
        return;
    if (cnt == 4) {
        chng({n - 1, m - 1}, {n - 1, m - 2}, {n - 2, m - 1});
        chng({n - 1, m - 1}, {n - 1, m - 2}, {n - 2, m - 2});
        chng({n - 1, m - 1}, {n - 2, m - 2}, {n - 2, m - 1});
        chng({n - 1, m - 2}, {n - 2, m - 2}, {n - 2, m - 1});
        return;
    }
    if (cnt == 3) {
        vector <pair <int, int>> cur;
        if (f[n - 1][m - 1]) cur.push_back({n - 1, m - 1});
        if (f[n - 1][m - 2]) cur.push_back({n - 1, m - 2});
        if (f[n - 2][m - 1]) cur.push_back({n - 2, m - 1});
        if (f[n - 2][m - 2]) cur.push_back({n - 2, m - 2});
        chng(cur[0], cur[1], cur[2]);
        return;
    }
    if (cnt == 2) {
        vector <pair <int, int>> cur;
        int tot = 0;
        for (int i = n - 2; i <= n - 1; i++) {
            for (int j = m - 2; j <= m - 1; j++) {
                if (f[i][j] && tot == 0) {
                    cur.push_back({i, j});
                    tot = 1;
                }
                if (!f[i][j] && cur.size() < 3)
                    cur.push_back({i, j});
            }
        }
        chng(cur[0], cur[1], cur[2]);
        solve_2(n, m);
        return;
    }
    vector <pair <int, int>> cur;
    int tot = 0;
    for (int i = n - 2; i <= n - 1; i++) {
        for (int j = m - 2; j <= m - 1; j++) {
            if (!f[i][j] && tot + 1 < 3) {
                cur.push_back({i, j});
                tot++;
            }
            if (f[i][j])
                cur.push_back({i, j});
        }
    }
    chng(cur[0], cur[1], cur[2]);
    solve_2(n, m);
}

void solve() {
    int n, m;
    cin >> n >> m;
    res.clear();
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)  {
            if (s[j] == '0')
                f[i][j] = 0;
            else 
                f[i][j] = 1;
        }
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m; j++) {
            if (!f[i][j])
                continue;
            if (j != 0)
                chng({i, j}, {i + 1, j - 1}, {i + 1, j});
            else 
                chng({i, j}, {i + 1, j}, {i + 1, j + 1});
        }
    }
    for (int j = 0; j < m - 2; j++) {
        if (!f[n - 2][j] && !f[n - 1][j])
            continue;
        vector <pair <int, int>> cur;
        if (f[n - 2][j])
            cur.push_back({n - 2, j});
        if (f[n - 1][j])
            cur.push_back({n - 1, j});
        if (cur.size() < 3)
            cur.push_back({n - 1, j + 1});
        if (cur.size() < 3)
            cur.push_back({n - 2, j + 1});
        chng(cur[0], cur[1], cur[2]);
    }
    solve_2(n, m);
    cout << res.size() << "\n";
    assert(res.size() <= n * m);
    for (auto elem : res) {
        cout << elem.a.first + 1 << ' ' << elem.a.second + 1 << ' ' << elem.b.first + 1 << ' ' << elem.b.second + 1 << ' ' << elem.c.first + 1 << ' ' << elem.c.second + 1 << "\n";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            assert(!f[i][j]);
        }
    }
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}