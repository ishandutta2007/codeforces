#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll z = a[1] - a[0];
    rep(i, 2, n) z = __gcd(z, a[i] - a[i - 1]);
    ll y = 0;
    rep(i, 0, n) y += (a[n - 1] - a[i]) / z;
    cout << y << ' ' << z << endl;

    return 0;
}