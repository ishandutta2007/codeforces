#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    ll s = 0;
    bool wasZero = false;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        if (s < 0 || (a[i] && wasZero)) {
            cout << "No" << '\n';
            return;
        }
        if (s == 0) wasZero = true;
    }

    cout << (s == 0 ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}