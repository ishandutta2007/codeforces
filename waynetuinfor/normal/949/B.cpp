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

void naive() {
    int n; cin >> n;
    vector<int> v = { 0 };
    for (int i = 2; i <= n; ++i) v.push_back(-1), v.push_back(i - 1);
    while (true) {
        int a = -1, b = -1;
        for (int i = v.size() - 1; i >= 0; --i) {
            if (v[i] >= 0) {
                for (int j = i - 1; j >= 0; --j) if (v[j] == -1) {
                    a = i; b = j;
                    break;
                }
                break;
            }
        }
        if (a == -1 || b == -1) break;
        vector<int> nv(v.size(), -1);
        for (int i = 0; i < v.size(); ++i) {
            if (i == a) continue;
            if (i == b) nv[i] = v[a];
            else nv[i] = v[i];
        }
        v = nv;
    }
    for (int i = 0; i < n; ++i) cout << v[i] + 1 << ' '; cout << endl;
    // for (int i = 0; i < n; ++i) cout << bitset<4>(v[i]) << ' '; cout << endl;
    // for (int i = 0; i < n; ++i) cout << bitset<4>(i) << ' '; cout << endl;
}

int main() {
    // naive();
    // return 0;
    long long n; int q; cin >> n >> q;
    while (q--) {
        long long x; cin >> x; --x;
        int step = 0;
        long long p = 0, now = 1, t = 0, kk = 2, f = (n + kk / 2) / kk;
        while (true) {
            if ((x - p) % kk == 0) {
                cout << now + (x - p) / kk << '\n';
                break;
            }
            int b = (n >> step) & 1;
            p += kk * (2 * b + 1) / 2;
            // if ((1ll << step) & n) p += kk * 3 / 2;
            // else p += kk / 2;
            ++step;
            kk <<= 1;
            now += f;
            f = (n + kk / 2) / kk;
        }
    }
    return 0;
}