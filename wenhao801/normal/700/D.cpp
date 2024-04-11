#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
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

#define size(v) (int(v.size()))
using ll = long long;
const int MAXN = 100100, B = 320;
int n, m, a[MAXN];

struct qry { int id, l, r; } q[MAXN];
int buc[MAXN], bbuc[MAXN];

#define pii pair <ll, int>
#define fr first
#define se second

vector <int> sp; bool isp[MAXN];
inline void add (int u) { u = a[u]; if (!isp[u]) --bbuc[buc[u]]; ++buc[u]; if (!isp[u]) ++bbuc[buc[u]]; }
inline void del (int u) { u = a[u]; if (!isp[u]) --bbuc[buc[u]]; --buc[u]; if (!isp[u]) ++bbuc[buc[u]]; }

// priority_queue <pii, vector <pii>, greater <pii>> pq;
vector <pii> tmp;
struct Queue {
    pii val[MAXN]; int head, tail;
    inline void clear() { head = tail = 0; }
    inline void push(pii x) { val[tail++] = x; }
    inline void pop() { ++head; }
    inline bool empty() { return head == tail; }
    inline pii front() { return val[head]; }
} q1, q2;

ll ans[MAXN];

int pre[MAXN];
int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read(), pre[i] = i / B, ++buc[a[i]];
    for (i = 1; i <= int(1e5); i++) if (buc[i] >= B) sp.emplace_back(i), isp[i] = 1;
    memset(buc, 0, sizeof buc);
    m = read();
    for (i = 1; i <= m; i++) q[i].l = read(), q[i].r = read(), q[i].id = i;
    sort(q + 1, q + m + 1, [](qry u, qry v) { return pre[u.l] == pre[v.l] ? ((pre[u.l] & 1) ? (u.r < v.r) : (u.r > v.r)) : (u.l < v.l); });
    int l = 1, r = 0;
    bbuc[0] = 1e5;
    for (i = 1; i <= m; i++) {
        while (r < q[i].r) add(++r);
        while (l > q[i].l) add(--l);
        while (r > q[i].r) del(r--);
        while (l < q[i].l) del(l++);
        tmp.clear();
        for (int i = 1; i <= B; i++) if (bbuc[i]) tmp.push_back({i, bbuc[i]});
        for (auto i: sp) if (buc[i]) tmp.push_back({buc[i], 1});
        sort(tmp.begin(), tmp.end());
        for (auto i: tmp) q1.push(i);
        while (!q1.empty() || !q2.empty()) {
            pii u;
            if (q2.empty() || (!q1.empty() && !q2.empty() && q1.front() < q2.front())) u = q1.front(), q1.pop();
            else u = q2.front(), q2.pop();
            if (u.se >= 2) q2.push({u.fr << 1, u.se >> 1}), ans[q[i].id] += 1ll * (u.fr << 1) * (u.se >> 1);
            if (u.se & 1) {
                if (q1.empty() && q2.empty()) break;
                
                if (q2.empty() || (!q1.empty() && !q2.empty() && q1.front() < q2.front())) {
                    pii v = q1.front();
                    ans[q[i].id] += u.fr + v.fr; q2.push({u.fr + v.fr, 1});
                    if (v.se >= 2) --q1.val[q1.head].se; else q1.pop();
                }
                else {
                    pii v = q2.front();
                    ans[q[i].id] += u.fr + v.fr; q2.push({u.fr + v.fr, 1});
                    if (v.se >= 2) --q2.val[q2.head].se; else q2.pop();
                }
            }
        }
        q1.clear(), q2.clear();
    }
    for (i = 1; i <= m; i++) printf("%lld\n", ans[i]);
    return 0;
}