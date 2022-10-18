#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
struct fenwick {
    int n;
    vector<T> node;

    fenwick(int _n) : n(_n) {
        node.resize(n);
    }

    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {  // [0, x]
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }

    T get(int x, int y) {  // [x, y]
        return (get(y) - (x ? get(x - 1) : 0));
    }

    int lower_bound(T v) {
        int x = 0;
        int h = 1;
        while (n >= (h << 1)) {
            h <<= 1;
        }
        for (int k = h; k > 0; k >>= 1) {
            if (x + k <= n && node[x + k - 1] < v) {
                v -= node[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int h, w;
        cin >> h >> w;
        string s;
        cin >> s;
        vector<int> ans(h * w);
        {
            vector<int> t(w);
            for (int i = 0; i < h * w; i++) {
                if (s[i] == '1' && t[i % w] == 0) {
                    t[i % w] = 1;
                    ans[i]++;
                }
            }
            for (int i = 1; i < h * w; i++) {
                ans[i] += ans[i - 1];
            }
        }
        {
            vector<int> t(h * w);
            string x = string(w - 1, '0') + s;
            vector<int> pref((int) x.size() + 1);
            for (int i = 0; i < (int) x.size(); i++) {
                pref[i + 1] = pref[i] + (x[i] == '1');
            }
            for (int i = 0; i < h * w; i++) {
                // x[i : i + w - 1]
                t[i] = (pref[i] != pref[i + w]);
            }
            for (int i = 0; i < h * w; i++) {
                if (i >= w) {
                    t[i] += t[i - w];
                }
                ans[i] += t[i];
            }
        }
        for (int i = 0; i < h * w; i++) {
            cout << ans[i] << " \n"[i == h * w - 1];
        }
    }
    return 0;
}