#include <cstdio>

int main() {
    long long n;
    scanf("%lld", &n);
    for(int i=2; 1ll*i*i <= n; i++) {
        if(n%i != 0) continue;
        int c = 0;
        while(n%i == 0) n /= i, c++;
        if(n == 1) {
            printf("%d\n", i);
            return 0;
        }
        else {
            printf("1\n");
            return 0;
        }
    }
    printf("%lld\n", n);
    return 0;
}