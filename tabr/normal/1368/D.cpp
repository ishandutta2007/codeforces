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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<int> cnt(30);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 30; j++) {
            if (a[i] & (1 << j)) {
                cnt[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            if (i < cnt[j]) {
                b[i] |= (1 << j);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += b[i] * b[i];
    }
    cout << ans << '\n';
    return 0;
}