#include <cstdio>
#include <algorithm>
int a[200001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<2*n; i++) scanf("%d", a+i);
    std::sort(a, a+2*n);
    long long ans = (0ll+a[n-1] - a[0])*(a[2*n-1] - a[n]);
    for(int i=1; i<n; i++) {
        long long t = (0ll+a[n-1+i] - a[i]) * (a[2*n-1] - a[0]);
        if(ans > t) ans = t;
    }
    printf("%lld\n", ans);
    return 0;
}