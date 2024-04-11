#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

void solve() {
    int n, k; cin >> n >> k;

    ll ans = -1e18;
    vector<int> a(n); for (int& x : a) cin >> x;

    for (int i = n; i--; ) {
        for (int j = i-1; j >= 0 && j >= n - 3*k - 5; --j) {
            ans = max(ans, (ll)(i+1)*(j+1) - k * (a[i] | a[j]));
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
}