#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &a[i][0], &a[i][1]);
    if (n == 3) {
        printf("1 2 3\n");
        return 0;
    }
    for (int i = 0; i < n; ++i) --a[i][0], --a[i][1];
    for (int i = 0, c = 0; c < n; ++c) {
        int p = -1;
        for (int j = 0; j < 2; ++j) {
            bool f = false;
            for (int k = 0; k < 2; ++k) f |= a[a[i][j ^ 1]][k] == a[i][j];
            if (!f) p = j;
        }
        if (p == -1) throw;
        printf("%d ", a[i][p] + 1);
        i = a[i][p];
    }
    puts("");
    return 0;
}