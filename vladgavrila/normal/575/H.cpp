#include <cstdio>

using namespace std;

#define maxn 2000010
#define mod 1000000007

int n, m;
int f[maxn], fi[maxn];

int lgput(int nr, int e)
{
    if(e==0)
        return 1;

    int aux=lgput(nr, e/2);

    aux=(1LL*aux*aux)%mod;

    if(e%2)
        aux=(1LL*aux*nr)%mod;

    return aux;
}

int main()
{
    scanf("%d", &n);
    ++n;

    f[0]=fi[0]=1;

    for(int i=1; i<=2*n; ++i)
        f[i]=(1LL*f[i-1]*i)%mod;

    for(int i=1; i<=n; ++i)
        fi[i]=(1LL*fi[i-1]*lgput(i, mod-2))%mod;

    int sol = (((((2LL*f[2*n-1]*fi[n])%mod)*fi[n-1])%mod)-1+mod)%mod;

    printf("%d\n", sol);
}