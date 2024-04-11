#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 110000, M = 1001000;

int a[N], b[N], c[2][20][N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0, j = 1; j <= n; i++, j *= 2) {
        int an = 0, bn = 0;
        for (int k = 1; k <= n; k++) {
            if (k & (1 << i)) a[++an] = k;
            else b[++bn] = k;
        }
        if (an) {
            printf ("%d\n", an);
            for (int k = 1; k <= an; k++) {
                if (k != 1) printf (" ");
                printf ("%d", a[k]);
            }
            printf ("\n");
            fflush(stdout);
            for (int k = 1; k <= n; k++) {
                scanf ("%d", &c[0][i][k]);
            }
        }
        if (bn) {
            printf ("%d\n", bn);
            for (int k = 1; k <= bn; k++) {
                if (k != 1) printf (" ");
                printf ("%d", b[k]);
            }
            printf ("\n");
            fflush(stdout);
            for (int k = 1; k <= n; k++) {
                scanf ("%d", &c[1][i][k]);
            }
        }
    }
    cout << -1 << endl;
    for (int k = 1; k <= n; k++) {
        int mn = 1e9;
        for (int i = 0, j = 1; j <= n; i++, j *= 2) {
//            cout << k << ' ' << i << ' ' << c[0][i] << ' ' <<
            if (k & (1 << i)) mn = min (mn, c[1][i][k]);
            else mn = min (mn, c[0][i][k]);
        }
        if (k != 1) printf (" ");
        printf ("%d", mn);
    }
    printf ("\n");
    fflush(stdout);
}