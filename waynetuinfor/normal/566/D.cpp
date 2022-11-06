#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

struct djset {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
    void merge(int u, int v) { p[find(u)] = find(v); }
} djs;

set<pair<pair<int, int>, int>> st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    djs.init();
    for (int i = 1; i <= n; ++i) st.insert(make_pair(make_pair(i, i), i));
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            auto itx = --(st.upper_bound(make_pair(make_pair(x, maxn), -1)));
            auto ity = --(st.upper_bound(make_pair(make_pair(y, maxn), -1)));
            djs.merge(itx->second, ity->second);
        }
        if (t == 2) {
            auto it = --(st.upper_bound(make_pair(make_pair(x, maxn), -1)));
            pair<pair<int, int>, int> now = *it;
            while (it != st.end()) {
                if (next(it) == st.end()) break;
                if (next(it)->first.first > y) break;
                now.first.second = next(it)->first.second;
                djs.merge(now.second, next(it)->second);
                st.erase(next(it));
            }
            st.erase(it);
            st.insert(now);
        }
        if (t == 3) {
            auto itx = --(st.upper_bound(make_pair(make_pair(x, maxn), -1)));
            auto ity = --(st.upper_bound(make_pair(make_pair(y, maxn), -1)));
            if (djs.find(itx->second) == djs.find(ity->second)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}