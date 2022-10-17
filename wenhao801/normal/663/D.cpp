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

#define pii pair <int, int>
#define fr first
#define se second

const int MAXN = 5050, inf = 1e9 + 7;
int n, a[MAXN], b[MAXN], c[MAXN];

int s[] = {0, 500, 1000, 1500, 2000, 2500, 3000};
int mxa, mxb, mxc;
inline pii foo (int id) {
    if (id == 1) return {(n >> 1) + 1, n};
    if (id == 2) return {(n >> 2) + 1, n >> 1};
    if (id == 3) return {(n >> 3) + 1, n >> 2};
    if (id == 4) return {(n >> 4) + 1, n >> 3};
    if (id == 5) return {(n >> 5) + 1, n >> 4};
    return {0, n >> 5};
}

int f[95][95][95], las[95][95][95];
int scoreA (int id, int idA) { return a[id] ? (s[idA] * (250 - abs(a[id]))) : 0; }
int scoreB (int id, int idB) { return b[id] ? (s[idB] * (250 - abs(b[id]))) : 0; }
int scoreC (int id, int idC) { return c[id] ? (s[idC] * (250 - abs(c[id]))) : 0; }
int score (int id, int idA, int idB, int idC) {
    return scoreA(id, idA) + scoreB(id, idB) + scoreC(id, idC);
}

int ans = inf;
void solve (int idA, int idB, int idC) {
    pii A = foo(idA), B = foo(idB), C = foo(idC);
    A.fr = n - A.fr, A.se = n - A.se, swap(A.fr, A.se);
    B.fr = n - B.fr, B.se = n - B.se, swap(B.fr, B.se);
    C.fr = n - C.fr, C.se = n - C.se, swap(C.fr, C.se);
    int ca = 0, cb = 0, cc = 0, i, j, k;
    for (i = 1; i <= n; i++)
        ca += a[i] < 0, cb += b[i] < 0, cc += c[i] < 0,
        A.fr -= !a[i], A.se -= !a[i], B.fr -= !b[i], B.se -= !b[i], C.fr -= !c[i], C.se -= !c[i];
    if (ca < A.fr || cb < B.fr || cc < C.fr || A.se < 0 || B.se < 0 || C.se < 0) return;
    
    // printf("%d %d %d\n", A.fr, A.se, ca);
    // printf("%d %d %d\n", B.fr, B.se, cb);
    // printf("%d %d %d\n", C.fr, C.se, cc);
    
    const int cur = (min(ca, A.se) + min(cb, B.se) + min(cc, C.se)) * 100 * 250 + score(1, idA, idB, idC);
    if (cur >= (s[idA] + s[idB] + s[idC]) * 250) { puts("1"); exit(0); }
    int ex = 0;
    for (i = 0; i <= min(ca, A.se); i++) for (j = 0; j <= min(cb, B.se); j++) for (k = 0; k <= min(cc, C.se); k++)
        las[i][j][k] = inf;
    las[0][0][0] = 0;
    for (int it = 2; it <= n; it++) {
        if (a[it] >= 0 && b[it] >= 0 && c[it] >= 0) {
            ex += score(it, idA, idB, idC) > cur;
            continue;
        }
        for (i = 0; i <= min(ca, A.se); i++) for (j = 0; j <= min(cb, B.se); j++) for (k = 0; k <= min(cc, C.se); k++)
            f[i][j][k] = inf;
        for (int x = 0; x <= (a[it] < 0); x++) for (int y = 0; y <= (b[it] < 0); y++) for (int z = 0; z <= (c[it] < 0); z++) {
            const int curit = (x ^ 1) * scoreA(it, idA) + (y ^ 1) * scoreB(it, idB) + (z ^ 1) * scoreC(it, idC);
            for (i = x; i <= min(ca, A.se); i++) for (j = y; j <= min(cb, B.se); j++) for (k = z; k <= min(cc, C.se); k++)
                f[i][j][k] = min(f[i][j][k], las[i - x][j - y][k - z] + (curit > cur));
        }
        for (i = 0; i <= min(ca, A.se); i++) for (j = 0; j <= min(cb, B.se); j++) for (k = 0; k <= min(cc, C.se); k++)
            las[i][j][k] = f[i][j][k];
    }
    // printf("%d\n", las[min(ca, A.se)][min(cb, B.se)][min(cc, C.se)] + ex);
    ans = min(ans, las[min(ca, A.se)][min(cb, B.se)][min(cc, C.se)] + ex);
}

int main () {
    n = read(); int i, j, k;
    for (i = 1; i <= n; i++) a[i] = read(), b[i] = read(), c[i] = read();

    for (i = 1; i <= 6; i++) for (j = 1; j <= 6; j++) for (k = 1; k <= 6; k++)
        solve(i, j, k);
    printf("%d\n", ans + 1);
    return 0;
}