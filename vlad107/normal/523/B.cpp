#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

const int N = 5e5;

int n, T;
double c, pa[N], sa[N];
int a[N];

int main() {
//  freopen("input.txt", "r", stdin);
    cin >> n >> T >> c;
    double revT = 1.0 / T;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pa[i + 1] = (pa[i] + a[i] * revT) / c;
        sa[i + 1] = sa[i] + a[i] * revT;
    }
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int x;
        scanf("%d", &x);
        double u = (sa[x] - sa[x - T]);
        double v = pa[x];
        double e = fabs(u - v) / u;
        printf("%.10lf %.10lf %.10lf\n", u, v, e);
    }
}