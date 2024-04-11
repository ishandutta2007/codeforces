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
        vector<int> a(1 << n, 0);
        iota(a.begin(), a.end(), 0);
        auto Ask = [&](int x, int y) {
            cout << "? " << x + 1 << " " << y + 1 << endl;
            cin >> x;
            return x;
        };
        while (a.size() > 1) {
            if (a.size() == 2) {
                if (Ask(a[0], a[1]) == 1) {
                    a.pop_back();
                } else {
                    a.erase(a.begin());
                }
                break;
            }
            vector<int> b;
            for (int i = 0; i < (int) a.size(); i += 4) {
                int w = a[i + 0];
                int x = a[i + 1];
                int y = a[i + 2];
                int z = a[i + 3];
                int t = Ask(w, y);
                if (t == 0) {
                    int s = Ask(x, z);
                    if (s == 1) {
                        b.emplace_back(x);
                    } else {
                        b.emplace_back(z);
                    }
                } else if (t == 1) {
                    int s = Ask(w, z);
                    if (s == 1) {
                        b.emplace_back(w);
                    } else {
                        b.emplace_back(z);
                    }
                } else {
                    int s = Ask(x, y);
                    if (s == 1) {
                        b.emplace_back(x);
                    } else {
                        b.emplace_back(y);
                    }
                }
            }
            swap(a, b);
        }
        cout << "! " << a[0] + 1 << endl;
    }
    return 0;
}