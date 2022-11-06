#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int deg[maxn], s[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> deg[i] >> s[i];
    queue<int> q;
    for (int i = 0; i < n; ++i) if (deg[i] == 1) q.push(i);
    vector<pair<int, int>> ans;
    while (q.size()) {
        int now = q.front(); q.pop();
        if (deg[now] == 0) continue;
        ans.emplace_back(minmax(now, s[now]));
        s[s[now]] ^= now;
        --deg[s[now]];
        if (deg[s[now]] == 1) q.push(s[now]);
    }
    sort(ans.begin(), ans.end()); ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    for (auto i : ans) cout << i.first << ' ' << i.second << endl;
}