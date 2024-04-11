#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        vector<int> n(3);
        vector<vector<ll>> v(3);
        for (int i = 0; i < 3; i++) {
            cin >> n[i];
        }
        for (int i = 0; i < 3; i++) {
            v[i].resize(n[i]);
            for (int j = 0; j < n[i]; j++) {
                cin >> v[i][j];
            }
            sort(v[i].begin(), v[i].end());
            v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
            n[i] = v[i].size();
            v[i].emplace_back(1e18);
        }
        ll ans = 9e18;
        auto calc = [&](ll x, ll y, ll z) {
            return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
        };
        for (int p = 0; p < 3; p++) {
            for (int q = 0; q < 2; q++) {
                int j = 0, k = 0;
                for (int i = 0; i < n[0]; i++) {
                    while (j + 1 < n[1] && v[1][j + 1] < v[0][i]) {
                        j++;
                    }
                    ll x = v[0][i], y = v[1][j];
                    while (k + 1 < n[2] && v[2][k + 1] < y) {
                        k++;
                    }
                    for (int s = max(0, j - 2); s <= min(n[1] - 1, j + 2); s++) {
                        for (int t = max(0, k - 4); t <= min(n[2] - 1, k + 4); t++) {
                            ans = min(ans, calc(x, v[1][s], v[2][t]));
                        }
                    }
                }
                if (q) break;
                swap(v[1], v[2]);
                swap(n[1], n[2]);
            }
            swap(v[0], v[1]);
            swap(n[0], n[1]);
        }
        cout << ans << '\n';
    }
    return 0;
}