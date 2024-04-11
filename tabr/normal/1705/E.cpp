#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

// segment container
// each operation is log order
// - all arguments should strictly between lower and upper
// - add or remove segment [l, r)
// - get left or right segment of x
// - check if x is on a segment
struct segment_container {
    set<pair<long long, long long>> st;

    segment_container() {
        st.emplace((long long) -9e18, (long long) -9e18);
        st.emplace((long long) 9e18, (long long) 9e18);
    }

    // return first segment such that x < r
    set<pair<long long, long long>>::iterator right(long long x) {
        auto res = prev(st.lower_bound(make_pair(x, x)));
        if (x >= res->second) {
            res = next(res);
        }
        return res;
    }

    // return last segment such that x >= l
    set<pair<long long, long long>>::iterator left(long long x) {
        auto res = st.lower_bound(make_pair(x, x));
        if (x < res->first) {
            res = prev(res);
        }
        return res;
    }

    void add(long long l, long long r) {
        while (true) {
            auto iter = right(l - 1);
            if (iter->first <= r && l <= iter->second) {
                l = min(l, iter->first);
                r = max(r, iter->second);
                st.erase(iter);
            } else {
                break;
            }
        }
        st.emplace(l, r);
    }

    void remove(long long l, long long r) {
        while (true) {
            auto iter = right(l);
            if (iter->first < r && l < iter->second) {
                auto t = *iter;
                st.erase(iter);
                if (t.first < l) {
                    add(t.first, l);
                }
                if (r < t.second) {
                    add(r, t.second);
                }
            } else {
                break;
            }
        }
    }

    bool on(int x) {
        if (right(x) == left(x)) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int m = (int) 2e5 + 50;
    int n, q;
    cin >> n >> q;
    vector<int> c(m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i]]++;
    }
    for (int i = 0; i < m - 1; i++) {
        c[i + 1] += c[i] / 2;
        c[i] %= 2;
    }
    segment_container sc;
    auto Remove = [&](int x) {
        if (sc.on(x)) {
            sc.remove(x, x + 1);
        } else {
            int y = (int) sc.right(x)->first;
            sc.add(x, y);
            sc.remove(y, y + 1);
        }
    };
    auto Add = [&](int x) {
        if (!sc.on(x)) {
            sc.add(x, x + 1);
        } else {
            int y = (int) sc.right(x)->second;
            sc.remove(x, y);
            sc.add(y, y + 1);
        }
    };
    for (int i = 0; i < m; i++) {
        if (c[i]) {
            Add(i);
        }
    }
    while (q--) {
        int k, l;
        cin >> k >> l;
        k--;
        Remove(a[k]);
        a[k] = l;
        Add(a[k]);
        debug(sc.st);
        cout << sc.left((int) 1e9)->second - 1 << '\n';
    }
    return 0;
}