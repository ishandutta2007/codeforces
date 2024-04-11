#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct Fenwick {
    int _bit[4][10][11][maxn];
    inline int lowbit(int x) { return x & -x; }
    void init() {
        memset(_bit, 0, sizeof(_bit));
    }
    void add(int x, int ind, int id, int p, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) _bit[id][ind][p][i] += v;
    }
    int qry(int x, int ind, int id, int p) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += _bit[id][ind][p][i];
        return ret;
    }
} bit;

inline int id(char c) {
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'G') return 2;
    if (c == 'C') return 3;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    bit.init();
    // for (int i = 0; i < s.length(); ++i) bit.add(i + 1, (i + 1) % 10, id(s[i]), 1);
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j < s.length(); ++j) bit.add(j + 1, (j + 1) % i, id(s[j]), i, 1);
    }
    int q; cin >> q; while (q--) {
        int met; cin >> met;
        if (met == 1) {
            int x; char c; cin >> x >> c;
            for (int i = 1; i <= 10; ++i) {
                bit.add(x, x % i, id(s[x - 1]), i, -1);
                bit.add(x, x % i, id(c), i, 1);
            }
            s[x - 1] = c;
        } else {
            int l, r; string e; cin >> l >> r >> e;
            int ans = 0;
            for (int i = 0; i < e.length(); ++i) {
                ans += bit.qry(r, (l + i) % (int)e.length(), id(e[i]), e.length()) - bit.qry(l - 1, (l + i) % (int)e.length(), id(e[i]), e.length());
            }
            cout << ans << endl;
        }
    }
    return 0;
}