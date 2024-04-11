#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma comment(linker, "/stack:200000000")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <random>

using namespace std;
mt19937 RND (random_device{}());

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 3003000;
#define pii pair<int, int>
#define fr first
#define se second

int n, K, suf[MAXN]; pii a[MAXN]; char s[MAXN];
struct node { int ls, rs, val, siz, rnd; } t[MAXN]; int top = 0, root = 0;
int newnode (int val) { ++top; t[top].ls = t[top].rs = 0, t[top].val = val, t[top].siz = 1, t[top].rnd = RND(); return top; }
void pushup (int x) { t[x].siz = t[t[x].ls].siz + t[t[x].rs].siz + 1; }

void split (int now, int k, int &x, int &y) {
    if (!now) { x = y = 0; return; }
    if (t[t[now].ls].siz + 1 <= k) x = now, split(t[now].rs, k - t[t[now].ls].siz - 1, t[now].rs, y);
    else y = now, split(t[now].ls, k, x, t[now].ls);
    pushup(now);
}
int merge (int x, int y) {
    if (!x || !y) return x | y;
    if (t[x].rnd < t[y].rnd) { t[x].rs = merge(t[x].rs, y); pushup(x); return x; }
    else { t[y].ls = merge(x, t[y].ls); pushup(y); return y; }
}
int ask (int k, int x) {
    if (t[t[x].ls].siz >= k) return ask(k, t[x].ls);
    else if (t[t[x].ls].siz + 1 < k) return ask(k - 1 - t[t[x].ls].siz, t[x].rs);
    else return t[x].val;
}
void out (int x) {
    if (t[x].ls) out(t[x].ls);
    putchar(t[x].val);
    if (t[x].rs) out(t[x].rs);
}

int main () {
    scanf("%s", s + 1);
    K = read(), n = read(); int i, j, L = 1e9, R = -1e9;
    for (i = 1; i <= n; i++) a[i].fr = read(), a[i].se = read(), L = min(L, a[i].fr), R = max(R, a[i].se);
    suf[n + 1] = K;
    for (i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (a[i].se >= suf[i]) continue;
        suf[i] -= min(2 * a[i].se - a[i].fr + 1, suf[i]) - a[i].se;
    }
    for (i = 1, j = min(suf[1], (int) strlen(s + 1)); i <= j; i++) root = merge(root, newnode(s[i]));
    for (i = 1; i <= n; i++) {
        int cnt = 0, r1, r2 = 0, r3; split(root, a[i].se, r1, r3);
        for (j = a[i].fr + 1; j <= a[i].se && cnt < suf[i + 1] - suf[i]; j += 2) r2 = merge(r2, newnode(ask(j, r1))), ++cnt;
        for (j = a[i].fr; j <= a[i].se && cnt < suf[i + 1] - suf[i]; j += 2) r2 = merge(r2, newnode(ask(j, r1))), ++cnt;
        root = merge(r1, merge(r2, r3));
    }
    out(root); puts("");
    return 0;
}