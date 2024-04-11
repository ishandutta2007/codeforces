#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 300300;
int n, K, a[MAXN];

struct node { int id; bool operator < (const node &other) const { return a[id] < a[other.id]; } };
priority_queue <node> pq;
int out[MAXN];

using ll = long long;

int main () {
    n = read(), K = read(); int i, j;
    ll s = 0, ans = 0;
    for (i = 1; i <= n + K; i++) {
        if (i <= n) { a[i] = read(); s += a[i], pq.push({i}); }
        if (i > K) { s -= a[pq.top().id], out[pq.top().id] = i; pq.pop(); }
        ans += s;
    }
    printf("%lld\n", ans);
    for (i = 1; i <= n; i++) printf("%d ", out[i]);
    return 0;
}