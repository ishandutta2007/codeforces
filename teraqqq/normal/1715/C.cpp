#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

void solve() {
    int n, m; cin >> n >> m;

    ll ans = (ll)n*(n+1)/2;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    for (int i = 0; i < n-1; ++i) {
        if (a[i] != a[i+1]) ans += (ll)(i+1)*(n-i-1);
    }

    while (m--) {
        int i, x; cin >> i >> x; --i;

        if (i != n-1 && a[i] != a[i+1]) ans -= (ll)(i+1)*(n-i-1);
        if (i != 0   && a[i] != a[i-1]) ans -= (ll)i*(n-i);
        a[i] = x;
        if (i != n-1 && a[i] != a[i+1]) ans += (ll)(i+1)*(n-i-1);
        if (i != 0   && a[i] != a[i-1]) ans += (ll)i*(n-i);

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}