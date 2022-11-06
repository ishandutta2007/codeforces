#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 7;
vector<pair<int, int>> graf[maxn];
bool v[maxn], inq[maxn];
int tpow[maxn], fr[maxn];

struct segtree {
    segtree *lc, *rc;
    int hv, hv2;
    segtree(int l, int r, int v) {
        hv = 0;
        if (l == r) hv = v, lc = rc = nullptr;
        else lc = new segtree(l, (l + r) / 2, v), rc = new segtree((l + r) / 2 + 1, r, v), pull(l, r);
    }
    segtree(segtree *t) { hv = t->hv, hv2 = t->hv2, lc = t->lc, rc = t->rc; }
    void pull(int l, int r) {
        hv = rc->hv * 1ll * tpow[(l + r) / 2 - l + 1] % mod + lc->hv;
        hv %= mod;
    }
    int leq(segtree *t, int l, int r) {
        if (l == r) return (t->hv == 1 && hv == 0);
        if (t->rc->hv == rc->hv) return lc->leq(t->lc, l, (l + r) / 2);
        else return rc->leq(t->rc, (l + r) / 2 + 1, r);
    }
    int query(int l, int r, int p) const {
        if (l == r) return hv;
        if (p <= (l + r) / 2) return lc->query(l, (l + r) / 2, p);
        else return rc->query((l + r) / 2 + 1, r, p);
    }
    segtree *add(int l, int r, int p, int v) {
        segtree *ret = new segtree(this);
        if (l == r) return ret->hv = v, ret;
        if (p <= (l + r) / 2) ret->lc = lc->add(l, (l + r) / 2, p, v);
        else ret->rc = rc->add((l + r) / 2 + 1, r, p, v);
        ret->pull(l, r);
        return ret;
    }
    int final(int l, int r) {
        if (l == r) return hv;
        return (rc->final((l + r) / 2 + 1, r) * 1ll * tpow[(l + r) / 2 - l + 1] % mod + lc->final(l, (l + r) / 2)) % mod;
    }
} *sgt[maxn];

struct cmp {
    bool operator()(const pair<segtree*, int> &i, const pair<segtree*, int> &j) { return !(i.first->leq(j.first, 0, maxn)); }  
};

segtree *add(segtree *t, int p) {
    segtree *ret = t;
    while (ret->query(0, maxn, p) == 1) {
        ret = ret->add(0, maxn, p, 0);
        ++p;
    }
    ret = ret->add(0, maxn, p, 1);
    return ret;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    while (m--) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        graf[a].emplace_back(b, c); graf[b].emplace_back(a, c);
    }
    tpow[0] = 1; 
    for (int i = 1; i < maxn; ++i) tpow[i] = tpow[i - 1] * 1ll * 2 % mod;
    int s, t; scanf("%d %d", &s, &t);
    sgt[s] = new segtree(0, maxn, 0);
    if (s != t) sgt[t] = new segtree(0, maxn, 1);
    for (int i = 1; i <= n; ++i) if (i != s && i != t) sgt[i] = sgt[t];
    priority_queue<pair<segtree*, int>, vector<pair<segtree*, int>>, cmp> pq;
    pq.emplace(sgt[s], s); 
    while (pq.size()) {
        int now = pq.top().second; pq.pop();
        if (v[now]) continue;
        v[now] = true;
        for (auto u : graf[now]) {
            segtree *tmp = add(sgt[now], u.second);
            if (tmp->leq(sgt[u.first], 0, maxn)) {
                sgt[u.first] = tmp;
                fr[u.first] = now;
                pq.emplace(sgt[u.first], u.first);
            } 
        }
    }
    stack<int> ans;
    if (!v[t]) return 0 * puts("-1");
    printf("%d\n", sgt[t]->final(0, maxn));
    while (t != s) {
        ans.push(t);
        t = fr[t];
    }
    ans.push(s);
    printf("%d\n", ans.size());
    while (ans.size()) printf("%d ", ans.top()), ans.pop(); puts("");
    return 0;
}