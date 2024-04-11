#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>
#include <vector>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100010;
int n, a[MAXN], b[MAXN], nex[MAXN]; long long ans[MAXN]; set <int> s;

int ind[MAXN]; vector <int> E[MAXN]; queue <int> q;
int dis(int fr, int to) { if (fr <= to) return to - fr; return to + n - fr; }

int main() {
    n = read(); int i, j, k;
    for (i = 0; i < n; i++) a[i] = read(), b[i] = i;
    sort(b, b + n, [](int u, int v) { return a[u] > a[v]; });
    for (i = 0; i < n; i = j) {
        for (j = i; j < n && a[b[j]] == a[b[i]]; j++) s.insert(b[j]);
        for (j = i; j < n && a[b[j]] == a[b[i]]; j++) {
            auto it = s.upper_bound(b[j]);
            if (it == s.end()) it = s.begin();
            nex[b[j]] = *it;
        }
    }
    reverse(b, b + n); s.clear();
    for (i = 0, k = 0; i < n; i = j) {
        while (k < n && a[b[i]] * 2 >= a[b[k]]) {
            if (s.empty()) { ans[b[k]] = b[k]; ++k; continue; }
            auto it = s.upper_bound(b[k]);
            if (it == s.end()) it = s.begin();
            ans[b[k]] = *it; ++k;
        }
        for (j = i; j < n && a[b[j]] == a[b[i]]; j++) s.insert(b[j]);
    }
    for (i = 0; i < n; i++) {
        int p = nex[i], q = ans[i];
        if (p <= i) p += n; if (q <= i) q += n;
        if (p <= q) E[nex[i]].push_back(i), ++ind[i];
        else if (ans[i] == i) ans[i] = 1e9 + 7;
        else ans[i] = dis(i, ans[i]);
    }
    for (i = 0; i < n; i++) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto i: E[x]) {
            --ind[i]; if (!ind[i]) q.push(i), ans[i] = ans[x] + dis(i, x);
        }
    }
    for (i = 0; i < n; i++) {
        if (ind[i] || ans[i] > 1e9) printf("-1 ");
        else printf("%lld ", ans[i]);
    }
    return 0;
}