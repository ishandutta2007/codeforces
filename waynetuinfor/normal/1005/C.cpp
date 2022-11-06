#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
bool v[maxn];

map<int, int> cnt, z;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (__builtin_popcount(x) == 1) {
            ++z[x];
            continue;
        }
        a.push_back(x);
        ++cnt[x];
    }
    int ans = 0;
    for (auto it : z) {
        a.push_back(it.first);
        if (it.second == 1) ++cnt[it.first];
    }
    sort(a.begin(), a.end()), a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; (1ll << j) <= 2000000000; ++j) {
            int x = (1ll << j) - a[i];
            if (x < a[i]) continue;
            int b = lower_bound(a.begin(), a.end(), x) - a.begin();
            if (b < a.size() && a[b] == x && x != a[i]) {
                v[i] = v[b] = true;
            }
        }
        if (!v[i]) ans += cnt[a[i]];
    }
    cout << ans << endl;
}