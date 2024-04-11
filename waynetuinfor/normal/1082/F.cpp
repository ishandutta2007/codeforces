#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
char s[maxn][maxn];
int f[maxn], ch[maxn][10], sum[maxn], dep[maxn], val[maxn];
int dp[maxn][maxn][11], n, k;
bool v[maxn][maxn];

int gnode(int d = 0) {
    static int sz = 0;
    for (int i = 0; i < 10; ++i) ch[sz][i] = -1;
    dep[sz] = d;
    return sz++;
}

void pull(int o) {
    sum[o] = val[o];
    for (int i = 0; i < 10; ++i) {
        if (~ch[o][i])
            sum[o] += sum[ch[o][i]];
    }
}

void insert(int o, char *s, int d, int n, int p) {
    if (d == n) {
        val[o] += p;
        sum[o] += p;
        return;
    }
    if (ch[o][s[d] - '0'] == -1) ch[o][s[d] - '0'] = gnode(dep[o] + 1);
    insert(ch[o][s[d] - '0'], s, d + 1, n, p);
    pull(o);
}

int dfs(int x, int last, int used) {
    if (v[x][last]) return dp[x][last][used];
    for (int i = 0; i < 10; ++i) {
        if (ch[x][i] == -1) continue;
        vector<int> v(k + 1, 0);
        for (int p = 0; p <= k; ++p) {
            int res = dfs(ch[x][i], last, p);
            v[p] = max(v[p], dp[x][last][p]);
            for (int j = p; j <= k; ++j) v[j] = max(v[j], dp[x][last][j - p] + res);
        }
        for (int p = 0; p <= k; ++p) dp[x][last][p] = v[p];
    }
    vector<int> u(k + 1, 0);
    for (int i = 0; i < 10; ++i) {
        if (ch[x][i] == -1) continue;
        vector<int> v(k + 1, 0);
        for (int p = 0; p <= k; ++p) {
            int res = dfs(ch[x][i], dep[x], p);
            v[p] = max(v[p], u[p]);
            for (int j = p; j <= k; ++j) v[j] = max(v[j], u[j - p] + res);
        }
        for (int p = 0; p <= k; ++p) u[p] = v[p];
    }
    for (int p = 1; p <= k; ++p) dp[x][last][p] = max(dp[x][last][p], u[p - 1] + sum[x] * (dep[x] - last));
    v[x][last] = true;
    return dp[x][last][used];
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%s%d", s[i], &f[i]);
    int root = gnode(), ans = 0;
    for (int i = 0; i < n; ++i) {
        insert(root, s[i], 0, strlen(s[i]), f[i]);
        ans += strlen(s[i]) * f[i];
    }
    int res = 0;
    for (int i = 0; i <= k; ++i) res = max(res, dfs(root, 0, i));
    printf("%d\n", ans - res);
    return 0;
}