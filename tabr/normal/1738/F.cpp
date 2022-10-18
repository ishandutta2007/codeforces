#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p = vector<int>(n);
        iota(p.begin(), p.end(), 0);
        sz = vector<int>(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }

    inline int size(int x) {
        return sz[get(x)];
    }

    inline bool root(int x) {
        return (x == get(x));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        dsu uf(n);
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return d[i] > d[j];
        });
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[order[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (d[order[i]] == 0 || uf.size(order[i]) > 1) {
                continue;
            }
            for (int j = 0; j < d[order[i]]; j++) {
                cout << "? " << order[i] + 1 << endl;
                int x;
                cin >> x;
                assert(x != -1);
                x--;
                x = uf.get(x);
                if (pos[x] < pos[order[i]]) {
                    uf.unite(order[i], x);
                    break;
                } else {
                    uf.unite(x, order[i]);
                }
            }
        }
        cout << "!";
        for (int i = 0; i < n; i++) {
            cout << " " << uf.get(i) + 1;
        }
        cout << endl;
    }
    return 0;
}