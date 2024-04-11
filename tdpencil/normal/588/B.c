#include <stdio.h>
long long n;
int main() {
    scanf("%lld", &n);
    long long ans = 1;
    for (int i = 2; (long long) i * i <= n; i++) {
        char done = 1; 
        while(n % i == 0) {
            if(done)
                ans *= i;
            done = 0;
            n /= i;
        }
    }
    if(n > 1)
        ans *= n;

    printf("%lld", ans);
}