#include <bits/stdc++.h>
using namespace std;

const int kN = 2000 + 5;
int p[kN], q[kN], v[kN], w[kN], lv[kN], rv[kN], lw[kN], rw[kN];
int cv[kN][kN], cw[kN][kN], dp[kN];

int main() {
    int n; scanf("%d", &n);
    int a; scanf("%d", &a);
    memset(p, -1, sizeof(p));
    for (int i = 1; i < a; ++i) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    memset(v, -1, sizeof(v));
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        v[x - 1] = i;
    }
    for (int i = 0; i < a; ++i) {
        lv[i] = a + 1;
        rv[i] = -1;
    }
    for (int i = 0; i < a; ++i) {
        if (v[i] == -1) continue;
        for (int j = i; p[j] != -1; j = p[j]) {
            lv[j] = min(lv[j], v[i]);
            rv[j] = max(rv[j], v[i]);
        }
    }
    int b; scanf("%d", &b);
    memset(q, -1, sizeof(q));
    for (int i = 1; i < b; ++i) {
        scanf("%d", &q[i]);
        q[i]--;
    }
    memset(w, -1, sizeof(w));
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        w[x - 1] = i;
    }
    for (int i = 0; i < b; ++i) {
        lw[i] = b + 1;
        rw[i] = -1;
    }
    for (int i = 0; i < b; ++i) {
        if (w[i] == -1) continue;
        for (int j = i; q[j] != -1; j = q[j]) {
            lw[j] = min(lw[j], w[i]);
            rw[j] = max(rw[j], w[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a; ++j) {
            if (rv[j] == -1) continue;
            if (lv[j] >= i) ++cv[i][rv[j]];
        }
        for (int j = i; j < n; ++j) cv[i][j] += cv[i][j - 1];
        for (int j = 0; j < b; ++j) {
            if (rw[j] == -1) continue;
            if (lw[j] >= i) ++cw[i][rw[j]];
        }
        for (int j = i; j < n; ++j) cw[i][j] += cw[i][j - 1];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = -1;
        for (int j = 0; j < i; ++j)
            dp[i] = max(dp[i], dp[j] + max(cv[j][i - 1], cw[j][i - 1]));
    }
    printf("%d\n", dp[n]);
}