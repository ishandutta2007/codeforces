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

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) {
        if (a[0] == 0) cout << "YES\n0" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    if (a[n - 1] != 0) return cout << "NO" << endl, 0;
    if (a[n - 2] == 1) {
        cout << "YES" << endl;
        cout << a[0];
        for (int i = 1; i < n; ++i) cout << "->" << a[i];
        cout << endl;
        return 0;
    } 
    int p = n - 2, stop = -1, now = a[p];
    while (p > 0) {
        if (a[p - 1] == 1 && now == 0) {
            --p;
            continue;
        }
        stop = p - 1;
        break;
    }
    if (stop == -1) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    if (stop != 0) cout << a[0] << "->";
    for (int i = 1; i < stop; ++i) cout << a[i] << "->";
    cout << "(" << a[stop] << "->(";
    int b = 2;
    for (int i = stop + 1; i < n - 2; ++i) cout << a[i] << "->(", ++b;
    cout << a[n - 2];
    while (b--) cout << ')';
    cout << "->" << a[n - 1] << endl;
    return 0;
}