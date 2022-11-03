#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, a[N];
int main() {
    scanf("%d", &n);
    int fir = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if (!fir && a[i] != a[1]) fir = i;
    }
    int ans = 0;
    for (int i = n; i; --i) 
        if (a[i] != a[1]) ans = max(ans, i - 1);
        else ans = max(ans, i - fir);
    printf("%d\n", ans);
    return 0;
}