#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n, k, now;
double f[2][1005];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        now = 1 - now;
        for (int j = 1; j <= 1000; ++j)
            f[now][j] = (1.0 * j / (k * (j + 1)) + (1 - 1.0 / k)) * f[1 - now][j] +
            1.0 * j / (2 * k) + 1.0 * j / (k * (j + 1)) +
            1.0 / (k * (j + 1)) * f[1 - now][j + 1];
    }
    printf("%.10lf\n", f[now][1] * k);            
}