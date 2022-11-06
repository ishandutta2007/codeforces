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

const int maxn = 2000 + 5, mod = 1e9 + 7;

int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
int mul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1, a = mul(a, a)) if (n & 1) ret = mul(ret, a);
    return ret;
}

int dp[maxn][maxn];
int pa, pb;

int calc(int i, int j) {
    int fr = mul(pa, fpow(fpow(sub(1, pa), 2), mod - 2));
    int ad = mul(pb, fpow(sub(1, pa), mod - 2));
    int ret = add(mul(i + j, ad), mul(pb, fr));
    // debug() << var(fr) << var(ad) << var(ret);
    return ret;
    // return mul(add(i, j), fr); 
}

int main() {
    int k, a, b; cin >> k >> a >> b;
    pa = mul(a, fpow(a + b, mod - 2)), pb = mul(b, fpow(a + b, mod - 2));
    // debug() << var(pa) << var(pb);
    dp[0][0] = mul(pb, fpow(sub(1, pb), mod - 2));
    dp[0][0] = add(1, dp[0][0]);
    // debug() << var(dp[0][0]);
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i + j >= k) {
                // debug() << var(i) << var(j) << var(dp[i][j]);
                ans = add(ans, mul(dp[i][j], calc(i, j)));
                continue;
            }
            dp[i + 1][j] = add(dp[i + 1][j], mul(dp[i][j], pa));
            if (i > 0) dp[i][i + j] = add(dp[i][i + j], mul(dp[i][j], pb));
        }
    }
    cout << ans << endl; 
}