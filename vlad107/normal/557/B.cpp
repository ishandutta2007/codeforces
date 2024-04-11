#include <stdio.h>
#include <math.h>
#include <algorithm>

const int N = 3e5;

int n, m;
int a[N];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n + n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + 2 * n);
    double ans = m * 1.0 / 3 / n;
    ans = std::min(ans, a[0] * 1.0);
    ans = std::min(ans, (double)a[n] / 2);
    printf("%.10lf\n", 3 * n * ans);
}