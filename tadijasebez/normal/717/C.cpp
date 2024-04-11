#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll x = 0, m = 10007;
    for (int i = 0; i < n; i++) {
        x += a[i] * a[n - i - 1];
    }
    cout << x % m << endl;
    return 0;
}