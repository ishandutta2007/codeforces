#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1001000;
#define pii pair<int, int>
#define fr first
#define se second

struct SAM { int len, ed, trans[2], link; } t[MAXN];
int las = 1, top = 1;
void extend (int c, int ed) {
    int now = ++top, i; t[now].len = t[las].len + 1; t[now].ed = ed;
    for (i = las; i && !t[i].trans[c]; i = t[i].link) t[i].trans[c] = now;
    las = now; if (!i) { t[now].link = 1; return; }
    int tmp = t[i].trans[c];
    if (t[tmp].len == t[i].len + 1) { t[now].link = tmp; return; }
    int cl = ++top; t[cl] = t[tmp]; t[cl].len = t[i].len + 1;
    for (i; t[i].trans[c] == tmp; i = t[i].link) t[i].trans[c] = cl;
    t[tmp].link = t[now].link = cl;
}

int n; char s[MAXN]; int a[MAXN];
vector <pii> q[MAXN];

namespace seg {
    struct node {
        int ls, rs, val;
    } t[MAXN * 10]; int top;

    void pushup (int x) { t[x].val = t[t[x].ls].val + t[t[x].rs].val; }
    void modify (int pos, int l, int r, int x) {
        if (l == r) { ++t[x].val; return; }
        int mid = (l + r) >> 1;
        if (pos <= mid) modify(pos, l, mid, t[x].ls ? t[x].ls : (t[x].ls = ++top));
        else modify(pos, mid + 1, r, t[x].rs ? t[x].rs : (t[x].rs = ++top));
        pushup(x);
    }
    int query (int l, int r, int L, int R, int x) {
        if (l > r) return 0;
        if (!x) return 0;
        if (l <= L && R <= r) return t[x].val;
        int mid = (L + R) >> 1, ret = 0;
        if (l <= mid) ret += query(l, r, L, mid, t[x].ls);
        if (mid < r) ret += query(l, r, mid + 1, R, t[x].rs);
        return ret;
    }
    int rt[MAXN];
}

const int SFT = 500000;
int R[MAXN], nex[MAXN];

int main () {
    n = read(); scanf("%s", s + 1);
    int i, j;
    for (i = 1; i <= n; i++) a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
    for (i = n; i >= 1; i--) extend(s[i] - '(', i);
    for (i = 2; i <= top; i++) q[t[i].ed].push_back(make_pair(t[i].ed + (t[t[i].link].len + 1) - 1, t[i].ed + t[i].len - 1));
    long long ans = 0;
    nex[0] = n + 1; R[n + 1] = n;
    for (i = n; i >= 1; i--) {
        if (a[i] < a[i - 1]) R[i] = i - 1;
        else if (nex[a[i - 1] + SFT]) R[i] = R[nex[a[i - 1] + SFT] + 1];
        else R[i] = n;
        for (auto j: q[i]) ans += seg::query(j.fr, min(R[i], j.se), 1, n, seg::rt[a[i - 1] + SFT]);
        nex[a[i] + SFT] = i;
        seg::modify(i, 1, n, seg::rt[a[i] + SFT] ? seg::rt[a[i] + SFT] : (seg::rt[a[i] + SFT] = ++seg::top));
    }
    printf("%lld\n", ans);
    return 0;
}