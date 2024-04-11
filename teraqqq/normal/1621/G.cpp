#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n), values;
    for (int& x : a) cin >> x, values.push_back(x);

    sort(begin(values), end(values));
    for (int& x : a) x = lower_bound(begin(values), end(values), x) - begin(values);

    vector<int> xid(n, -1);
    vector<int> st, stid;
    for (int i = n; i--; ) {
        int j = upper_bound(begin(st), end(st), a[i]) - begin(st);
        if (j < size(st)) {
            xid[i] = stid[j];
        } else {
            if (st.empty() || a[i] > st.back()) {
                st.push_back(a[i]);
                stid.push_back(i);
            }
        }
    }

    vector<int> seq(n, 1), dp2(n, 1), dps(n, 0);
    vector<int> fnw(n+7);

    auto change = [&](int i, int x) {
        for (; i < fnw.size(); i |= i + 1) {
            fnw[i] += x;
            if (fnw[i] >= MOD) fnw[i] -= MOD;
        }
    };

    auto sum = [&] (int l, int r) -> int {
        ll res = 0;
        for (int j = r;   j >= 0; j = (j&j+1) - 1) res += fnw[j];
        for (int j = l-1; j >= 0; j = (j&j+1) - 1) res -= fnw[j];
        res %= MOD;
        if (res < 0) res += MOD;
        return res;
    };

    for (int i = 0; i < n; ++i) {
        seq[i] = (1 + sum(0, a[i]-1)) % MOD;
        change(a[i], seq[i]);
    }

    fill(begin(fnw), end(fnw), 0);
    for (int i = n; i--;  ) {
        dp2[i] = (1 + sum(a[i]+1, n-1)) % MOD;
        change(a[i], dp2[i]);
    }

    int ans = 0;

    fill(begin(fnw), end(fnw), 0);
    for (int i = n; i--; ) {
        if (xid[i] == -1) continue;

        dps[i] = (1 + sum(a[i]+1, a[xid[i]]-1)) % MOD;
        change(a[i], dps[i]);

        ans = (ans + (ll) seq[i] * (dp2[i] - dps[i])) % MOD;
        if (ans < 0) ans += MOD;
    }

/*
    for (int x : seq) cout << x << ' '; cout << endl;
    for (int x : dp2) cout << x << ' '; cout << endl;
    for (int x : dps) cout << x << ' '; cout << endl;
    for (int x : xid) cout << x << ' '; cout << endl;
*/

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}