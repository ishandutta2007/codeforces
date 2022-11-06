#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<int, int>> vec;
    set<int> ri;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        vec.push_back(make_pair(l, 1)); vec.push_back(make_pair(r, -1));
        ri.insert(r);
    }
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });
    int cur = 0, ansl;
    vector<pair<int, int>> ans;
    for (auto e : vec) {
        cur += e.second;
        if (e.second == 1 && cur == k) ansl = e.first;
        else if (e.second == -1 && cur == k - 1) ans.push_back(make_pair(ansl, e.first));
    }
    vector<pair<int, int>> nans;
    for (int i = 0; i < ans.size(); ++i) {
        if (i < ans.size() - 1 && ans[i + 1].first == ans[i].second) {
            nans.push_back(make_pair(ans[i].first, ans[i + 1].second));
            ++i;
        } else nans.push_back(ans[i]);
    }
    cout << nans.size() << endl;
    for (auto p : nans) {
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}