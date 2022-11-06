#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
pair<pair<int, int>, int> s[maxn];
pair<pair<int, int>, pair<int, int>> a[maxn];
int ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i].first.first >> s[i].first.second, s[i].second = i;
    int m; cin >> m;
    for (int i = 0; i < m; ++i) cin >> a[i].first.first >> a[i].first.second >> a[i].second.first, a[i].second.second = i;
    sort(s, s + n); sort(a, a + m);
    set<pair<int, pair<int, int>>> st;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        while (ind < m && a[ind].first.first <= s[i].first.first) st.insert(make_pair(a[ind].first.second, a[ind].second)), ++ind;
        auto it = st.lower_bound(make_pair(s[i].first.second, make_pair(-1, -1)));
        if (it == st.end()) return cout << "NO" << endl, 0;
        ans[s[i].second] = it->second.second;
        if (it->second.first - 1 > 0) st.insert(make_pair(it->first, make_pair(it->second.first - 1, it->second.second)));
        st.erase(it);
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' '; cout << endl;
}