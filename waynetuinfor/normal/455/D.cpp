#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 1e5 + 10, sq = 700;
int a[maxn], bid[maxn], lb[maxn], rb[maxn], cnt[maxn / sq + 10][maxn];
deque<int> deq[maxn / sq + 10];

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

int main() {
    int n; rit(n);
    for (int i = 1; i <= n; ++i) rit(a[i]);
    int block = 0;
    for (int i = 1; i <= n; ) {
        int j = 0; ++block; lb[i] = i;
        while (j < sq && i + j <= n) {
            deq[block].push_back(a[i + j]);
            bid[i + j] = block;
            lb[i + j] = i;
            ++j;
        }
        for (int k = i; k < i + j; ++k) rb[k] = i + j - 1;
        i += j;
    }
    for (int i = 1; i <= block; ++i) {
        for (int j : deq[i]) cnt[i][j]++;
    }
    int last = 0; 
    int q; rit(q); while (q--) {
        int t, l, r; rit(t, l, r);
        l = (l + last - 1) % n + 1; r = (r + last - 1) % n + 1;
        if (l > r) swap(l, r);
        if (t == 1) {
            if (bid[l] == bid[r]) {
                int tmp = deq[bid[l]][r - lb[r]];
                for (int i = r - lb[r]; i > l - lb[l]; --i) deq[bid[l]][i] = deq[bid[l]][i - 1];
                deq[bid[l]][l - lb[l]] = tmp;
                continue;
            }
            int pv = deq[bid[l]].back(); deq[bid[l]].pop_back(); --cnt[bid[l]][pv];
            for (int b = bid[l] + 1; b < bid[r]; ++b) {
                deq[b].push_front(pv);
                ++cnt[b][pv];
                pv = deq[b].back();
                deq[b].pop_back();
                --cnt[b][pv];
            }
            vector<int> tmpl(deq[bid[l]].begin(), deq[bid[l]].end()), tmpr(deq[bid[r]].begin(), deq[bid[r]].end());
            deq[bid[l]].clear(); deq[bid[r]].clear();
            int ptrl = 0, ptrr = tmpr.size() - 1;
            while (ptrl < l - lb[l]) deq[bid[l]].push_back(tmpl[ptrl++]);
            while (ptrr > r - lb[r]) deq[bid[r]].push_front(tmpr[ptrr--]);
            deq[bid[l]].push_back(tmpr[ptrr--]);
            while (ptrr >= 0) deq[bid[r]].push_front(tmpr[ptrr--]);
            deq[bid[r]].push_front(pv);
            --cnt[bid[r]][deq[bid[l]].back()]; ++cnt[bid[r]][pv];
            ++cnt[bid[l]][deq[bid[l]].back()];
            while (ptrl < tmpl.size()) deq[bid[l]].push_back(tmpl[ptrl++]);
        } else {
            int k; rit(k);
            k = (k + last - 1) % n + 1;
            int ans = 0;
            if (bid[l] == bid[r]) {
                for (int i = l - lb[l]; i <= r - lb[r]; ++i) {
                    if (deq[bid[l]][i] == k) ++ans;
                }
                printf("%d\n", ans);
                last = ans;
                continue;
            }
            for (int b = bid[l] + 1; b < bid[r]; ++b) ans += cnt[b][k];
            for (int i = l - lb[l]; i < deq[bid[l]].size(); ++i) {
                if (deq[bid[l]][i] == k) ++ans;
            }
            for (int i = 0; i <= r - lb[r]; ++i) {
                if (deq[bid[r]][i] == k) ++ans;
            }
            printf("%d\n", ans);
            last = ans;
        }
    }
    return 0;
}