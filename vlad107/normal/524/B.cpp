#include <bits/stdc++.h>

using namespace std;

const int N = 2e3;
const int INF = 1e9 + 1e7;

int f[N], ff[N], n;

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < N; i++) f[i] = INF;
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        int h, w;
        scanf("%d%d", &h, &w);
        for (int j = 0; j < N; j++) ff[j] = INF;
        for (int j = 0; j < N; j++) {
            int nj = max(j, h);
            ff[nj] = min(ff[nj], f[j] + w);
            nj = max(j, w);
            ff[nj] = min(ff[nj], f[j] + h);
        }
        for (int j = 0; j < N; j++) f[j] = ff[j];
    }
    int ans = INF + 10;
    for (int i = 1; i < N; i++) {
        if (f[i] == INF) continue;
        ans = min(ans, f[i] * i);
    }
    printf("%d\n", ans);
}