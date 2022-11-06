#include <cstdio>
#include <algorithm>

int main() {
    int n; scanf("%d", &n);
    int ans = 0;
    while (n--) {
        int x, y; scanf("%d %d", &x, &y);
        ans = std::max(ans, x + y);
    }
    printf("%d\n", ans);
    return 0;
}