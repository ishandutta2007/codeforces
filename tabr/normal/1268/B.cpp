#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> x(2);
    rep(i, 0, n) {
        ll a;
        cin >> a;
        x[i % 2] += a / 2;
        x[(i + 1) % 2] += (a + 1) / 2;
    }
    cout << min(x[0], x[1]) << endl;

    return 0;
}