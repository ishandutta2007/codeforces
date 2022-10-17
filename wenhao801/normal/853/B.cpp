#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

#define pii pair <int, int>
#define fr first
#define se second
int n, m, K;

const int MAXN = 100100, inf = 1e9 + 7;
#define size(v) (int(v.size()))
vector <pii> I[MAXN], O[MAXN];
vector <int> suf, now;

using ll = long long;
int L = 1, R = 1e6; ll ans[MAXN * 10];

int main () {
    n = read(), m = read(), K = read(); int i, j, k;
    for (i = 1; i <= m; i++) {
        int d = read(), f = read(), t = read(), c = read();
        if (f) O[f].emplace_back(d + 1, c);
        else I[t].emplace_back(d - K, c);
    }
    for (i = 1; i <= n; i++) {
        sort(I[i].begin(), I[i].end()); sort(O[i].begin(), O[i].end());
        if (I[i].empty() || O[i].empty()) { L = inf; break; }
        suf.clear();
        suf.resize(size(I[i]) + 1); suf[size(I[i])] = inf;
        for (j = size(I[i]) - 1; j >= 0; j--) suf[j] = min(suf[j + 1], I[i][j].se);
        int cur = inf;  
        L = max(L, O[i][0].fr), R = min(R, I[i].back().fr);

        now.clear();
        for (auto k: O[i]) now.push_back(k.fr);
        for (auto k: I[i]) now.push_back(k.fr + 1);
        sort(now.begin(), now.end());
        int j = -1, k = 0, las = 0; 
        for (auto it: now) {
            while (j < size(O[i]) - 1 && O[i][j + 1].fr <= it) ++j, cur = min(cur, O[i][j].se);
            while (k < size(I[i]) && I[i][k].fr < it) ++k;
            int cost = suf[k] + cur;
            // printf("? %d %d | %d %d | suf = %d, cur = %d\n", it, cost, j, k, suf[k], cur);
            ans[max(0, it)] += cost - las; las = cost;
        }
        // putchar('\n');
    }
    // printf("%d %d\n", L, R);
    for (i = 1; i <= R; i++) ans[i] += ans[i - 1];
    if (L > R) puts("-1");
    else printf("%lld\n", *min_element(ans + L, ans + R + 1));
    return 0;
}