#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), a(n), b(n);
    set<pair<int, int>> s[4];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[a[i]].insert({p[i], i});
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s[b[i]].insert({p[i], i});
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        if ((int) s[c].size() == 0) {
            cout << -1 << " ";
        } else {
            auto it = s[c].begin();
            int j = it -> second;
            cout << it -> first << " ";
            auto it1 = s[a[j]].find({p[j], j});
            if (it1 != s[a[j]].end()) {
                s[a[j]].erase({p[j], j});
            }
            auto it2 = s[b[j]].find({p[j], j});
            if (it2 != s[b[j]].end()) {
                s[b[j]].erase({p[j], j});
            }
        }
    }
    return 0;
}