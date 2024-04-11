#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
int a[maxn];
vector<pair<long long, int>> mon;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) mon.push_back(make_pair((long long)a[i] * (long long)j, j));
    }
    sort(mon.begin(), mon.end());
    int q; cin >> q;
    while (q--) {
        long long x; cin >> x;
        int ans = 100;
        for (int i = 0; i < n; ++i) {
            for (int t = 0; t <= k; ++t) {
                long long c = (long long)a[i] * t;
                long long d = x - c;
                if (d < 0) break;
                auto it = lower_bound(mon.begin(), mon.end(), make_pair(d, -1));
                if (it != mon.end() && it->first == d && it->second + t <= k) ans = min(ans, it->second + t);
            }
        }
        if (ans == 100) ans = -1;
        cout << ans << endl;
    }
    return 0;
}