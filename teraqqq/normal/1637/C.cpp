#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    if (n == 3 && a[1] % 2) {
        cout << -1 << '\n';
    } else {
        bool ok = false;
        ll sum = 0;
        for (int i = 1; i + 1  < n; ++i) {
            if (a[i] > 1) ok = true;
            sum += (a[i] + 1) / 2;
        }

        if (ok) {
            cout << sum << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}