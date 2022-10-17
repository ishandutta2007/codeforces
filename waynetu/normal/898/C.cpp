#include <bits/stdc++.h>
using namespace std;

bool check(string a, string b) {
    if (a.size() > b.size()) return false;
    if (a == b) return true;
    if (b.substr(b.size() - a.size(), a.size()) == a) return true;
    return false;
}

map<string, vector<string>> mp, ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        int k; cin >> k;
        vector<string> v(k);
        for (int j = 0; j < k; ++j) cin >> v[j], mp[name].push_back(v[j]);
    }
    for (auto it : mp) {
        bitset<10000> b;
        sort(it.second.begin(), it.second.end()); it.second.resize(unique(it.second.begin(), it.second.end()) - it.second.begin());
        for (int j = 0; j < it.second.size(); ++j) {
            for (int p = 0; p < it.second.size(); ++p) if (j != p && !b[p]) if (check(it.second[j], it.second[p])) b[j] = true;
        }
        for (int j = 0; j < it.second.size(); ++j) if (!b[j]) ans[it.first].push_back(it.second[j]);
    }
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first << ' ' << it.second.size() << ' ';
        for (auto s : it.second) cout << s << ' ';
        cout << endl;
    }
    return 0;
}