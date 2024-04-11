#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1000 + 10;
int a[maxn], n;

set<pair<int, int>> s;
unordered_map<int, int> m;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) ++m[a[i]];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j) {
            if (s.count(make_pair(a[i], a[j]))) continue;
            vector<int> f = { a[i], a[j] };
            --m[a[i]]; --m[a[j]];
            while (m[f[f.size() - 1] + f[f.size() - 2]]) {
                --m[f[f.size() - 1] + f[f.size() - 2]];
                f.push_back(f[f.size() - 1] + f[f.size() - 2]);
            }
            s.insert(make_pair(a[i], a[j]));
            ans = max(ans, (int)f.size());
            for (int k : f) ++m[k];
        }
    }
    cout << ans << endl;
    return 0;
}