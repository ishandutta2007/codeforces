#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<int> s(n), f(m), h(m);
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
        s[i]--;
        pos[s[i]].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &f[i], &h[i]);
        f[i]--;
    }
    vector<int> left(m, -1), right(m, -1);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        if (pos[f[i]].size() >= h[i]) {
            left[i] = pos[f[i]][h[i] - 1];
            right[i] = pos[f[i]][pos[f[i]].size() - h[i]];
            g[f[i]].push_back(i);
        }
    }
    constexpr int kMod = 1'000'000'000 + 7;
    vector<vector<int>> lv(n, vector<int>(n)), rv = lv;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            lv[i][left[g[i][j]]]++;
            rv[i][right[g[i][j]]]++;
        }
        for (int j = 1; j < n; ++j) lv[i][j] += lv[i][j - 1];
        for (int j = n - 2; j >= 0; --j) rv[i][j] += rv[i][j + 1];
    }
    int glob = 0, res = 1;
    for (int k = 0; k < n; ++k) {
        vector<int> ans(n), ways(n);
        int cur = 0, w = 1;
        bool ok = false;
        for (int i = 0; i < m; ++i) {
            if (left[i] == -1) continue;
            if (f[i] == s[k]) {
                if (left[i] == k) {
                    int oth = k + 1 < n ? rv[f[i]][k + 1] : 0;
                    if (right[i] > k) --oth;
                    int c = oth > 0 ? 2 : 1;
                    if (c == 2) cur += 2, w = 1LL * w * oth % kMod;
                    else cur++;
                    ok = true;
                }
                continue;
            }
            if (left[i] < k) {
                int oth = k + 1 < n ? rv[f[i]][k + 1] : 0;
                if (right[i] > k) --oth;
                int c = oth > 0 ? 2 : 1;
                if (c == 2) {
                    if (ans[f[i]] < 2) {
                        ans[f[i]] = 2;
                        ways[f[i]] = oth;
                    } else if (ans[f[i]] == 2) {
                        (ways[f[i]] += oth) %= kMod;
                    }
                } else {
                    if (ans[f[i]] < 1) {
                        ans[f[i]] = 1;
                        ways[f[i]] = 1;
                        if (right[i] > k)
                            (ways[f[i]] += 1) %= kMod;
                    } else if (ans[f[i]] == 1) {
                        (ways[f[i]] += 1) %= kMod;
                        if (right[i] > k)
                            (ways[f[i]] += 1) %= kMod;
                    }
                }
            } else {
                if (right[i] <= k) continue;
                if (ans[f[i]] < 1) {
                    ans[f[i]] = 1;
                    ways[f[i]] = 1;
                } else if (ans[f[i]] == 1) {
                    (ways[f[i]] += 1) %= kMod;
                }
            }
        }
        if (!ok) continue;
        for (int i = 0; i < n; ++i) {
            if (i == s[k]) continue;
            if (ans[i] == 2) {
                cur += 2;
                w = 1LL * w * ways[i] % kMod;
            } else if (ans[i] == 1) {
                cur++;
                w = 1LL * w * ways[i] % kMod;
            } else {
                int cnt = k + 1 < n ? rv[i][k + 1] : 0;
                if (cnt > 0) {
                    cur++;
                    w = 1LL * w * ways[i] % kMod;
                }
            }
        }
        if (cur > glob) {
            glob = cur;
            res = w;
        } else if (glob == cur) {
            (res += w) %= kMod;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (right[i] == -1) continue;
        vector<int> cnt(n), ways(n);
        for (int j = 0; j < m; ++j) {
            if (right[j] > right[i]) cnt[f[j]]++;
        }
        int cur = 1, w = 1;
        for (int j = 0; j < n; ++j) {
            if (j == f[i]) continue;
            if (cnt[j] > 0) cur++, w = 1LL * w * cnt[j] % kMod;
        }
        if (cur > glob) {
            glob = cur;
            res = w;
        } else if (glob == cur) {
            (res += w) %= kMod;
        }
    }
    if (glob == 0) res = 1;
    printf("%d %d\n", glob, res);
}