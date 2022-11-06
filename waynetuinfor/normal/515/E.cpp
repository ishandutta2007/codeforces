#include <bits/stdc++.h>
#define int long long
#define getchar gtx
using namespace std;

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

const int maxn = 1e5 + 10, inf = 1e18 + 1;
int d[maxn << 1], h[maxn << 1];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    vector<pair<int, int>> vec;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        vec.assign(4, make_pair(-inf, -inf));
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    vector<pair<int, int>> merge(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
        vector<pair<int, int>> ret; ret.assign(4, make_pair(-inf, -inf));
        vector<pair<int, int>> que = { a[0], a[1], b[0], b[1] };
        for (auto i : que) {
            if (i > ret[0]) ret[1] = ret[0], ret[0] = i;
            else if (i > ret[1]) ret[1] = i;
        }
        que = { a[2], a[3], b[2], b[3] };
        for (auto i : que) {
            if (i > ret[2]) ret[3] = ret[2], ret[2] = i;
            else if (i > ret[3]) ret[3] = i;
        }
        return ret;
    }
    void pull() {
        vec = merge(lc->vec, rc->vec);
    }
    void modify(int L, int R, int x, pair<int, int> v) {
        if (L == R) {
            vec[0] = make_pair(v.first, x);
            vec[2] = make_pair(v.second, x);
            return;
        }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    vector<pair<int, int>> query(int L, int R, int l, int r) {
        if (L > r || l > R) return vector<pair<int, int>>(4, make_pair(-inf, -inf));
        if (L >= l && R <= r) return vec;
        return merge(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st;

int32_t main() {
    int n, m; rit(n, m);
    for (int i = 1; i <= n; ++i) rit(d[i]);
    for (int i = 1; i <= n; ++i) rit(h[i]);
    for (int i = 1; i <= n; ++i) d[i + n] = d[i], h[i + n] = h[i];
    st = new SegmentTree(1, n << 1);
    int cur = 0;
    for (int i = 1; i <= n << 1; ++i) {
        int x = 2 * h[i] + cur;
        int y = 2 * h[i] - cur;
        st->modify(1, n << 1, i, make_pair(x, y));
        cur += d[i];
    }
    while (m--) {
        int a, b; rit(a, b);
        vector<pair<int, int>> ans;
        if (a > b) ans = st->query(1, n << 1, b + 1, a - 1);
        else ans = st->query(1, n << 1, b + 1, a + n - 1);
        int sum = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 2; j < 4; ++j) if (ans[i].second != ans[j].second) sum = max(sum, ans[i].first + ans[j].first);
        }
        printf("%I64d\n", sum);
    }
    return 0;
}