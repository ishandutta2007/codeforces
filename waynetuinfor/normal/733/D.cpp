#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> v[maxn];

map<pair<int, int>, multiset<pair<int, int>>> m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        v[i].resize(3);
        for (int j = 0; j < 3; ++j) cin >> v[i][j];
        sort(v[i].begin(), v[i].end());
        for (int j = 0; j < 3; ++j) {
            m[minmax(v[i][j], v[i][(j + 1) % 3])].insert(make_pair(v[i][(j + 2) % 3], i));
        }
    }
    pair<int, pair<int, int>> ans = make_pair(0, make_pair(0, 0));
    for (int i = 1; i <= n; ++i) ans = max(ans, make_pair(v[i][0], make_pair(i, 0)));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            multiset<pair<int, int>>& s = m[minmax(v[i][j], v[i][(j + 1) % 3])];
            if (s.size() == 1) continue;
            s.erase(s.find(make_pair(v[i][(j + 2) % 3], i)));
            auto k = *s.rbegin();
            int l = min({ v[i][j], v[i][(j + 1) % 3], v[i][(j + 2) % 3] + k.first });
            ans = max(ans, make_pair(l, make_pair(i, k.second)));
            
        }
    }
    int k = 1;
    if (ans.second.second && ans.second.second != ans.second.first) ++k;
    cout << k << endl;
    cout << ans.second.first << ' ';
    if (ans.second.second && ans.second.second != ans.second.first) cout << ans.second.second << endl;
    return 0;
}