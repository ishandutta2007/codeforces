#include <bits/stdc++.h>
using namespace std;

void Solve() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> g(26);
    vector<int> uf(26);
    for (int i = 0; i < 26; ++i) uf[i] = i;

    function<int(int)> Find = [&](int x) {
        if (uf[x] == x) return x;
        return uf[x] = Find(uf[x]);
    };

    auto Merge = [&](int x, int y) {
        uf[Find(x)] = Find(y);
    };

    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1]) {
            cout << "NO\n";
            return;
        }
        g[s[i] - 'a'].push_back(s[i + 1] - 'a');
        g[s[i + 1] - 'a'].push_back(s[i] - 'a');
        Merge(s[i] - 'a', s[i + 1] - 'a');
    }
    for (int i = 0; i < 26; ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
        if (g[i].size() > 2) {
            cout << "NO\n";
            return;
        }
    }
    vector<vector<int>> nd(26);
    for (int i = 0; i < 26; ++i) nd[Find(i)].push_back(i);
    string res = "";
    for (int i = 0; i < 26; ++i) {
        if (Find(i) != i) continue;
        if (nd[i].size() == 1) {
            res += (i + 'a');
            continue;
        }
        vector<vector<int>> hd(2);
        for (int u : nd[i]) {
            hd[g[u].size() - 1].push_back(u); 
        }
        if (hd[0].size() != 2) {
            cout << "NO\n";
            return;
        }
        int u = hd[0][0], p = -1;
        while (true) {
            res += (u + 'a');
            int w = -1;
            for (int v : g[u]) {
                if (v != p) w = v;
            }
            if (w == -1) break;
            p = u;
            u = w;
        }
    }
    cout << "YES\n";
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) Solve();
}