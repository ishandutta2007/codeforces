#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    map<pair<int, int>, int> mp;
    set<pair<int, int>> st;
    ll all = accumulate(a.begin(), a.end(), 0LL);
    vector<ll> b(n), c(n);
    ll bs = 0, cs = 0;
    ll ans = all;
    while (q--) {
        int s, t, u;
        cin >> s >> t >> u;
        s--, u--;
        if (st.count({s, t})) {
            b[s]--;
            bs--;
            int v = mp[{s, t}];
            if (v != -1) {
                c[v]--;
                cs--;
                if (c[v] < a[v]) {
                    ans++;
                }
            }
        }
        st.emplace(s, t);
        mp[{s, t}] = u;
        b[s]++;
        bs++;
        if (u != -1) {
            c[u]++;
            if (c[u] <= a[u]) {
                ans--;
            }
            cs++;
        }
        cout << max(1LL, ans) << '\n';
    }
    return 0;
}