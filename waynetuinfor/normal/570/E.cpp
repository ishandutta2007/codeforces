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

const int maxn = 500 + 10, mod = 1e9 + 7;

int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
int mul(int a, int b) { return a * 1ll * b % mod; }

char c[maxn][maxn];
int dp[maxn][maxn][2], n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> c[i][j];
    }
    if (c[1][1] != c[n][m]) return cout << "0" << endl, 0;
    int tar = (n + m - 1) / 2;
    vector<pair<int, int>> cand1, cand2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i + j - 1 == tar) cand1.emplace_back(i, j);
            if ((n - i) + (m - j) + 1 == tar) cand2.emplace_back(i, j);
        }
    } 
    dp[1][n][1] = 1;
    for (int s = 2; s <= tar; ++s) {
        int cur = s & 1;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                dp[a][b][cur] = 0;
                int ax = a, ay = s - ax + 1, bx = b, by = m - (s - (n - bx)) + 1;
                if (c[ax][ay] != c[bx][by]) continue;
                if (ax - 1 >= 1 && bx + 1 <= n) dp[a][b][cur] = add(dp[a][b][cur], dp[ax - 1][bx + 1][cur ^ 1]);
                if (ax - 1 >= 1 && by + 1 <= m) dp[a][b][cur] = add(dp[a][b][cur], dp[ax - 1][bx][cur ^ 1]);
                if (ay - 1 >= 1 && bx + 1 <= n) dp[a][b][cur] = add(dp[a][b][cur], dp[ax][bx + 1][cur ^ 1]);
                if (ay - 1 >= 1 && by + 1 <= m) dp[a][b][cur] = add(dp[a][b][cur], dp[ax][bx][cur ^ 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < cand1.size(); ++i) {
        for (int j = 0; j < cand2.size(); ++j) {
            int a, b; tie(a, b) = cand1[i];
            int c, d; tie(c, d) = cand2[j];
            if (c < a || d < b) continue;
            if ((n + m - 1) % 2 == 0 && c - a + d - b == 1) ans = add(ans, dp[a][c][tar & 1]);
            if ((n + m - 1) % 2 == 1 && c - a + d - b == 2) ans = add(ans, mul(dp[a][c][tar & 1], (b + 2 == d || a + 2 == c ? 1 : 2)));
        }
    }
    cout << ans << endl;
    return 0;
}