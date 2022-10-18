#include <bits/stdc++.h>

using namespace std;

int n, d, e;

int main() {
    scanf("%d%d%d", &n, &d, &e);

    int ans = n;
    for(int j = 0; j <= n/(5*e); ++j) {
        int remain = n - 5*e*j;
        int i = remain / d;
        remain -= d*i;
        ans = min(ans, remain);
    }

    printf("%d", ans);

    return 0;
}