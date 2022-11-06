#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], n, q, st[20][maxn];
vector<int> pos[maxn];

void check() {
    for (int i = 1; i <= n; ++i) st[0][i - 1] = a[i] == 0 ? maxn : a[i];
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j)
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    for (int i = 1; i <= q; ++i) if (pos[i].size()) {
        int l = pos[i].front() - 1, r = pos[i].back() - 1;
        int p = 31 - __builtin_clz(r - l + 1);
        int x = min(st[p][l], st[p][r - (1 << p) + 1]);
        if (x < i) {
            puts("NO");
            exit(0);
        }
    }
}

int main() {
    scanf("%d %d", &n, &q);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == 0) ++cnt;
        pos[a[i]].push_back(i);
    }
    check();
    if (cnt == 0) {
        if (pos[q].size() == 0) return 0 * puts("NO");
        puts("YES");
        for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
        puts("");
        return 0;
    }
    bool u = false;
    for (int i = 1; i <= n; ) {
        if (a[i] > 0) {
            ++i;
            continue;
        }
        int j = i;
        while (j <= n && a[j] == 0) ++j;
        int prv = a[i - 1], nxt = a[n + 1];
        if (prv == 0) prv = 1;
        if (pos[q].size() == 0 && !u) {
            for (int k = i; k < j; ++k) a[k] = q;
            u = true;
        } else {
            for (int k = i; k < j; ++k) a[k] = prv;
        }
        i = j;
    }
    for (int i = 1; i <= q; ++i) pos[i].clear();
    for (int i = 1; i <= n; ++i) pos[a[i]].push_back(i);
    check();
    if (pos[q].size() == 0) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    puts("");
    return 0;
}