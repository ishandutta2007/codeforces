#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
#define imie(...) #__VA_ARGS__" = " << (__VA_ARGS__) << " "
struct debug {
~debug() { cerr << endl; }
template <class c> typename \
enable_if <sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename \
enable_if <sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class c, class b> debug &operator<<(pair<c, b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> debug &operator<<(rge<c> d) { *this << "[ "; for (auto it = d.bg; it != d.ed; ++it) *this << ", " + 2 * (it == d.bg) << *it; return *this << " ]"; }
};

const int maxn = 18;
double p[maxn][maxn], dp[1 << maxn];
bool v[1 << maxn];
int n;

double dfs(int mask) {
    if (v[mask]) return dp[mask];
    if (__builtin_popcount(mask) == n) return 1.0;
    dp[mask] = 0;
    for (int i = 0; i < n; ++i) if (!((1 << i) & mask)) {
        double d = dfs(mask ^ (1 << i));
        int m = __builtin_popcount(mask) + 1;
        double prob = 1.0 / (m * (m - 1) / 2);
        double s = 0.0;
        for (int j = 0; j < n; ++j) if ((1 << j) & mask) s += p[j][i];
        dp[mask] += d * prob * s;
    }
    v[mask] = true;
    return dp[mask];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> p[i][j];
    }
    for (int i = 0; i < n; ++i) cout << fixed << setprecision(20) << dfs(1 << i) << ' ';
    cout << endl;
    return 0;
}