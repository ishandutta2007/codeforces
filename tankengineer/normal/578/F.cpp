#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;

int MOD;

int n, m;

char map[N][N];

int fa[N * N], col[N * N];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    fa[u] = v;
}

const int M = 405;

int a[M][M];

int inverse(int a) {
    return a == 1 ? 1 : MOD - (long long)MOD / a * inverse(MOD % a) % MOD;
}

int det(int a[M][M], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] %= MOD;
            if (a[i][j] < 0) {
                a[i][j] += MOD;
            }
        }
    }
    int ret = 1, sign = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i][i] == 0) {
            for (int j = i + 1; j < n; ++j) {
                if (a[j][i]) {
                    for (int k = i; k < n; ++k) {
                        swap(a[j][k], a[i][k]);
                    }
                    sign = -sign;
                    break;
                }
            }
        }
        if (a[i][i] == 0) {
            return 0;
        }
        ret = (long long)ret * a[i][i] % MOD;
        int re = inverse(a[i][i]);
        for (int j = i + 1; j < n; ++j) {
            if (a[j][i]) {
                int d = (long long)a[j][i] * re % MOD;
                for (int k = i; k < n; ++k) {
                    if ((a[j][k] -= (long long)a[i][k] * d % MOD) < 0) {
                        a[j][k] += MOD;
                    }
                }
            }
        }
    }
    if (sign == -1 && ret) {
        ret = MOD - ret;
    }
    return ret;
}

int solve(vector<pair<int, int> > &edge, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < edge.size(); ++i) {
        int u = edge[i].first, v = edge[i].second;
        ++a[u][u], ++a[v][v];
        --a[u][v], --a[v][u];
    }
    return det(a, n - 1);
}

vector<pair<int, int> > edge[2];

int main() {
    scanf("%d%d%d", &n, &m, &MOD);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < (n + 1) * (m + 1); ++i) {
        fa[i] = i;
    }
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int ul = i * (m + 1) + j, ur = ul + 1,
                dl = (i + 1) * (m + 1) + j, dr = dl + 1;
            if (map[i][j] == '/') {
                flag = flag || find(dl) == find(ur);
                merge(find(dl), find(ur));
            } else if (map[i][j] == '\\') {
                flag = flag || find(dr) == find(ul);
                merge(find(dr), find(ul));
            } else {
                int c = (i ^ j) & 1;
                edge[c].push_back(make_pair(ul, dr));
                edge[c ^ 1].push_back(make_pair(ur, dl));
            }
        }
    }
    if (flag) {
        printf("0\n");
        return 0;
    }
    int cnt[2] = {0, 0};
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int c = (i ^ j) & 1,
                id = i * (m + 1) + j;
            if (fa[id] == id) {
                col[id] = cnt[c]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < (int)edge[i].size(); ++j) {
            edge[i][j] = make_pair(col[find(edge[i][j].first)], col[find(edge[i][j].second)]);
        }
        (ans += solve(edge[i], cnt[i])) %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}