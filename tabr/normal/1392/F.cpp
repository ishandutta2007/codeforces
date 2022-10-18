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
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    ll s = accumulate(h.begin(), h.end(), 0LL);
    ll k = (s - n * (n - 1) / 2) / n;
    ll t = s - k * n - n * (n - 1) / 2;
    vector<ll> ans(n, k);
    for (int i = 0; i < n; i++) {
        ans[i] += i + (i < t);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}