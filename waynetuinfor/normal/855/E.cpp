#include <bits/stdc++.h>
using namespace std;

long long dp[11][61][1024][2];
bool v[11][61][1024][2];

long long dfs(int b, int x, int s, int z) {
    if (x < 0) {
        if (s == 0 && z == 0) return 1;
        return 0;
    }
    if (v[b][x][s][z]) return dp[b][x][s][z];
    dp[b][x][s][z] = 0;
    for (int i = 0; i < b; ++i) {
        if (i == 0 && z == 0) dp[b][x][s][z] += dfs(b, x - 1, s ^ (1 << i), 0) + dfs(b, x - 1, s ^ (1 << i), 1);
        if (i != 0 && z == 1) dp[b][x][s][z] += dfs(b, x - 1, s ^ (1 << i), 0) + dfs(b, x - 1, s ^ (1 << i), 1);
    }
    v[b][x][s][z] = true;
    return dp[b][x][s][z];
}

long long solve(int b, long long x) {
    vector<int> dg;
    int pmask = 0;
    long long tx = x;
    while (tx) dg.push_back(tx % b), pmask ^= (1 << (tx % b)), tx /= b;
    long long res = 0;
    if (pmask == 0 && x != 0) ++res;
    int mask = 0;
    for (int i = dg.size() - 1; i >= 0; --i) {
        if (i < dg.size() - 1) res += dfs(b, i, 0, 1);
        for (int j = 0; j < dg[i]; ++j) {
            if (i == dg.size() - 1 && j == 0) continue;
            res += dfs(b, i - 1, mask ^ (1 << j), 0) + dfs(b, i - 1, mask ^ (1 << j), 1);
        }
        mask ^= (1 << dg[i]);
    }
    return res;
}

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int b; long long l, r; scanf("%d %lld %lld", &b, &l, &r);
        printf("%lld\n", solve(b, r) - solve(b, l - 1));
    }
    return 0;
}