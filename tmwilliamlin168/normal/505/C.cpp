#include <bits/stdc++.h>
using namespace std;

const int N = 30005;
const int M = 255;
int n, d, ans, p[N], a[N], f[N][2*M], v[N][2*M];
int main() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", p+i);
        a[p[i]]++;
    }
    v[d][M] = 1;
    for (int i = 1; i < N; i++)
        for (int j = -M; j < M; j++) {
            if ((d+j > 1)&&(i > d+j)&&(v[i-d-j][j+M-1])) {
                f[i][j+M] = max(f[i-d-j][j+M-1], f[i][j+M]);
                v[i][j+M] = 1;
            }
            if ((i > d+j)&&(v[i-d-j][j+M])) {
                f[i][j+M] = max(f[i-d-j][j+M], f[i][j+M]);
                v[i][j+M] = 1;
            }
            if ((i > d+j)&&(v[i-d-j][j+M+1])) {
                f[i][j+M] = max(f[i-d-j][j+M+1], f[i][j+M]);
                v[i][j+M] = 1;
            }
            if (v[i][j+M]) {
                f[i][j+M] += a[i];
                ans = max(ans, f[i][j+M]);
            }
        }
    printf("%d\n", ans);
}