#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n, -1e9) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] = max(a[i - 1], v);
    }
    T qry(int x) {
        T ret = -1e9;
        if(x < 0) return ret;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret = max(ret, a[i - 1]);
        return ret;
    }
};
// 0 <= x < n

int syn(int x) {
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}

int solve(vector<int> a) {
    int n = a.size();
    vector<ll> s(n + 1);
    for(int i = 0; i < n; ++i) s[i + 1] = a[i] + s[i];
    vector<ll> b = s;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    auto f = [&](ll x) {return lower_bound(b.begin(), b.end(), x) - b.begin();};
    int m = b.size();
    vector<ll> dp(n + 1);
    fenwick<ll> fen(m);
    fen.add(f(0), 0);
    for(int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + syn(a[i - 1]);
        dp[i] = max(dp[i], fen.qry(f(s[i]) - 1) + i);
        fen.add(f(s[i]), dp[i] - i);
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        cout << solve(a) << '\n';
    }
}