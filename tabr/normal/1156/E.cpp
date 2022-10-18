#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int n;
vector<ll> p(200010), q(200000);
vector<vector<int>> d(2, vector<int>(200010));

ll dfs(int l, int r, set<int> &st) {
    if (l >= r || l <= 0 || n < r)
        return 0;
    ll mx = *st.rbegin(), res = 0, pos = q[*st.rbegin()];
    st.erase(*st.rbegin());
    set<int> st2;

    if (pos - l < r - pos) {
        swap(st, st2);
        rep(i, l, pos) {
            st.insert(p[i]);
            st2.erase(p[i]);
            if (pos < q[mx - p[i]] && q[mx - p[i]] <= r)
                res++;
        }
    } else {
        rep(i, pos + 1, r + 1) {
            st.erase(p[i]);
            st2.insert(p[i]);
            if (l <= q[mx - p[i]] && q[mx - p[i]] < pos)
                res++;
        }
    }

    return res + dfs(l, pos - 1, st) + dfs(pos + 1, r, st2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i, 1, n + 1) {
        cin >> p[i];
        q[p[i]] = i;
    }
    set<int> v;
    rep(i, 1, n + 1) v.insert(i);

    cout << dfs(1, n, v) << endl;

    return 0;
}