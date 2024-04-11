#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
char s[maxn][maxn];
int lt[maxn][maxn], rg[maxn][maxn], up[maxn][maxn], dn[maxn][maxn];
int rw[maxn][maxn], cl[maxn][maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*') lt[i][j] = lt[i][j - 1] + 1;
        }
        for (int j = m; j >= 1; --j) {
            if (s[i][j] == '*') rg[i][j] = rg[i][j + 1] + 1;
        }
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (s[i][j] == '*') up[i][j] = up[i - 1][j] + 1;
        }
        for (int i = n; i >= 1; --i) {
            if (s[i][j] == '*') dn[i][j] = dn[i + 1][j] + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') continue;
            int dt = min(min(lt[i][j], rg[i][j]), min(up[i][j], dn[i][j]));
            if (dt == 1) continue;
            rw[i][j - dt + 1]++;
            rw[i][j + dt]--;
            cl[i - dt + 1][j]++;
            cl[i + dt][j]--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) rw[i][j] += rw[i][j - 1];
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) cl[i][j] += cl[i - 1][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*' && rw[i][j] + cl[i][j] == 0) return 0 * puts("-1");
        }
    }
    vector<tuple<int, int, int>> ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') continue;
            int dt = min(min(lt[i][j], rg[i][j]), min(up[i][j], dn[i][j]));
            if (dt > 1) ans.emplace_back(i, j, dt - 1);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d %d %d\n", get<0>(ans[i]), get<1>(ans[i]), get<2>(ans[i]));
    return 0;
}