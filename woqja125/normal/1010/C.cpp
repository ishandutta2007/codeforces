#include <cstdio>
int gcd(int a, int b) {
    return b?gcd(b, a%b):a;
}
int main() {
    int n, k, g, t;
    scanf("%d%d", &n, &k);
    g = k;
    for(int i=1; i<=n; i++) {
        scanf("%d", &t); t %= k;
        g = gcd(g, t);
    }
    printf("%d\n", k/g);
    for(int i=0; i<k; i+=g) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}