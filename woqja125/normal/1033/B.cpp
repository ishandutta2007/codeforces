#include <cstdio>
bool isP(long long x) {
    for(long long i=2; i*i <= x; i++) if(x%i == 0) return false;
    return true;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int tt=0; tt<t; tt++) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        if(a-b == 1 && isP(a+b)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}