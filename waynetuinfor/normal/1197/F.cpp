#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 1000 + 5;
int f[3][3], adj[64][64], tab[maxn][4], a[maxn];
bool used[4];
vector<pair<int, int>> color[maxn];

using matrix = array<array<int, 64>, 64>;

matrix pw[30];

matrix mult(const matrix &a, const matrix &b) {
    matrix res;
    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; ++j) res[i][j] = 0;
    }

    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; ++j) {
            for (int k = 0; k < 64; ++k) {
                res[i][j] += a[i][k] * 1ll * b[k][j] % mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

array<int, 64> push(array<int, 64> dp, int step) {
    array<int, 64> res = dp;
    for (int i = 0; i < 30; ++i) {
        if (step >> i & 1) {
            array<int, 64> nxt{};
            for (int j = 0; j < 64; ++j) {
                for (int k = 0; k < 64; ++k) {
                    nxt[k] += res[j] * 1ll * pw[i][j][k] % mod;
                    nxt[k] %= mod;
                }
            }
            res = nxt;
        }
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int m; scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x, y, c; scanf("%d%d%d", &x, &y, &c);
        color[x - 1].emplace_back(y, c - 1);
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            scanf("%d", &f[i][j]);
    }

    auto mex = [&](vector<int> v) {
        memset(used, false, sizeof(used));
        for (int i : v) used[i] = true; 
        int res = 0;
        while (used[res]) res++;
        return res;
    };

    for (int j = 0; j < 64; ++j) {
        int sg[3], p = j;
        for (int k = 0; k < 3; ++k) {
            sg[k] = p & 3;
            p >>= 2;
        }
        for (int k = 0; k < 3; ++k) {
            vector<int> v;
            for (int r = 0; r < 3; ++r) {
                if (f[k][r]) v.push_back(sg[r]);
            }
            int to = mex(v);
            int nxt = to | (sg[0] << 2) | (sg[1] << 4);
            adj[j][nxt]++;
        }
    }

    matrix p;
    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; ++j) p[i][j] = adj[i][j];
    }
    for (int i = 0; i < 30; ++i) {
        pw[i] = p;
        p = mult(p, p);
    }

    auto debug = [&](string msg, array<int, 64> x) {
        cout << msg << endl;
        for (int i = 0; i < 64; ++i) cout << x[i] << ' ';
        cout << endl;
    };

    for (int i = 0; i < n; ++i) {
        array<int, 64> dp{};
        dp[63] = 1;
        sort(color[i].begin(), color[i].end());
        int prv = 0;
        for (int j = 0; j < (int)color[i].size(); ++j) {
            int step = color[i][j].first - prv - 1;
            array<int, 64> tdp = push(dp, step);
            array<int, 64> rdp{};
            for (int k = 0; k < 64; ++k) {
                int sg[3], p = k;
                for (int z = 0; z < 3; ++z) {
                    sg[z] = p & 3;
                    p >>= 2;
                }
                vector<int> v;
                for (int r = 0; r < 3; ++r) {
                    if (f[color[i][j].second][r]) v.push_back(sg[r]);
                } 
                int to = mex(v);
                int nxt = to | (sg[0] << 2) | (sg[1] << 4);
                (rdp[nxt] += tdp[k]) %= mod;
            }
            dp = rdp;
            prv = color[i][j].first;
        }
        if (prv != a[i]) {
            int step = a[i] - prv;
            dp = push(dp, step);
        }
        for (int j = 0; j < 64; ++j) {
            int f = j & 3;
            (tab[i][f] += dp[j]) %= mod;
        }
    }

    array<int, 4> ans;
    for (int i = 0; i < 4; ++i) ans[i] = tab[0][i];
    for (int i = 1; i < n; ++i) {
        array<int, 4> nxt{};
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                nxt[j ^ k] += ans[j] * 1ll * tab[i][k] % mod;
                nxt[j ^ k] %= mod;
            }
        }
        ans = nxt;
    }
    printf("%d\n", ans[0]);
    return 0;
}