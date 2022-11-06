#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
#define var(...) #__VA_ARGS__" = " << (__VA_ARGS__) << " "
struct debug {
~debug() { cerr << endl; }
template <class c> typename \
enable_if <sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename \
enable_if <sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class c, class b> debug &operator<<(pair<c, b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> debug &operator<<(rge<c> d) { *this << "[ "; for (auto it = d.bg; it != d.ed; ++it) *this << ", " + 2 * (it == d.bg) << *it; return *this << " ]"; }
};

const int maxn = 3000 + 10;
const long long inf = 1e18;
long long dp[maxn][maxn], a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] -= i, v.push_back(a[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    // debug() << var(v);
    // for (int i = 1; i <= n; ++i) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) dp[0][i] = min(dp[0][i], dp[0][i - 1]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= v.size(); ++j) dp[i][j] = dp[i - 1][j] + abs(a[i] - v[j - 1]);
        // for (int j = 1; j <= v.size(); ++j) debug() << "dp[" << i << "][" << j << "] = " << dp[i][j];
        for (int j = 1; j <= v.size(); ++j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
    long long ans = inf;
    for (int i = 1; i <= v.size(); ++i) ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}