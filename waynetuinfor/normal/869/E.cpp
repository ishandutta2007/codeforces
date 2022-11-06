#include <bits/stdc++.h>
using namespace std;

const int maxn = 2500 + 10;

struct square {
    int x1, y1, x2, y2;
    square(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d) {}
    square() {}
    bool operator<(const square& rhs) const {
        return x1 == rhs.x1 ? y1 == rhs.y1 ? x2 == rhs.x2 ? y2 < rhs.y2 : x2 < rhs.x2 : y1 < rhs.y1 : x1 < rhs.x1;
    }
};

map<square, long long> hs;

struct fenwick {
    long long data[maxn][maxn];
    void init() {
        memset(data, 0, sizeof(data));
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int y, long long v) {
        for (int i = x; i < maxn; i += lowbit(i)) {
            for (int j = y; j < maxn; j += lowbit(j)) data[i][j] ^= v;
        }
    } 
    long long qry(int x, int y) {
        long long ret = 0;
        for (int i = x; i; i -= lowbit(i)) {
            for (int j = y; j; j -= lowbit(j)) ret ^= data[i][j];
        }
        return ret;
    }
} bit;

int main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    bit.init();
    while (q--) {
        int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
        if (t == 1) {
            long long k = ((long long)rand() << 45) + ((long long)rand() << 30) + ((long long)rand() << 15) + (long long)rand();
            bit.add(x1, y1, k); bit.add(x1, y2 + 1, k); bit.add(x2 + 1, y1, k); bit.add(x2 + 1, y2 + 1, k);
            hs[square(x1, y1, x2, y2)] = k;
        }
        if (t == 2) {
            long long k = hs[square(x1, y1, x2, y2)];
            bit.add(x1, y1, k); bit.add(x1, y2 + 1, k); bit.add(x2 + 1, y1, k); bit.add(x2 + 1, y2 + 1, k);
        }
        if (t == 3) {
            if (bit.qry(x1, y1) == bit.qry(x2, y2)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}