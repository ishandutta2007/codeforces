#include <bits/stdc++.h>

using namespace std;

const int K = 10000;

int n, l[50], r[50];
long double f[10][10][2];

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &l[i], &r[i]);
    long double cnt = 1;
    for (int i = 0; i < n; i++) cnt = cnt * (r[i] - l[i] + 1);
    long double ans = 0;
    for (int it = 1; it <= K; it++) {
        memset(f, 0, sizeof(f));
        f[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                for (int flag = 0; flag < 2; flag++) {
                    if (f[i][j][flag] == 0) continue;
                    f[i + 1][j][flag] += f[i][j][flag] * max(0, min(it, r[i] + 1) - l[i]);
                    if ((it >= l[i]) && (it <= r[i])) {
                        f[i + 1][j + 1][flag] += f[i][j][flag];
                    }
                    if (!flag) {
                        f[i + 1][j][1] += f[i][j][flag] * max(0, r[i] - max(it, l[i] - 1));
                    }
                }
            }
        }
        long double cur = 0;
        for (int j = 1; j <= n; j++) {
            for (int flag = 0; flag < 2; flag++) {
                if ((!flag) && (j == 1)) continue;
                cur += f[n][j][flag];
            }
        }
        ans += cur * it;
    }
    printf("%.10lf\n", (double)(ans / cnt));
}