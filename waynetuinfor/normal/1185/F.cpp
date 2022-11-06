#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int b[maxn], a[maxn], c[maxn], p[1 << 9], sub[1 << 9], cnt[1 << 9];
vector<pair<int, int>> v[1 << 9];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int f; scanf("%d", &f);
        for (int j = 0; j < f; ++j) {
            int x; scanf("%d", &x);
            b[i] |= (1 << (x - 1));
        }
        ++cnt[b[i]];
    }

    for (int i = 0; i < m; ++i) {
        int r;
        scanf("%d%d", &c[i], &r);
        for (int j = 0; j < r; ++j) {
            int x; scanf("%d", &x);
            a[i] |= (1 << (x - 1));
        }
        p[a[i]] = min(p[a[i]], c[i]);
        v[a[i]].emplace_back(c[i], i);
    }

    for (int i = 0; i < (1 << 9); ++i) 
        sort(v[i].begin(), v[i].end());

    for (int i = 0; i < (1 << 9); ++i) {
        for (int j = i; j > 0; j = (j - 1) & i)
            sub[i] += cnt[j];
    }

    int ans = 0, cost = 2e9 + 5;
    int j1 = -1, j2 = -1;

    for (int i = 0; i < (1 << 9); ++i) {
        if (v[i].empty()) continue;
        for (int j = 0; j < (1 << 9); ++j) {
            if (i == j) continue;
            if (v[j].empty()) continue;

            if (sub[i | j] > ans || sub[i | j] == ans && v[i][0].first + v[j][0].first < cost) {
                ans = sub[i | j];
                cost = v[i][0].first + v[j][0].first;
                j1 = v[i][0].second;
                j2 = v[j][0].second;
            }
        }

        if ((int)v[i].size() >= 2) {
            if (sub[i] > ans || sub[i] == ans && v[i][0].first + v[i][1].first < cost) {
                ans = sub[i];
                cost = v[i][0].first + v[i][1].first;
                j1 = v[i][0].second;
                j2 = v[i][1].second;
            }
        }
    }

    printf("%d %d\n", j1 + 1, j2 + 1);
    return 0;
}