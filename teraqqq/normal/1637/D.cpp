#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const int S = 1e4+1;

void solve() {
    int n; cin >> n;
    int s = 0, ssq = 0;
    vector<int> a(n), b(n);

    for (int& x : a) cin >> x, s += x, ssq += x*x;
    for (int& x : b) cin >> x, s += x, ssq += x*x;

    vector<bitset<S>> dp(n+1);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        dp[i+1] = (dp[i] << a[i]) | (dp[i] << b[i]);
    }

    int ans = numeric_limits<int>::max();

    for (int t = 0; t < S; ++t) {
        if (dp[n][t]) ckmin(ans, ssq * (n-2) + t*t + (s-t)*(s-t));
    }

    cout << ans << '\n';

    //
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}