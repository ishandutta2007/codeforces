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
    vector<int> v(n);
    for (int& x : v) {
        cin >> x;
        x = x ? 1 : 2;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += v[i] * (i+1) * (n-i);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}