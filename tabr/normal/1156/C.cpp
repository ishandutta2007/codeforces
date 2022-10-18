#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using P = pair<ll, int>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    ll z;
    cin >> n >> z;
    vector<ll> x(n);
    rep(i, 0, n) cin >> x[i];
    sort(x.begin(), x.end());
    int l = 0, r = n / 2 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        bool ok = true;
        rep(i, 0, m) ok &= (x[i] + z <= x[n - m + i]);
        if (ok)
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    return 0;
}