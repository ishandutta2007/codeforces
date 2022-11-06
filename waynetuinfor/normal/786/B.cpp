#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e18 + 1;
vector<pair<int, int>> G[maxn << 3];
int stamp;
long long d[maxn << 3];
bool v[maxn << 3];

struct Seg {
    Seg *lc, *rc;
    int id;
#define M ((L + R) >> 1)
    Seg(int L, int R, int t) {
        id = ++stamp;
        lc = rc = nullptr;
        if (L == R) {
            if (t == 1) G[id].push_back(make_pair(L, 0));
            else G[L].push_back(make_pair(id, 0));
            return;
        }
        lc = new Seg(L, M, t); rc = new Seg(M + 1, R, t);
        if (t == 1) G[id].push_back(make_pair(lc->id, 0)), G[id].push_back(make_pair(rc->id, 0));
        else G[lc->id].push_back(make_pair(id, 0)), G[rc->id].push_back(make_pair(id, 0));
    }
    void modify1(int L, int R, int l, int r, int v, int w) {
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            G[v].push_back(make_pair(id, w));
            return;
        }
        lc->modify1(L, M, l, r, v, w); rc->modify1(M + 1, R, l, r, v, w);
    }
    void modify2(int L, int R, int l, int r, int v, int w) {
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            G[id].push_back(make_pair(v, w));
            return;
        }
        lc->modify2(L, M, l, r, v, w); rc->modify2(M + 1, R, l, r, v, w);
    }
#undef M
} *st1, *st2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, s; cin >> n >> q >> s;
    stamp = n; st1 = new Seg(1, n, 1); st2 = new Seg(1, n, 2);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int v, u, w; cin >> v >> u >> w;
            G[v].push_back(make_pair(u, w));
        }
        if (t == 2) {
            int v, l, r, w; cin >> v >> l >> r >> w;
            st1->modify1(1, n, l, r, v, w);
        }
        if (t == 3) {
            int v, l, r, w; cin >> v >> l >> r >> w;
            st2->modify2(1, n, l, r, v, w);
        }
    }
    fill(d, d + (maxn << 3), inf); d[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0, s));
    // for (int i = 1; i <= n; ++i) cout << d[i] << ' '; cout << endl;
    while (pq.size()) {
        pair<long long, int> p = pq.top(); pq.pop();
        // cout << p.first << ' ' << p.second << endl;
        if (v[p.second]) continue;
        v[p.second] = true;
        for (pair<long long, int> e : G[p.second]) {
            if (d[e.first] > p.first + e.second) {
                d[e.first] = p.first + e.second;
                pq.push(make_pair(d[e.first], e.first));
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << (d[i] == inf ? -1 : d[i]) << ' '; cout << endl;
    return 0;
}