#include <bits/stdc++.h>

using namespace std;
using ll = long  long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

void solve() {
    int n; cin >> n;
    vi a(n);
    ll s = 0;
    for (int& x : a) {
        cin >> x;
        s += x;
    }

    bool prime = true;
    for (int d = 2; d*d <= s; ++d) {
        if (s % d == 0) prime = false;
    }

    if (!prime) {
        cout << n << endl;
        for (int i = 1; i <= n; ++i) cout << i << ' ';
    } else {
        cout << n - 1 << endl;
        int j = 0;
        for (int i = n; i--; ) if (a[i] % 2 != 0) j = i;
        for (int i = 1; i <= n; ++i) {
            if (i != j + 1) cout << i << ' ';
        }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}