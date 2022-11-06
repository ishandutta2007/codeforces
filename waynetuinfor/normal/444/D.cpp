#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    map<int, int> id;
    vector<vector<int>> pos;

    constexpr int kP = 131;
    constexpr int kM = 1'000'000'000 + 87;

    auto Hash = [&](const string &s) {
        int res = 0;
        for (char c : s) res = (1LL * res * kP + c) % kM;
        return res;
    };

    auto Insert = [&](int v, int p) {
        if (id.find(v) != id.end()) {
            pos[id[v]].push_back(p);
            return;
        }
        int nid = id.size();
        id[v] = nid;
        pos.push_back({p});
    };

    for (int k = 1; k <= 4; ++k) {
        for (int i = 0; i + k <= n; ++i) {
            int hv = Hash(s.substr(i, k));
            Insert(hv, i);
        }
    }
    int q; cin >> q;
    map<pair<int, int>, int> cache;
    while (q--) {
        string a, b; cin >> a >> b;
        int x = Hash(a), y = Hash(b);
        if (id.find(x) == id.end() || id.find(y) == id.end()) {
            cout << "-1\n";
            continue;
        }
        x = id[x], y = id[y];
        if (pos[x].size() > pos[y].size()) {
            swap(x, y);
            swap(a, b);
        }
        if (cache.find(make_pair(x, y)) != cache.end()) {
            cout << cache[make_pair(x, y)] << "\n";
            continue;
        }
        int ans = n + 1;
        for (int u : pos[x]) {
            auto it = lower_bound(pos[y].begin(), pos[y].end(), u);
            if (it != pos[y].end()) {
                int rb = max(u + a.size(), *it + b.size());
                ans = min(ans, rb - u);
            }
            if (it != pos[y].begin()) {
                int rb = max(u + a.size(), *prev(it) + b.size());
                ans = min(ans, rb - *prev(it));
            }
        }
        cache[make_pair(x, y)] = ans;
        cout << ans << "\n";
    }
    return 0;
}