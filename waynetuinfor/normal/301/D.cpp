#include <bits/stdc++.h>
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

const int maxn = 2e5 + 10;
int p[maxn], mindiv[maxn], pos[maxn];
long long ans[maxn];
vector<int> divs[maxn], ds[maxn];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divs[j].push_back(i);
        }
    }
}

struct fenwick {
    long long data[maxn];
    void init() { memset(data, 0, sizeof(data)); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) data[p] += v; }
    long long qry(int p, long long c = 0) { for (; p; p -= p & -p) c += data[p]; return c; }
} bit;

struct query {
    int l, r, i;
    bool operator<(const query &q) const { return r < q.r; }
};

int main() {
    int n, m; rit(n, m);
    for (int i = 1; i <= n; ++i) rit(p[i]), pos[p[i]] = i;
    init(n);
    for (int i = 1; i <= n; ++i) {
        for (int j : divs[i]) ds[max(pos[i], pos[j])].push_back(min(pos[i], pos[j]));
    }
    vector<query> qry;
    for (int i = 0; i < m; ++i) {
        int l, r; rit(l, r);
        qry.push_back({ l, r, i });
    }
    sort(qry.begin(), qry.end());
    int r = 1;
    size_t ptr = 0;
    bit.init();
    for (auto q : qry) {
        while (r <= q.r) {
            for (int p : ds[r]) bit.add(p, 1);
            ++r;
        }
        ans[q.i] = bit.qry(maxn - 1) - bit.qry(q.l - 1);
    }
    for (int i = 0; i < m; ++i) printf("%I64d\n", ans[i]);
    return 0;
}