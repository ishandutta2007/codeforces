#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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

const int maxn = 2e5 + 10;
int c[2];
set<int> st[2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) ++c[s[i] - '0'];
    if (c[1] >= c[0]) return cout << "-1" << endl, 0;
    int k = c[0] - c[1];
    for (int i = 0; i < n; ++i) st[s[i] - '0'].insert(i);
    vector<vector<int>> v;
    for (int i = 0; i < k; ++i) {
        if (st[0].size() == 0) return cout << "-1" << endl, 0;
        int now = *st[0].begin();
        st[0].erase(now);
        int z = 0;
        vector<int> cur; cur.push_back(now);
        while (true) {
            if (st[z ^ 1].size() == 0) break;
            auto it = st[z ^ 1].upper_bound(now);
            if (it == st[z ^ 1].end()) break;
            now = *it;
            cur.push_back(now);
            st[z ^ 1].erase(now);
            z ^= 1;
        }
        if (cur.size() == 0) return cout << "-1" << endl, 0;
        if (s[cur.back()] == '1') st[1].insert(cur.back()), cur.pop_back();
        v.push_back(cur);
    }
    if (st[0].size() || st[1].size()) return cout << "-1" << endl, 0;
    cout << k << endl;
    for (auto i : v) {
        cout << i.size() << ' ';
        for (int j : i) cout << j + 1 << ' ';
        cout << endl;
    }
    return 0;
}