#include <cstdio>
#include <algorithm>
int a[200001];
int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    std::sort(a+1, a+n+1);
    long long ans = 0;
    for(int i=1; i<=n/2+1; i++) {
        if(a[i] >= s) ans += a[i] - s;
    }
    for(int i=n/2+1; i<=n; i++) if(a[i] <= s) ans += s - a[i];
    printf("%lld\n", ans);
    return 0;
}