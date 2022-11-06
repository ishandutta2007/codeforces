#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("%d\n", n + 1);
    for (int i = n - 1; i >= 0; --i) {
        int tg = (a[i] / n) * n + i - a[i];
        if (tg < 0) tg += n;
        for (int j = i; j >= 0; --j) a[j] += tg;
        printf("1 %d %d\n", i + 1, tg);
    }
    printf("2 %d %d\n", n, n);
}