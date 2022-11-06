#include <bits/stdc++.h>
#define getchar gtx
#define int long long
using namespace std;

const int maxn = 5e5 + 10, sq = 450;
int a[maxn], lb[maxn / sq + 10], rb[maxn / sq + 10], id[maxn], tag[maxn / sq + 10];
unordered_map<int, pair<int, int>> pos[maxn / sq + 10];

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

int32_t main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; rit(n, q);
    for (int i = 1; i <= n; ++i) rit(a[i]);
    int blk = 0;
    for (int i = 1; i <= n; ) {
        ++blk; lb[blk] = i;
        for (int j = 0; j < sq && i <= n; ++j, ++i) {
            if (pos[blk].find(a[i]) == pos[blk].end()) pos[blk][a[i]] = make_pair(i, i);
            pos[blk][a[i]].second = i;
            id[i] = blk;
        }
        rb[blk] = i - 1;
    }
    while (q--) {
        int t; rit(t);
        if (t == 1) {
            int l, r, x; rit(l, r, x);
            if (id[l] == id[r]) {
                for (int i = l; i <= r; ++i) a[i] += x;
                pos[id[l]].clear();
                for (int i = lb[id[l]]; i <= rb[id[l]]; ++i) {
                    if (pos[id[l]].find(a[i]) == pos[id[l]].end()) pos[id[l]][a[i]] = make_pair(i, i);
                    pos[id[l]][a[i]].second = i;
                }
                continue;
            }
            for (int i = id[l] + 1; i < id[r]; ++i) tag[i] += x;
            pos[id[l]].clear(); pos[id[r]].clear();
            for (int i = l; i <= rb[id[l]]; ++i) a[i] += x;
            for (int i = lb[id[l]]; i <= rb[id[l]]; ++i) {
                if (pos[id[l]].find(a[i]) == pos[id[l]].end()) pos[id[l]][a[i]] = make_pair(i, i);
                pos[id[l]][a[i]].second = i;
            }
            for (int i = lb[id[r]]; i <= r; ++i) a[i] += x;
            for (int i = lb[id[r]]; i <= rb[id[r]]; ++i) {
                if (pos[id[r]].find(a[i]) == pos[id[r]].end()) pos[id[r]][a[i]] = make_pair(i, i);
                pos[id[r]][a[i]].second = i;
            }
        } else {
            int y; rit(y);
            int l = n + 1, r = 0;
            for (int i = 1; i <= blk; ++i) {
                int ty = y - tag[i];
                if (pos[i].find(ty) == pos[i].end()) continue;
                l = min(l, pos[i][ty].first); r = max(r, pos[i][ty].second);
            }
            if (r == 0 || l == n + 1) printf("%d\n", -1);
            else printf("%d\n", r - l);
            // if (r == 0 || l == n + 1) cout << "-1" << endl;
            // else cout << r - l << endl;
        }
    }
    return 0;
}