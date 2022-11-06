#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 3e5 + 10, lg = 25;
bool chg[lg + 5];

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

struct Trie {
    Trie *ch[2];
    int cnt;
    Trie(): cnt(0) {
        ch[0] = ch[1] = nullptr;
    }
    void insert(int x, int dep) {
        if (dep < 0) return;
        int bit = ((1 << dep) & x) >> dep;
        if (!ch[bit]) ch[bit] = new Trie();
        ++ch[bit]->cnt;
        ch[bit]->insert(x, dep - 1);
    }
    int query(int dep) {
        if (dep < 0) return 0;
        int bit = (int)chg[dep];
        if (ch[bit] && ch[bit]->cnt == (1 << dep)) {
            int ret = (1 << dep);
            if (ch[bit ^ 1]) ret += ch[bit ^ 1]->query(dep - 1);
            return ret;
        } else {
            if (!ch[bit]) return 0;
            return ch[bit]->query(dep - 1);
        }
    }
} *tr;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; rit(n, m);
    tr = new Trie();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) rit(a[i]);
    sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int i : a) tr->insert(i, lg);
    while (m--) {
        int x; rit(x);
        for (int i = 0; i < lg; ++i) {
            if ((1 << i) & x) chg[i] = !chg[i];
        }
        printf("%d\n", tr->query(lg));
        // cout << tr->query(lg) << endl;
    }
    return 0;
}