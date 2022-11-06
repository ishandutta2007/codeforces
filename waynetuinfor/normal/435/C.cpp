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

const int maxn = 2000 + 10;
int a[maxn], y[maxn];
string ans[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], --a[i];
    int d = maxn, c = -maxn;
    y[0] = 0;
    c = d = 0;
    for (int i = 1; i <= n; ++i) {
        y[i] = y[i - 1];
        if (i & 1) y[i] += a[i];
        else y[i] -= a[i];
        d = min(d, y[i]);
        c = max(c, y[i]);
    }
    c -= d;
    debug() << var(c) << var(d);
    for (int i = 1; i <= n; ++i) {
        int curh = y[i] - d;
        if (i & 1) {
            for (int j = curh - a[i]; j <= curh; ++j) {
                for (int k = 0; k <= c; ++k) {
                    if (k == j) ans[k] += '/';
                    else ans[k] += ' ';
                }
            }
        } else {
            for (int j = curh + a[i]; j >= curh; --j) {
                for (int k = 0; k <= c; ++k) {
                    if (k == j) ans[k] += '\\';
                    else ans[k] += ' ';
                }
            }
        }
    }
    for (int j = c; j >= 0; --j) cout << ans[j] << endl;
}