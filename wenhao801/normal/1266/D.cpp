#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
ll a[100100];
vector <int> vp, vq;

struct edge { int u, v; ll w; }; vector <edge> ans;

int main() {
    int n = read(), m = read();
    while (m--) {
        int u = read(), v = read(), w = read();
        a[u] += w; a[v] -= w;
    }
    for (int i = 1; i <= n; i++) if (a[i] >= 0) vp.push_back(i); else vq.push_back(i);
    auto p = vp.begin(), q = vq.begin();
    while (p != vp.end() && !a[*p]) ++p;
    while (q != vq.end() && !a[*q]) ++q;
    while (p != vp.end() && q != vq.end()) {
        const ll val = min(a[*p], -a[*q]);
        ans.push_back({*p, *q, val});
        a[*p] -= val; while (p != vp.end() && !a[*p]) ++p;
        a[*q] += val; while (q != vq.end() && !a[*q]) ++q;
    }
    printf("%d\n", ans.size());
    for (auto e: ans) printf("%d %d %lld\n", e.u, e.v, e.w);
    return 0;
}