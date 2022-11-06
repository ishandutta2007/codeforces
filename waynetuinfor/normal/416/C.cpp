#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
pair<pair<int, int>, int> p[maxn];
int r[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i].first.first >> p[i].first.second, p[i].second = i;
    int k; cin >> k;
    for (int i = 1; i <= k; ++i) cin >> r[i];
    sort(p + 1, p + n + 1, [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) { return a.first.second > b.first.second; });
    multiset<pair<int, int>> ms;
    for (int i = 1; i <= k; ++i) ms.insert(make_pair(r[i], i));
    int ans = 0;
    vector<pair<int, int>> vec;
    for (int j = 1; j <= n; ++j) {
        auto i = p[j];
        auto it = ms.lower_bound(make_pair(i.first.first, -1));
        if (it != ms.end()) {
            vec.push_back(make_pair(i.second, it->second));
            ans += i.first.second;
            ms.erase(ms.find(*it));
        }
    }
    cout << vec.size() << ' ' << ans << endl;
    for (auto i : vec) cout << i.first << ' ' << i.second << endl;
    return 0;
}