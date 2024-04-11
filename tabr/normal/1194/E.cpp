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
    int n;
    cin >> n;
    vector<tuple<int, int, int>> xs;
    vector<vector<int>> add(10001), del(10002);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 5000;
        y1 += 5000;
        x2 += 5000;
        y2 += 5000;
        if (x1 == x2) {
            if (y1 > y2) {
                swap(y1, y2);
            }
            xs.emplace_back(x1, y1, y2);
        } else {
            if (x1 > x2) {
                swap(x1, x2);
            }
            add[x1].emplace_back(y1);
            del[x2 + 1].emplace_back(y1);
        }
    }
    sort(xs.begin(), xs.end());
    long long ans = 0;
    for (int i = 0; i < (int)xs.size(); i++) {
        fenwick<long long> ft(10001);
        int l1 = get<1>(xs[i]);
        int l2 = get<2>(xs[i]);
        for (int j = i + 1, k = 0; j < (int)xs.size(); j++) {
            int x = get<0>(xs[j]);
            int r1 = get<1>(xs[j]);
            int r2 = get<2>(xs[j]);
            while (k <= x) {
                for (int y : del[k]) {
                    ft.add(y, -ft.get(y, y));
                }
                for (int y : add[k]) {
                    if (k <= get<0>(xs[i])) {
                        ft.add(y, 1);
                    }
                }
                k++;
            }
            if (max(l1, r1) <= min(l2, r2)) {
                long long t = ft.get(max(l1, r1), min(l2, r2));
                ans += t * (t - 1) / 2;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}