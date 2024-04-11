#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
const long long inf = 1e15;
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 }, cs[] = { 0, 0, 0, 1 };
long long d[maxn][maxn];
bool v[maxn][maxn];
char s[maxn][maxn];

template <typename t>
using heap = priority_queue<t, vector<t>, greater<t>>;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int r, c; scanf("%d%d", &r, &c); --r, --c;
    int lt, rg; scanf("%d%d", &lt, &rg);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) d[i][j] = inf;
    }
    d[r][c] = 0;
    heap<pair<long long, pair<int, int>>> pq;
    pq.emplace(0, make_pair(r, c));
    while (pq.size()) {
        int x, y; tie(x, y) = pq.top().second; pq.pop();
        if (v[x][y]) continue;
        v[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if (s[tx][ty] == '*') continue;
            if (d[x][y] + cs[i] < d[tx][ty]) {
                d[tx][ty] = d[x][y] + cs[i];
                pq.emplace(d[tx][ty], make_pair(tx, ty));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[i][j] > lt) continue;
            long long y = c - d[i][j];
            if (j - y >= 0 && j - y <= rg) ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}