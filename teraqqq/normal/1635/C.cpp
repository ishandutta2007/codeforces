#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    if (a[n-2] > a[n-1]) {
        cout << -1 << '\n';
    } else if (is_sorted(a.begin(), a.end())) {
        cout << 0 << '\n';
    } else if (a.back() < 0) {
        cout << -1 << '\n';
    } else {
        vector<array<int, 3>> ans;

        for (int i = n-2; i >= 0;  i--) {
            if (a[i] <= a[i+1]) continue;

            ans.push_back(array { i, i+1, n-1 });
            a[i] = a[i+1] - a[n-1];
        }

        cout << ans.size() << '\n';
        for (auto [x, y, z] : ans) cout << x+1 << " " << y+1 << " " << z+1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    cin >> t;
    while (t--) solve();
}