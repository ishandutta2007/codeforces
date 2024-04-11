#include <bits/stdc++.h>

using namespace std;

int b, g, n;

int main() {
    scanf("%d%d%d", &b, &g, &n);

    int ans = 0;
    for(int i = 0; i <= n; ++i) {
        int j = n - i;
        if (i <= b && j <= g)
            ++ans;
    }

    printf("%d", ans);

    return 0;
}