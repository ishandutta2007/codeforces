#include <cstdio>

using namespace std;

int a,b;
int mod = 1000000007;

int main()
{
    scanf("%d%d", &a, &b);
    long long rez = ((((1LL*b*(b-1)/2)%mod)*a)%mod+((((1LL*b*(b-1)/2)%mod)*((1LL*a*(a+1)/2)%mod))%mod*b)%mod)%mod;
    printf("%I64d\n", rez);

    return 0;
}