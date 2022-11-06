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

const int maxn = 26;

struct djset {
    int p[maxn];
    void init() { iota(p, p + maxn, 0); }
    int find(int n) { return p[n] == n ? n : p[n] = find(p[n]); }
    void merge(int n, int m) { p[find(m)] = find(n); }
} djs;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string a, b; cin >> a >> b;
    djs.init();
    vector<pair<char, char>> ans;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) continue;
        if (djs.find(a[i] - 'a') == djs.find(b[i] - 'a')) continue;
        ans.emplace_back(a[i], b[i]);
        djs.merge(a[i] - 'a', b[i] - 'a');
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i.first << ' ' << i.second << endl;
    return 0;
}