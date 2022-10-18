#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    rep(i, 0, n) {
        ll b;
        cin >> b;
        a[i].first = -b;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i, 0, n) {
        ans -= a[i].first * i - 1;
    }
    cout << ans << endl;
    rep(i, 0, n) cout << a[i].second << ' ';
    cout << endl;

    return 0;
}