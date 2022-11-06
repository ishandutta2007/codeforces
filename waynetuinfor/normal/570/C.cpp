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

const int maxn = 3e5 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    set<pair<int, int>> st;
    int ans = 0;
    for (size_t i = 0; i < s.size(); ) {
        if (s[i] != '.') {
            ++i;
            continue;
        }
        size_t j = i;
        while (j < s.size() && s[j] == '.') ++j;
        st.insert(make_pair(i, j - 1));
        ans += j - i - 1;
        i = j;
    }
    while (m--) {
        int p; char c; cin >> p >> c; --p;
        if ((s[p] == '.') == (c == '.')) {
            cout << ans << endl;
            continue;
        }
        s[p] = c;
        if (c == '.') {
            if (st.size() == 0) {
                st.insert(make_pair(p, p));
                cout << ans << endl;
                continue;
            }
            auto it = st.lower_bound(make_pair(p, -1));
            // if (it != st.end()) debug() << *it;
            auto pit = prev(it);
            if (it != st.end() && it != st.begin()) {
                if (it->first == p + 1 && pit->second == p - 1) {
                    ans -= it->second - it->first;
                    ans -= pit->second - pit->first;
                    ans += max(0, it->second - pit->first);
                    st.erase(*it); st.erase(*pit);
                    st.insert(make_pair(pit->first, it->second)); 
                } else if (it->first == p + 1) {
                    ++ans;
                    st.erase(*it);
                    st.insert(make_pair(p, it->second));
                } else if (pit->second == p - 1) {
                    ++ans;
                    st.erase(*pit);
                    st.insert(make_pair(pit->first, p));
                } else st.insert(make_pair(p, p));
            } else if (it == st.end() && it != st.begin()) {
                if (pit->second == p - 1) {
                    ++ans;
                    st.erase(*it);
                    st.insert(make_pair(pit->first, p));
                } else st.insert(make_pair(p, p));
            } else if (it != st.end() && it == st.begin()) {
                if (it->first == p + 1) {
                    ++ans;
                    st.erase(*it);
                    st.insert(make_pair(p, it->second));
                
                } else st.insert(make_pair(p, p));
            } else st.insert(make_pair(p, p));
            cout << ans << endl;
        } else {
            auto it = --st.upper_bound(make_pair(p, maxn));
            // debug() << *it;
            int now = ans;
            if (it->first <= p && it->second >= p) {
                ans -= it->second - it->first;
                ans += max(0, p - it->first - 1);
                ans += max(0, it->second - p - 1);
                if (p > it->first) st.insert(make_pair(it->first, p - 1));
                if (p < it->second) st.insert(make_pair(p + 1, it->second));
                st.erase(*it);
            }
            cout << ans << endl;
        }
        // debug() << var(st);
    }
    return 0;
}