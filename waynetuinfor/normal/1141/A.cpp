#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    if (m % n != 0) {
        puts("-1");
        return 0;
    }
    m /= n;
    int ans = 0;
    while (m % 2 == 0) m /= 2, ++ans;
    while (m % 3 == 0) m /= 3, ++ans;
    if (m != 1) ans = -1;
    printf("%d\n", ans);
}