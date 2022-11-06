#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int inf = 1e9;
int a[maxn], b[maxn], d[3][3][maxn][maxn], dr[3][3][maxn][maxn], dp[3][maxn], tr[3][maxn];
bool v[3][3][maxn][maxn];

vector<vector<int>> dx = { {-1, 1, 2, 2, 1, -1, -2, -2}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
vector<vector<int>> dy = { {2, 2, 1, -1, -2, -2, -1, 1}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10} };


template <typename T>
using heap = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n * n; ++i) scanf("%d", &a[i]), --a[i], b[a[i]] = i;
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
        for (int a = 0; a < maxn; ++a) for (int b = 0; b < maxn; ++b) {
            d[i][j][a][b] = inf;
            dr[i][j][a][b] = inf;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n * n; ++j) {
            d[i][i][j][j] = 0;
            dr[i][i][j][j] = 0;
            heap<pair<pair<int, int>, pair<int, int>>> q;
            q.emplace(make_pair(0, 0), make_pair(j, i));
            while (q.size()) {
                int z, t; tie(z, t) = q.top().second; q.pop();
                if (v[i][t][j][z]) continue;
                v[i][t][j][z] = true;
                int x = z / n, y = z % n;
                for (int p = 0; p < dx[t].size(); ++p) {
                    int tx = x + dx[t][p], ty = y + dy[t][p];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                    int tz = tx * n + ty;
                    if (make_pair(d[i][t][j][z] + 1, dr[i][t][j][z]) < make_pair(d[i][t][j][tz], dr[i][t][j][tz])) {
                        d[i][t][j][tz] = d[i][t][j][z] + 1;
                        dr[i][t][j][tz] = dr[i][t][j][z];
                        q.emplace(make_pair(d[i][t][j][tz], dr[i][t][j][tz]), make_pair(tz, t));
                    }
                }
                for (int k = 0; k < 3; ++k) {
                    if (make_pair(d[i][t][j][z] + 1, dr[i][t][j][z] + 1) < make_pair(d[i][k][j][z], dr[i][k][j][z])) {
                        d[i][k][j][z] = d[i][t][j][z] + 1;
                        dr[i][k][j][z] = dr[i][t][j][z] + 1;
                        q.emplace(make_pair(d[i][k][j][z], dr[i][k][j][z]), make_pair(z, k));
                    }
                }
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < maxn; ++j) dp[i][j] = inf;
    }
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for (int i = 0; i < n * n - 1; ++i) {
        for (int t = 0; t < 2; ++t) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (dp[j][i] + 1 < dp[k][i]) {
                        dp[k][i] = dp[j][i] + 1;
                        tr[k][i] = tr[j][i] + 1;
                    } else if (dp[j][i] + 1 == dp[k][i] && tr[j][i] + 1 < tr[k][i]) {
                        tr[k][i] = tr[j][i] + 1;
                    }
                }
            }
        }
        for (int j = 0; j < 3; ++j) for (int k = 0; k < 3; ++k) {
            if (d[j][k][b[i]][b[i + 1]] == inf) continue;
            if (dp[j][i] + d[j][k][b[i]][b[i + 1]] < dp[k][i + 1]) {
                dp[k][i + 1] = dp[j][i] + d[j][k][b[i]][b[i + 1]];
                tr[k][i + 1] = tr[j][i] + dr[j][k][b[i]][b[i + 1]];
            } else if (dp[j][i] + d[j][k][b[i]][b[i + 1]] == dp[k][i + 1] && tr[k][i + 1] > tr[j][i] + dr[j][k][b[i]][b[i + 1]]) {
                tr[k][i + 1] = tr[j][i] + dr[j][k][b[i]][b[i + 1]];
            }
        }
    }
    int ans = inf, z = -1;
    for (int i = 0; i < 3; ++i) {
        if (dp[i][n * n - 1] < ans) {
            ans = dp[i][n * n - 1];
            z = tr[i][n * n - 1];
        } else if (dp[i][n * n - 1] == ans && tr[i][n * n - 1] < z) {
            z = tr[i][n * n - 1];
        }
    }
    printf("%d %d\n", ans, z);
    return 0;
}