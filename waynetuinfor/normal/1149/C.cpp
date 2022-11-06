#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int mx[maxn * 4], mn[maxn * 4], lr[maxn * 4], rl[maxn * 4], ans[maxn * 4], tag[maxn * 4];
char t[maxn];
int s[maxn];

void pull(int o) {
    mx[o] = max(mx[o * 2 + 1], mx[o * 2 + 2]);
    mn[o] = min(mn[o * 2 + 1], mn[o * 2 + 2]);
    lr[o] = max(lr[o * 2 + 1], lr[o * 2 + 2]);
    lr[o] = max(lr[o], mx[o * 2 + 1] - 2 * mn[o * 2 + 2]);
    rl[o] = max(rl[o * 2 + 1], rl[o * 2 + 2]);
    rl[o] = max(rl[o], mx[o * 2 + 2] - 2 * mn[o * 2 + 1]);
    ans[o] = max(ans[o * 2 + 1], ans[o * 2 + 2]);
    ans[o] = max(ans[o], mx[o * 2 + 1] + rl[o * 2 + 2]);
    ans[o] = max(ans[o], mx[o * 2 + 2] + lr[o * 2 + 1]);
}

void apply(int o, int v) {
    tag[o] += v;
    mx[o] += v;
    mn[o] += v;
    lr[o] -= v;
    rl[o] -= v;
}

void push(int o) {
    if (tag[o] == 0)
        return;

    apply(o * 2 + 1, tag[o]);
    apply(o * 2 + 2, tag[o]);
    tag[o] = 0;
}

void modify(int l, int r, int ql, int qr, int v, int o = 0) {
    if (l >= qr || ql >= r)
        return;

    if (l >= ql && r <= qr) {
        apply(o, v);
        return;
    }

    push(o);
    modify(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
    modify((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
    pull(o);
}

void build(int l, int r, int o = 0) {
    if (r - l == 1) {
        mx[o] = s[l];
        mn[o] = s[l];
        lr[o] = -s[l];
        rl[o] = -s[l];
        ans[o] = 0;
        return;
    }

    build(l, (l + r) >> 1, o * 2 + 1);
    build((l + r) >> 1, r, o * 2 + 2);
    pull(o);
}

int main() {
    int n, q; scanf("%d%d", &n, &q);
    n = 2 * (n - 1);
    scanf("%s", t + 1);
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + (t[i] == '(' ? 1 : -1);

    build(0, n + 1);
    printf("%d\n", ans[0]);

    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        if (l > r) swap(l, r);
        if (t[l] != t[r]) {
            if (t[l] == ')')
                modify(0, n + 1, l, r, 2);
            else
                modify(0, n + 1, l, r, -2);
        }
        swap(t[l], t[r]);
        printf("%d\n", ans[0]);
    }
    return 0;
}

// 1 2 3 4 3 2 1 0
// 1 2 3 2 3 2 1 0
// 1 2 1 2 3 2 1 0
// 1 2 1 2 1 2 1 0