#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int p[maxn];
vector<pair<int, int>> G[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, d; cin >> n >> k >> d;
    for (int i = 0; i < k; ++i) cin >> p[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(make_pair(b, i)); G[b].push_back(make_pair(a, i));
    }
    queue<pair<pair<int, int>, int>> que;
    for (int i = 0; i < k; ++i) que.push(make_pair(make_pair(p[i], -1), 0));
    vector<int> ans;
    while (que.size()) {
        pair<pair<int, int>, int> p = que.front(); que.pop();
        if (v[p.first.first]) {
            if (p.first.second != -1) ans.push_back(p.first.second);
            continue;
        }
        v[p.first.first] = true;
        for (pair<int, int> e : G[p.first.first]) {
            if (v[e.first]) continue;
            que.push(make_pair(make_pair(e.first, e.second), p.second + 1));
        }
    }
    sort(ans.begin(), ans.end()); ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    for (int i : ans) cout << i + 1 << ' '; cout << endl;
    return 0;
}