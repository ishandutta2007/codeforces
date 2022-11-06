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

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn];

inline int padd(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline int psub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
inline int pmul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1, a = pmul(a, a)) if (n & 1) ret = pmul(ret, a);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);    
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (a[i] == 0) ++cnt;
    for (int i = 0; i < n; ++i) if (b[i] == 0) ++cnt;
    int q = fpow(m, cnt), p = 0, prv = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) --cnt;
        if (b[i] == 0) --cnt;
        if (a[i] > 0 && b[i] > 0) {
            if (a[i] > b[i]) {
                p = padd(p, pmul(prv, fpow(m, cnt)));
                break;
            }
            if (a[i] < b[i]) break;
            continue;
        }
        if (a[i] == 0 && b[i] == 0) p = padd(p, pmul(pmul(prv, pmul(pmul(m, m - 1), fpow(2, mod - 2))), fpow(m, cnt))), prv = pmul(prv, m);
        else if (a[i] == 0) p = padd(p, pmul(pmul(prv, m - b[i]), fpow(m, cnt)));
        else p = padd(p, pmul(pmul(prv, a[i] - 1), fpow(m, cnt)));
    }
    p = pmul(p, fpow(q, mod - 2));
    cout << p << endl;
    return 0;
}