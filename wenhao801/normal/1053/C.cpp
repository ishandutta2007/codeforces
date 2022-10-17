#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define ll long long
#define lll __int128

const int MAXN = 200200, mod = 1e9 + 7;
int n, q, a[MAXN], w[MAXN];
struct BIT {
    lll t[MAXN];
    inline int lowbit (int x) { return x & -x; }
    inline lll sum (int x) { lll ret = 0; while (x) ret += t[x], x -= lowbit(x); return ret; }
    inline void add (int x, lll k) { while (x <= n) t[x] += k, x += lowbit(x); }
    inline lll query (int l, int r) { if (l > r) return 0; return sum(r) - sum(l - 1); }
} t_aw, t_w, t_iw;

void out (lll x) {
    if (x >= 10) out(x / 10);
    putchar(x % 10 + '0');
}
lll calc (ll pos, int l, int r) {
    // printf("calc %lld %d %d\n", pos, l, r);
    int L = l, R = r, res = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (a[mid] <= pos + mid - l) res = mid, L = mid + 1;
        else R = mid -1;
    }
    // cout << res << endl;
    // out(t_w.query(l, res) * (pos - l) + t_iw.query(l, res) - t_aw.query(l, res) // );puts("");
    //       +t_aw.query(res + 1, r) - t_w.query(res + 1, r) * (pos - l) - t_iw.query(res + 1, r)); puts("");
    return (t_w.query(l, res) * (pos - l) + t_iw.query(l, res) - t_aw.query(l, res) 
          +t_aw.query(res + 1, r) - t_w.query(res + 1, r) * (pos - l) - t_iw.query(res + 1, r));
}

int main () {
    n = read(), q = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i <= n; i++) w[i] = read(), t_aw.add(i, 1ll * a[i] * w[i]), t_w.add(i, w[i]), t_iw.add(i, 1ll * i * w[i]);
    while (q--) {
        int x = read();
        if (x < 0) { i = -x;; int nw = read(); t_aw.add(i, 1ll * a[i] * (nw - w[i])), t_w.add(i, nw - w[i]), t_iw.add(i, 1ll * i * (nw - w[i])); w[i] = nw; }
        else {
            int l = x, r = read();
            int L = a[l], R = a[r]; lll ans = -1;
            while (L <= R) {
                int mid = (L + R) >> 1;
                lll bibo = calc(mid, l, r), babo = calc(mid + 1, l, r);
                if (bibo > babo) ans = babo, L = mid + 1;
                else if (bibo < babo) ans = bibo, R = mid - 1;
                else { ans = bibo; break; }
            }
            assert(ans != -1); out(ans % mod); putchar('\n');
        }
    }
    return 0;
}