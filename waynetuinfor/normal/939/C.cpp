#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
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
int a[maxn];
long long now[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int s, f; cin >> s >> f;
    for (int i = 1; i <= n; ++i) {
        int ns = s - (i - 1), nf = f - (i - 1);
        if (ns <= 0) ns += n;
        if (nf <= 0) nf += n;
        if (ns > nf) now[ns] += a[i], now[n + 1] -= a[i], now[1] += a[i], now[nf] -= a[i];
        else now[ns] += a[i], now[nf] -= a[i];
    }
    int bst = 0;
    for (int i = 1; i < maxn; ++i) {
        now[i] += now[i - 1];
        if (now[i] > now[bst]) bst = i;
    }
    if (bst > n) bst -= n;
    cout << bst << endl;
}