#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
map<int, vector<int>> cub, pref;
int c[maxn], s[maxn], ans, bst1, bst2;
multiset<pair<int, int>> ms[maxn];

void upd(int idx, multiset<pair<int, int>>::reverse_iterator it) {
    if (pref[idx].back() + it->first <= ans) return;
    ans = pref[idx].back() + it->first;
    bst1 = idx; bst2 = it->second;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> ds;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> s[i];
        cub[c[i]].push_back(i);
        ds.push_back(c[i]);
    }
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    sort(ds.begin(), ds.end(), [&](const int &i, const int &j) { return cub[i].size() < cub[j].size(); });
    for (auto it = cub.begin(); it != cub.end(); ++it) {
        sort(it->second.begin(), it->second.end(), [&](const int &i, const int &j) { return s[i] > s[j]; });
        pref[it->first].resize(it->second.size());
        pref[it->first][0] = s[it->second[0]];
        for (int i = 1; i < it->second.size(); ++i) pref[it->first][i] = pref[it->first][i - 1] + s[it->second[i]];
    }
    for (auto it = pref.begin(); it != pref.end(); ++it) {
        for (int j = 0; j < it->second.size(); ++j) ms[j + 1].insert(make_pair(it->second[j], it->first));
    }
    for (int i : ds) {
        for (int j = 0; j < pref[i].size(); ++j) ms[j + 1].erase(ms[j + 1].find(make_pair(pref[i][j], i))); 
        int sz = pref[i].size(), sum = pref[i].back();
        if (ms[sz].size()) upd(i, ms[sz].rbegin());
        if (sz > 0 && ms[sz - 1].size()) upd(i, ms[sz - 1].rbegin());
        if (ms[sz + 1].size()) upd(i, ms[sz + 1].rbegin());
    }
    cout << ans << endl;
    int now = ans - pref[bst1].back();
    int sz = lower_bound(pref[bst2].begin(), pref[bst2].end(), now) - pref[bst2].begin() + 1;
    cout << sz + pref[bst1].size() << endl;
    if (pref[bst1].size() == sz) {
        for (int i = 0; i < sz; ++i) cout << cub[bst1][i] << ' ' << cub[bst2][i] << ' ';
        cout << endl;
    } else if (pref[bst1].size() > sz) {
        cout << cub[bst1][0] << ' ';
        for (int i = 0; i < sz; ++i) cout << cub[bst2][i] << ' ' << cub[bst1][i + 1] << ' ';
        cout << endl;
    } else {
        cout << cub[bst2][0] << ' ';
        for (int i = 0; i < cub[bst1].size(); ++i) cout << cub[bst1][i] << ' ' << cub[bst2][i + 1] << ' ';
        cout << endl;
    }
    return 0;
}