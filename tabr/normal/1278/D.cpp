#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct unionfind {
    vector<int> par;
    unionfind(int n)
        : par(n, -1) {}

    int find(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }
    int size(int x) {
        return -par[find(x)];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    set<pair<int, int>> st;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        p[i] = {r, l};
        st.emplace(l, i);
        mp[l] = i;
    }
    sort(p.begin(), p.end());
    int cnt = 0;
    unionfind uf(n);
    for (int i = 0; i < n; i++) {
        int l = p[i].second, r = p[i].first;
        pair<int, int> a = {l, n}, b = {r, 0};
        auto beg = st.upper_bound({l, n}), en = st.upper_bound({r, 0});
        auto tmp = beg;
        tmp--;
        a = *tmp;
        b = *en;
        for (auto it = beg; it != en; it++) {
            cnt++;
            b = *it;
            uf.unite(a.second, b.second);
        }
        st.erase({l, mp[l]});
        if (cnt >= n) {
            break;
        }
    }
    debug(uf.par);
    bool ok = true;
    if (cnt != n - 1) {
        ok = false;
    }
    for (int i = 1; i < n; i++) {
        if (!uf.same(0, i)) {
            ok = false;
            break;
        }
    }
    if (ok) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}