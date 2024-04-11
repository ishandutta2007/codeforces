#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

const int N = 1111;
const int BASE = 1e9 + 7;

int a[N];
int f[N][N], c[N][N];

void add(int &x, int y) {
    x += y;
    if (x >= BASE) x -= BASE;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    memset(f, 0, sizeof(f));
    memset(c, 0, sizeof(c));
    c[0][0] = 1;
    for (int i = 0; i + 1 < N; i++) {
        for (int j = 0; j <= i; j++) {
            add(c[i+1][j],c[i][j]);
            add(c[i+1][j+1],c[i][j]);
        }
    }
    for (int i = a[0]; i <= s; i++) f[0][i] = c[i - 1][a[0] - 1];
    int cs = 0;
    for (int i = 1; i < n; i++) {
        cs += a[i - 1];
        int cur = 0;
        for (int j = 1; j <= s; j++) {
            if (j > cs) f[i][j] = (cur * 1LL * c[j - cs - 1][a[i] - 1]) % BASE;
            add(cur, f[i - 1][j]);
        }
    }
    printf("%d\n", f[n-1][s]);
}