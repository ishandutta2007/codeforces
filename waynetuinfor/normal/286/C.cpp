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

const int maxn = 1e6 + 10;
int p[maxn], v[maxn], ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    int t; cin >> t;
    while (t--) {
        int q; cin >> q;
        v[q] = true;
    }
    stack<int> stk;
    for (int i = n; i > 0; --i) {
        if (v[i]) {
            ans[i] = -p[i];
            stk.push(-p[i]);
            continue;
        }
        if (stk.size() && stk.top() == -p[i]) ans[i] = p[i], stk.pop();
        else ans[i] = -p[i], stk.push(-p[i]);
    }
    if (stk.size() > 0) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}