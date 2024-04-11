#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define maxN 105
#define oo 1000000007
using namespace std;

int n, d, a[maxN], x[maxN], y[maxN], c[maxN][maxN], f[maxN];
bool avail[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &d);
    fto(i, 2, n-1) scanf("%d", &a[i]);
    fto(i, 1, n) scanf("%d%d", &x[i], &y[i]);

    fto(u, 1, n)
        fto(v, 1, n)
            if (u != v) c[u][v] = (abs(x[u]-x[v])+abs(y[u]-y[v]))*d-a[v];


    fto(u, 1, n) f[u] = oo;
    f[1] = 0;
    memset(avail, true, sizeof(avail));
    while (true) {
        int minD = oo, u = 0;
        fto(v, 1, n)
            if (avail[v] && f[v] < minD) {
                minD = f[v]; u = v;
            }
        if (u == n) break;
        avail[u] = false;
        fto(v, 1, n)
            if (avail[v] && f[v] > f[u]+c[u][v]) f[v] = f[u]+c[u][v];
    }

    cout << f[n];
}