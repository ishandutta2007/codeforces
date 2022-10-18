#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<ll> a(1);
    char c = s[0];
    rep(i, 0, n) {
        if (s[i] == c) {
            a.back()++;
        } else {
            a.emplace_back(1);
            c = s[i];
        }
    }
    vector<ll> b = a;

    for (int i = b.size() - 2; i >= 0; i--) {
        b[i] = b[i + 1] + a[i];
    }
    ll ans = 0;
    rep(i, 0, b.size()) {
        ans += a[i] * (a[i] - 1) / 2LL;
        if (i < (int)b.size() - 1)
            ans += (a[i] - 1) * (a[i + 1] - 1);
        if (i < (int)b.size() - 2)
            ans += a[i] * b[i + 2];
    }
    cout << ans << endl;
}