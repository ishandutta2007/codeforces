#include <bits/stdc++.h>
#define int long long
#define getchar gtx
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int n, m, a[maxn], b[maxn];
pair<pair<int, int>, int> f[maxn];
pair<int, int> mos[maxn];

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
    static SegmentTree mem[2000000];
    static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    int id, tag;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        tag = n; id = n;
        lc = rc = nullptr;
        if (L == R) return;
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
        pull();
    }
    int cmp(int a, int b) {
        return f[a].first.first < f[b].first.first ? a : b;
    }
    void pull() {
        id = cmp(lc->id, rc->id);
    }
    void push() {
        if (tag == n || lc == nullptr) return;
        lc->tag = cmp(lc->tag, tag); lc->id = cmp(lc->id, tag);
        rc->tag = cmp(rc->tag, tag); rc->id = cmp(rc->id, tag);
        tag = n;
    }
    void modify(int L, int R, int l, int r, int v) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            tag = cmp(tag, v); id = cmp(id, v);
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return n;
        if (L >= l && R <= r) return id;
        return cmp(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
} *st, SegmentTree::mem[2000000], *SegmentTree::ptr = mem;

int32_t main() {
    rit(n, m);
    vector<int> v, vec;
    for (int i = 0; i < n; ++i) rit(f[i].first.first, f[i].first.second), f[i].second = i, v.push_back(f[i].first.first);
    f[n].first.first = inf;
    for (int i = 0; i < m; ++i) rit(mos[i].first, mos[i].second), v.push_back(mos[i].first);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < n; ++i) vec.push_back(i);
    sort(vec.begin(), vec.end(), [&](const int& i, const int& j) { return f[i].first.first < f[j].first.first; });
    st = new (SegmentTree::ptr++) SegmentTree(0, v.size() - 1);
    for (int i = 0; i < n; ++i) {
        int l = lower_bound(v.begin(), v.end(), f[vec[i]].first.first) - v.begin();
        int r = lower_bound(v.begin(), v.end(), f[vec[i]].first.first + f[vec[i]].first.second) - v.begin();
        if (v[r] > f[vec[i]].first.first + f[vec[i]].first.second) --r;
        st->modify(0, v.size() - 1, l, r, vec[i]);
    }
    multiset<pair<int, int>> s;
    for (int i = 0; i < n; ++i) b[i] = f[i].first.second;
    for (int i = 0; i < m; ++i) {
        int pos = lower_bound(v.begin(), v.end(), mos[i].first) - v.begin();
        int id = st->query(0, v.size() - 1, pos, pos);
        if (id == n) {
            s.insert(mos[i]);
            continue;
        }
        ++a[id]; b[id] += mos[i].second;
        int l = lower_bound(v.begin(), v.end(), f[id].first.first) - v.begin();
        int r = lower_bound(v.begin(), v.end(), f[id].first.first + b[id]) - v.begin();
        if (v[r] > f[id].first.first + b[id]) --r;
        st->modify(0, v.size() - 1, l, r, id);
        while (s.size()) {
            auto it = s.lower_bound(make_pair(f[id].first.first, -1));
            int pos = lower_bound(v.begin(), v.end(), it->first) - v.begin();
            if (st->query(0, v.size() - 1, pos, pos) != id) break;
            ++a[id]; b[id] += it->second;
            int l = lower_bound(v.begin(), v.end(), f[id].first.first) - v.begin();
            int r = lower_bound(v.begin(), v.end(), f[id].first.first + b[id]) - v.begin();
            if (v[r] > f[id].first.first + b[id]) --r;
            st->modify(0, v.size() - 1, l, r, id);
            s.erase(it);
        }
    }
    for (int i = 0; i < n; ++i) printf("%I64d %I64d\n", a[i], b[i]);
    return 0;
}