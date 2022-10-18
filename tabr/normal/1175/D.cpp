#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n), s(n);
    rep(i, 0, n) cin >> a[i];
    reverse(a.begin(), a.end());
    s[0] = a[0];
    rep(i, 1, n) {
        s[i] = s[i - 1] + a[i];
    }
    ll x = s[n - 1];
    s[n - 1] = -1e18;
    sort(s.begin(), s.end(), greater<ll>());
    cout << accumulate(s.begin(), s.begin() + k - 1, 0ll) + x << endl;

    return 0;
}