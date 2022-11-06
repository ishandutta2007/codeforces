#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
long long l[maxn], r[maxn], a[maxn], lb[maxn], ub[maxn];
int ans[maxn];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    set<pair<long long, int>> st;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    for (int i = 0; i < m; ++i) cin >> a[i], st.insert(make_pair(a[i], i));
    vector<int> con;
    for (int i = 0; i < n - 1; ++i) {
        lb[i] = l[i + 1] - r[i];
        ub[i] = r[i + 1] - l[i];
        con.push_back(i);
    }
    sort(con.begin(), con.end(), [&](const int &i, const int &j) { return ub[i] < ub[j]; });
    for (int i = 0; i < con.size(); ++i) {
        auto it = st.lower_bound(make_pair(lb[con[i]], -1));
        if (it == st.end() || it->first > ub[con[i]]) return cout << "No" << endl, 0;
        ans[con[i]] = it->second;
        st.erase(it);
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n - 1; ++i) cout << ans[i] + 1 << ' '; cout << endl;
    return 0;
}