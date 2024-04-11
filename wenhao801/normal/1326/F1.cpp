#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

using ull = unsigned long long;
#define mask ((1 << n) - 1)
int pc(int x) { return __builtin_popcount(x); }

int n; ull h[22][1 << 18];
char E[22][22];

ull f[22][1 << 18], fac[22] = {1};
map <vector <int>, ull> sav;

vector <int> cur;

void dfs(int s, int lim, int dep) {
    if (!s) {
        ull ans = 0;
        for (int i = 0; i <= mask; i++) ans += f[dep][i] * (((n - pc(i)) & 1) ? -1 : 1);
        vector <int> buc(n + 1);
        for (auto i: cur) ++buc[i];
        // for (auto i: buc) ans /= fac[i];
        // for (auto i: cur) cout << i << ' '; printf(": %llu\n", ans);

        sav[cur] = ans; return;
    }
    for (int i = 1; i <= lim; i++) {
        for (int j = 0; j <= mask; j++) f[dep + 1][j] = f[dep][j] * h[i][j];
        cur.push_back(i);
        dfs(s - i, min(i, s - i), dep + 1);
        cur.pop_back();
    }
}

ull pre[22][1 << 18], g[1 << 17], G[1 << 17];

int main() {
    scanf("%d", &n); int i, j;
    for (i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
    for (i = 0; i < n; i++) scanf("%s", E[i]);
    for (i = 0; i < n; i++) pre[i][1 << i] = 1;
    for (i = 1; i <= mask; i++) {
        for (int u = 0; u < n; u++) if ((i >> u) & 1)
            for (int v = 0; v < n; v++) if (!((i >> v) & 1) && E[u][v] == '1')
                pre[v][i | (1 << v)] += pre[u][i];
    }
    for (i = 0; i < n; i++) for (j = 0; j <= mask; j++) h[pc(j)][j] += pre[i][j];
    for (int p = 1; p <= n; p++) {
        for (i = 2; i <= (1 << n); i <<= 1) 
            for (j = 0; j <= mask; j += i) for (int k = j; k < j + (i >> 1); k++)
                h[p][k + (i >> 1)] += h[p][k];
    }
    for (i = 0; i <= mask; i++) f[0][i] = 1;
    dfs(n, n, 0);

    #undef mask
    #define mask ((1 << (n - 1)) - 1)
    for (i = 0; i <= mask; i++) {
        int cur = 1; vector <int> vec;
        for (j = 0; j < n - 1; j++) {
            if ((i >> j) & 1) ++cur;
            else vec.push_back(cur), cur = 1;
        }
        vec.push_back(cur); sort(vec.begin(), vec.end(), [](int u, int v) { return u > v; });
        g[i] = sav[vec];
    }
    for (i = 2; i <= mask + 1; i <<= 1)
        for (j = 0; j <= mask; j += i)
            for (int k = j; k < j + (i >> 1); k++)
                g[k] -= g[k + (i >> 1)];
    for (i = 0; i <= mask; i++) printf("%llu ", g[i]);
    return 0;
}