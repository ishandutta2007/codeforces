#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 2500 + 10;
const int mod[] = { 479001599, 433494437, 1073807359 };
const int p[] = { 101, 233, 457};

// int _sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
// int _mul(int a, int b) { return a * 1ll * b % mod; }

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int _add(long long a, long long b, int k) {
    a %= mod[k]; b %= mod[k];
    if (a < 0) a += mod[k];
    if (b < 0) b += mod[k];
    return (a + b) % mod[k];
}
struct square {
    int x1, y1, x2, y2;
    square(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d) {}
    square() {}
    bool operator<(const square& rhs) const {
        return x1 == rhs.x1 ? y1 == rhs.y1 ? x2 == rhs.x2 ? y2 < rhs.y2 : x2 < rhs.x2 : y1 < rhs.y1 : x1 < rhs.x1;
    }
};

map<square, long long> hs;

// int fpow(int a, int n) {
    // int ret = 1;
    // for (; n; n >>= 1) {
        // if (n & 1) ret = _mul(ret, a);
        // a = _mul(a, a);
    // }
    // return ret;
// }

struct fenwick {
    int data[5][maxn][maxn];
    void init() {
        memset(data, 0, sizeof(data));
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int y, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) {
            for (int j = y; j < maxn; j += lowbit(j)) {
                for (int k = 0; k < 2; ++k) data[k][i][j] = _add(data[k][i][j], v, k);
            }
        }
    } 
    vector<int> qry(int x, int y) {
        vector<int> ret(2, 0);
        for (int i = x; i; i -= lowbit(i)) {
            for (int j = y; j; j -= lowbit(j)) {
                for (int k = 0; k < 2; ++k) ret[k] = _add(ret[k], data[k][i][j], k);
            }
        }
        return ret;
    }
} bit;

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; rit(n, m, q);
    bit.init();
    while (q--) {
        int t, x1, y1, x2, y2; rit(t, x1, y1, x2, y2);
        if (t == 1) {
            long long k = rand()*RAND_MAX+rand();
            long long kk = -k;
            // int kk = -k;
            bit.add(x1, y1, k); bit.add(x1, y2 + 1, kk); bit.add(x2 + 1, y1, kk); bit.add(x2 + 1, y2 + 1, k);
            hs[square(x1, y1, x2, y2)] = k;
        }
        if (t == 2) {
            long long k = hs[square(x1, y1, x2, y2)];
            long long kk = -k;
            // int kk = -k;
            // cout << "k = " << k << endl;
            bit.add(x1, y1, kk); bit.add(x1, y2 + 1, k); bit.add(x2 + 1, y1, k); bit.add(x2 + 1, y2 + 1, kk);
        }
        if (t == 3) {
            // cout << bit.qry(x1, y1) << ' ' << bit.qry(x2, y2) << endl;
            if (bit.qry(x1, y1) == bit.qry(x2, y2)) puts("Yes");
            else puts("No");
        }
        // for (int i = 1; i <= n; ++i) {
            // for (int j = 1; j <= m; ++j) cout << bit.data[i][j] << ' ';
            // cout << endl;
        // }
    }
    return 0;
}