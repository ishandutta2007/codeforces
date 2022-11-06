#include <bits/stdc++.h>
using namespace std;

const int kC = 5000 + 5;
int pc[kC][kC], ck[kC];
bool prime[kC];

int main() {
    vector<int> p;
    for (int i = 2; i < kC; ++i) {
        if (!prime[i]) {
            p.push_back(i);
            for (int j = i + i; j < kC; j += i) prime[j] = true;
        }
    }
    int m = p.size();
    for (int i = 1; i < kC; ++i) {
        int v = i;
        for (int j = 0; j < m; ++j) {
            while (v % p[j] == 0) ++pc[i][j], v /= p[j];
        }
    }
    for (int i = 1; i < kC; ++i) {
        for (int j = 0; j < m; ++j) pc[i][j] += pc[i - 1][j];
    }
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int k; scanf("%d", &k);
        ++ck[k];
    }
    vector<map<int, pair<int, int>>> t(1);
    vector<int> sz(1);
    int root = 0;
    for (int i = 0; i < kC; ++i) {
        if (ck[i] == 0) continue;
        int nd = root;
        for (int j = m - 1; j >= 0; --j) {
            if (pc[i][j] == 0) continue;
            int dist = 0;
            while (t[nd].find(j) != t[nd].end()) {
                dist += t[nd][j].second;
                nd = t[nd][j].first;
            }
            assert(dist <= pc[i][j]);
            if (dist < pc[i][j]) {
                int g = t.size();
                t.emplace_back();
                sz.emplace_back();
                t[nd][j] = make_pair(g, pc[i][j] - dist);
                nd = g;
            }
        }
        sz[nd] += ck[i];
    }
    vector<long long> dp(sz.size());

    function<void(int)> Dfs = [&](int x) {
        for (auto it : t[x]) {
            int u = it.second.first, w = it.second.second;
            Dfs(u);
            sz[x] += sz[u];
            dp[x] += dp[u] + 1LL * sz[u] * w;
        }
        // printf("x = %d sz = %d dp = %lld\n", x, sz[x], dp[x]);
    };

    function<long long(int, int, int, long long)> Dfs2 = [&](int x, int fsz, int fe, long long fd) {
        long long res = dp[x] + fd + 1LL * fsz * fe;
        for (auto it : t[x]) {
            int u = it.second.first, w = it.second.second;
            int ksz = sz[x] + fsz - sz[u];
            long long kd = dp[x] + fd + 1LL * fsz * fe - dp[u] - 1LL * sz[u] * w;
            res = min(res, Dfs2(u, ksz, w, kd));
        }
        return res;
    };

    Dfs(0);
    printf("%lld\n", Dfs2(0, 0, 0, 0));
}