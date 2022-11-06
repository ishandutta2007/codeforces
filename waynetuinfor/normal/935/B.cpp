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

int main() {
    int n; cin >> n;
    int x = 0, y = 0, ans = 0;
    int c = -1, b = 0;
    --n;
    char cc; cin >> cc;
    if (cc == 'U') ++y; else ++x;
    if (y > x) b = 1; else b = 0;
    while (n--) {
        char cc; cin >> cc;
        if (cc == 'U') ++y;
        else ++x;
        int tside = (y > x);
        if (tside + c == 1 && b == -1) ++ans;
        if (x == y) c = b, b = -1;
        else if (tside) c = b, b = 1;
        else if (y < x) c = b, b = 0;
    }
    cout << ans << endl;
}