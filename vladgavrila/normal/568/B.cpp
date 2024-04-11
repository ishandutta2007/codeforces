#include <cstdio>

using namespace std;

#define maxn 16010
#define mod 1000000007

int n, m;
int f[maxn], fi[maxn], b[maxn];

int lgput(int nr, int e)
{
    if(e==0)
        return 1;

    int aux = lgput(nr, e/2);

    aux=(1LL*aux*aux)%mod;
    if(e%2)
        aux=(1LL*aux*nr)%mod;

    return aux;
}

long long getComb(int nn, int k)
{
    return (((1LL*f[nn]*fi[k])%mod)*fi[nn-k])%mod;
}

int main()
{
    scanf("%d", &n);

    f[0]=fi[0]=1;

    for(int i=1; i<=4*n; ++i)
    {
        f[i]=(1LL*f[i-1]*i)%mod;
        fi[i]=(1LL*fi[i-1]*lgput(i, mod-2))%mod;
    }

    int sol=1;

    b[0]=1;
    for(int i=1; i<=n; ++i)
        for(int j=0; j<i; ++j)
            b[i]=(b[i]+1LL*b[j]*getComb(i-1, j))%mod;

    for(int i=1; i<n; ++i)
        sol = (sol + 1LL* b[i] * getComb(n, n-i))%mod;

    printf("%d\n", (int)sol);

    return 0;
}