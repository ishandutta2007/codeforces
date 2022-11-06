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

int main() {
    int n, k; cin >> n >> k;
    if (n < k) return cout << "-1" << endl, 0;
    if (n > 1 && k == 1) return cout << "-1" << endl, 0;
    if (n == 1 && k == 1) return cout << "a" << endl, 0;
    string ans = "";
    char now = 'a';
    vector<char> cand;
    for (char i = 'c'; i < 'a' + k; ++i) cand.push_back(i);
    reverse(cand.begin(), cand.end());
    for (int i = 0; i < n; ++i) {
        int rem = n - i;
        if (rem == cand.size()) ans += cand.back(), cand.pop_back();
        else ans += now, now = (now == 'a' ? 'b' : 'a');
    }
    cout << ans << endl;
    return 0;
}