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

long long t[20];

int main() {
    t[0] = 1;
    for (int i = 1; i < 20; ++i) t[i] = t[i - 1] * 10;
    long long a; int k; cin >> a >> k;
    vector<int> dig;
    long long b = a;
    while (b) dig.push_back(b % 10), b /= 10;
    int sz = dig.size() - 1;
    while (k > 0 && sz >= 0) {
        debug() << var(sz);
        vector<pair<int, int>> dig;
        long long b = a;
        int now = 0;
        vector<int> dd;
        while (b) dd.push_back(b % 10), dig.emplace_back(b % 10, now), b /= 10, ++now;
        sort(dig.begin(), dig.end()); reverse(dig.begin(), dig.end());
        debug() << range(dd.begin(), dd.end());
        for (int i = 0; i < dig.size(); ++i) if (dig[i].second < sz && dig[i].first > dd[sz]) {
            if (sz - dig[i].second <= k) {
                k -= sz - dig[i].second;
                debug() << var(dig[i].second);
                debug() << var(dd[sz]);
                debug() << var(dig[i].first);
                debug() << var(t[sz]) << var(t[dig[i].second]);
                for (int j = dig[i].second; j < sz; ++j) swap(dd[j], dd[j + 1]);
                debug() << range(dd.begin(), dd.end());
                a = 0;
                for (int j = 0; j < dd.size(); ++j) a += t[j] * dd[j];
                break;
            }
        }
        debug() << var(a);
        --sz;
    } 
    cout << a << endl;
}