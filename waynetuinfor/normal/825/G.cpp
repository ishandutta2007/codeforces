#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 1e6 + 10;
vector<int> G[maxn];
int ans[maxn];

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

void dfs(int now, int cur, int fa) {
    if (cur >= ans[now]) return;
    ans[now] = cur;
    for (int u : G[now]) if (u != fa) dfs(u, min(cur, u), now);
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; rit(n, q);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; rit(a, b);
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    fill(ans, ans + maxn, n + 1);
    int last = 0, bst = n + 1;
    while (q--) {
        int t, z; rit(t, z);
        int x = (z + last) % n + 1;
        if (t == 1) dfs(x, x, 0), bst = min(bst, ans[x]);
        else printf("%d\n", min(ans[x], bst)), last = min(ans[x], bst);
    }
    return 0;
}