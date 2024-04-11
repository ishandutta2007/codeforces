#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
const int MAXN = 50050 * 30;
int n, m, K;
using pii = pair <ll, ll>;
#define fr first
#define se second
pii a[MAXN], b[MAXN];

pii tmp[MAXN];
int simp (pii *f, int N) {
    int top = 0;
    for (int i = 1; i <= N; i++) {
        if (!top || tmp[top].fr != f[i].fr) tmp[++top] = f[i];
        else tmp[top].se += f[i].se;
    }
    for (int i = 1; i <= top; i++) f[i] = tmp[i];
    return top;
}

int main () {
    int T = read(); while (T--) {
        n = read(), K = read(); int i, j;
        for (i = 1; i <= n; i++) {
            a[i].fr = read(), a[i].se = 1;
            while (a[i].fr % K == 0) a[i].fr /= K, a[i].se *= K;
        }
        m = read();
        for (i = 1; i <= m; i++) {
            b[i].fr = read(), b[i].se = 1;
            while (b[i].fr % K == 0) b[i].fr /= K, b[i].se *= K;
        }
        int lena = simp(a, n), lenb = simp(b, m);
        if (lena != lenb) { puts("No"); continue; }
        for (i = 1; i <= lena; i++) if (a[i] != b[i]) { puts("No"); break; }
        if (i > lena) puts("Yes");
    }
    return 0;
}