#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <ctime>
#include <cmath>
#include <queue>
#define pii pair <int, int>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define type double

using namespace std;

const int N = 100100;
int a[35][N], d[N], l[N], r[N], res[N], sum[N];
int n, m;

int solve (int k) {
    memset (d, 0, sizeof d);
    for (int i = 1; i <= m; i++) if (a[k][i]) {
        d[l[i]]++, d[r[i] + 1]--;
    }
    int now = 0;
    for (int i = 1; i <= n; i++) {
        now += d[i];
        sum[i] = sum[i - 1];
        res[i] *= 2;
        if (now) sum[i]++, res[i]++;
    }
    for (int i = 1; i <= m; i++) if (!a[k][i]) {
        if (sum[r[i]] - sum[l[i] - 1] == r[i] - l[i] + 1) return 0;
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d%d", &l[i], &r[i], &c);
        for (int j = 1; j <= 32; j++) {
            a[j][i] = c % 2;
            c /= 2;
        }
    }
    for (int i = 32; i >= 1; i--) {
        if (!solve (i)) {
            printf ("NO\n");
            return 0;
        }
    }
    printf ("YES\n");
    for (int i = 1; i <= n; i++) {
        printf ("%d", res[i]);
        if (i != n) printf (" ");
    }
}