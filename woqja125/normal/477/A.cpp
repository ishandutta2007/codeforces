#include<stdio.h>
const int MOD = 1000000007;
int main()
{
    int a, b, i;
    long long s = 0;
    scanf("%d%d", &a, &b);
    for(i=1; i<b; i++)
    {
        long long t = 1ll * i * a % MOD;
        t += 1ll * i * b % MOD * (1ll*a*(a+1)/2 % MOD) % MOD;
        s += t;
        s %= MOD;   
    }
    printf("%I64d", s);
    return 0;
}