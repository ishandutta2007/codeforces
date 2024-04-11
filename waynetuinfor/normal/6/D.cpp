#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 10;
int n, a, b;
vector<int> ans;
set<pair<vector<int>, int>> s;

void dfs(int now, vector<int> h, vector<int> cur) {
    if (now == n - 1) {
        if (cur.size() < ans.size()) ans = cur;
        return;
    }
    if (s.count(make_pair(h, now))) return;
    s.insert(make_pair(h, now));
    if (cur.size() > ans.size()) return;
    vector<int> hh(h.begin(), h.end());
    vector<int> ncur(cur.begin(), cur.end());
    while (hh[now] >= 0) {
        hh[now] -= a;
        hh[now - 1] -= b;
        hh[now + 1] -= b;
        ncur.push_back(now);
        dfs(now, hh, ncur);
    }
    dfs(now + 1, hh, ncur);
    hh = vector<int>(h.begin(), h.end());
    ncur = vector<int>(cur.begin(), cur.end());
    while (hh[now] >= 0) {
        hh[now] -= b;
        hh[now + 1] -= a;
        hh[now + 2] -= b;
        ncur.push_back(now + 1);
        dfs(now, hh, ncur);
    }
    dfs(now + 1, hh, ncur);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> h;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        h.push_back(x);
    }
    vector<int> cur;
    while (h[0] >= 0) h[1] -= a, h[0] -= b, h[2] -= b, cur.push_back(1);
    while (h[n - 1] >= 0) h[n - 2] -= a, h[n - 1] -= b, h[n - 3] -= b, cur.push_back(n - 2);
    for (int i = 0; i < 1e6; ++i) ans.push_back(-1);
    dfs(1, h, cur);
    cout << ans.size() << endl;
    for (int i : ans) cout << i + 1 << ' '; cout << endl;
    return 0;
}