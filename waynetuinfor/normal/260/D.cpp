#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int c[maxn], s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> c[i] >> s[i];
    set<pair<int, int>> st[2];
    for (int i = 0; i < n; ++i) st[c[i]].insert(make_pair(s[i], i));
    vector<tuple<int, int, int>> ans;
    int t = n - 1;
    while (t--) {
        int cur = -1;
        if (st[0].size() == 1) cur = 1;
        else if (st[1].size() == 1) cur = 0;
        else cur = (st[0].begin()->first < st[1].begin()->first ? 0 : 1);
        int z, w; tie(w, z) = *st[cur].begin();
        st[cur].erase(make_pair(w, z));
        int y, x; tie(y, x) = *st[cur ^ 1].lower_bound(make_pair(w, -1));
        ans.emplace_back(z, x, w);
        st[cur ^ 1].erase(make_pair(y, x));
        st[cur ^ 1].insert(make_pair(y - w, x));
    }
    for (auto i : ans) {
        int a, b, c; tie(a, b, c) = i;
        cout << a + 1 << ' ' << b + 1 << ' ' << c << endl;
    }
    return 0;
}