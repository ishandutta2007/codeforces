#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

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

using ld = long double;
const int MAXN = 100100;
int n; pii A, B, T, a[MAXN];

inline ld dis (pii x, pii y) { return sqrt(1ll * (x.fr - y.fr) * (x.fr - y.fr) + 1ll * (x.se - y.se) * (x.se - y.se)); }
struct node { int id; ld val; bool operator < (const node &other) const { return val < other.val; } } p[MAXN], q[MAXN];

int main () {
    A.fr = read(), A.se = read(), B.fr = read(), B.se = read(), T.fr = read(), T.se = read();
    n = read();
    int i, j;
    ld ans = 0, out = 1e18;
    for (i = 1; i <= n; i++) {
        a[i].fr = read(), a[i].se = read();
        ans += dis(a[i], T) * 2;
    }
    if (n == 1) { printf("%.8Lf\n", min(dis(A, a[1]), dis(B, a[1])) + dis(a[1], T)); return 0; }
    for (i = 1; i <= n; i++) p[i].id = q[i].id = i, p[i].val = dis(a[i], A) - dis(a[i], T), q[i].val = dis(a[i], B) - dis(a[i], T);
    sort(p + 1, p + n + 1); sort(q + 1, q + n + 1);
    out = min(out, min(ans + p[1].val, ans + q[1].val));
    if (p[1].id != q[1].id) out = min(out, ans + p[1].val + q[1].val);
    else out = min(out, min(ans + p[1].val + q[2].val, ans + p[2].val + q[1].val));
    printf("%.8Lf\n", out);
    return 0;
}