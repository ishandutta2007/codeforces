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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        string d = "ANTO";
        vector<int> p(4);
        iota(p.begin(), p.end(), 0);
        long long ans = -1;
        string res;
        vector<vector<int>> a(4);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                if (s[i] == d[j]) {
                    a[j].emplace_back(i);
                }
            }
        }
        do {
            string t;
            vector<int> b;
            for (int i = 0; i < 4; i++) {
                t += string(a[p[i]].size(), d[p[i]]);
                b.insert(b.end(), a[p[i]].begin(), a[p[i]].end());
            }
            long long sum = 0;
            fenwick<long long> ft(n);
            for (int i = 0; i < n; i++) {
                ft.add(i, 1);
            }
            for (int i = 0; i < n; i++) {
                ft.add(b[i], -1);
                sum += ft.get(0, b[i]);
            }
            if (ans < sum) {
                res = t;
                ans = sum;
            }
        } while (next_permutation(p.begin(), p.end()));
        cout << res << '\n';
    }
    return 0;
}