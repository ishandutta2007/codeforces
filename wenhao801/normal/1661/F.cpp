#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
int n;

ll sq (ll x) { return 1ll * x * x; }
ll val (ll d, ll k) {
    k = min(k, d); ll tmp = d / k, mod = d - k * tmp;
    return 1ll * mod * sq(tmp + 1) + 1ll * (k - mod) * sq(tmp);
}
struct node {
    ll d, k, delta;
    node (ll _d = 0, ll _k = 0) { d = _d, k = _k, delta = val(d, k) - val(d, k + 1); }
    bool operator < (const node &other) const { return delta < other.delta; }
};
priority_queue <node> pq;

int main () {
    n = read(); int i, j, last = 0;
    ll cost = 0;
    for (i = 1; i <= n; i++) j = read(), pq.push(node(j - last, 1)), cost += sq(j - last), last = j;
    ll m, ans = 0; scanf("%lld", &m);
    while (cost > m) {
        node x = pq.top(); pq.pop();
        ll d = x.d, k = x.k, delta = x.delta;
        ll nex = (d / k) != (d / (k + 1)) ? (k + 1) : (d / (d / k)), can = nex - k;
        if (cost - can * delta > m) cost -= can * delta, ans += can;
        else { ans += (cost - m + delta - 1) / delta; break; }
        if (nex < d) pq.push(node(d, nex));
    }
    printf("%lld\n", ans);
    return 0;
}