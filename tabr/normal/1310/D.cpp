#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int a, int b) {  // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> c(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    int loop = 10000;
    ll ans = 1e18;
    while (loop--) {
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = get_rand(0, 1);
        }
        vector<vector<ll>> d = c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i] == p[j]) {
                    d[i][j] = 1e12;
                }
            }
        }
        vector<ll> x(n, 1e12);
        x[0] = 0;
        for (int l = 0; l < k; l++) {
            vector<ll> y(n, 1e12);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    y[i] = min(y[i], x[j] + d[i][j]);
                }
            }
            swap(x, y);
        }
        ans = min(ans, x[0]);
    }
    cout << ans << '\n';
    return 0;
}