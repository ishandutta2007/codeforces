#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[maxn][maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            a[i][j] = ((i / 2) * n + j) * 2 + (i & 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf("%d ", a[i][j]);
        puts("");
    }
}