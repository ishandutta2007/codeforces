#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], pos[maxn];
vector<int> ans[maxn];
bool vis[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; ++i) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        pos[a[i]] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        ++cnt;
        int cur = i;
        while (!vis[cur]) {
            // cout << "cur = " << cur << endl;
            vis[cur] = true;
            ans[cnt].push_back(pos[cur]);
            cur = pos[cur];
        }
        // cout << "jizz" << endl;
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; ++i) {
        cout << ans[i].size() << ' ';
        sort(ans[i].begin(), ans[i].end());
        for (int j : ans[i]) cout << j << ' '; cout << endl;
    }
    return 0;
}