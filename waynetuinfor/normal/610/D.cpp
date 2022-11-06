#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int y[2][maxn], ynow[maxn], ypv[maxn];

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

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[1000000];
    static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    int sum;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr; sum = 0;
        if (L == R) return;
        lc = new (ptr++) SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void modify(int L, int R, int x, int v) {
        if (L == R) {
            sum = v;
            return;
        }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
} *st, SegmentTree::mem[1000000], *SegmentTree::ptr = mem;

int main() {
    int n; rit(n);
    vector<pair<int, int>> ys;
    vector<pair<int, pair<int, int>>> xs;
    vector<int> v, vx;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; rit(x1, y1, x2, y2);
        if (x1 > x2) swap(x1, x2); if (y1 > y2) swap(y1, y2);
        y[0][i] = y1; y[1][i] = y2;
        v.push_back(y1); v.push_back(y2);
        if (x1 == x2) ys.emplace_back(x1, i);
        else xs.emplace_back(x1, make_pair(y1, 1)), xs.emplace_back(x2 + 1, make_pair(y1, 0));
    }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    st = new (SegmentTree::ptr++) SegmentTree(0, v.size() - 1);
    sort(ys.begin(), ys.end()); sort(xs.begin(), xs.end());
    size_t ptr = 0;
    for (auto x : xs) {
        while (ptr < ys.size() && ys[ptr].first < x.first) {
            int px = ys[ptr].first;
            vector<pair<int, int>> nys;
            while (ptr < ys.size() && ys[ptr].first == px) {
                nys.emplace_back(y[0][ys[ptr].second], 1);
                nys.emplace_back(y[1][ys[ptr].second] + 1, -1);
                ++ptr;
            }
            sort(nys.begin(), nys.end());
            int now = 0, py = -1;
            for (auto ny : nys) {
                if (ny.second == 1) {
                    if (now == 0) py = ny.first;
                    ++now;
                } else {
                    --now;
                    if (now == 0) {
                        int l = lower_bound(v.begin(), v.end(), py) - v.begin();
                        int r = lower_bound(v.begin(), v.end(), ny.first - 1) - v.begin();
                        ans += ny.first - py - st->query(0, v.size() - 1, l, r);
                    }
                }
            }
        }
        int pos = lower_bound(v.begin(), v.end(), x.second.first) - v.begin();
        if (x.second.second == 1) {
            if (ynow[pos] == 0) ypv[pos] = x.first, st->modify(0, v.size() - 1, pos, 1);
            ++ynow[pos];
        }
        else {
            --ynow[pos];
            if (ynow[pos] == 0) ans += x.first - ypv[pos], st->modify(0, v.size() - 1, pos, 0);
        }
    }
    while (ptr < ys.size()) {
        int px = ys[ptr].first;
        vector<pair<int, int>> nys;
        while (ptr < ys.size() && ys[ptr].first == px) {
            nys.emplace_back(y[0][ys[ptr].second], 1);
            nys.emplace_back(y[1][ys[ptr].second] + 1, -1);
            ++ptr;
        }
        sort(nys.begin(), nys.end());
        int now = 0, py = -1;
        for (auto ny : nys) {
            if (ny.second == 1) {
                if (now == 0) py = ny.first;
                ++now;
            } else {
                --now;
                if (now == 0) ans += ny.first - py;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}