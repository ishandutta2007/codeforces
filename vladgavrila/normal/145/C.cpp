#include <cstdio>
#include <algorithm>

using namespace std;

#define mod 1000000007
#define maxn 100010

int n, k, ns, nm;
long long sol;
int v[maxn];
long long f[maxn], nr[maxn], p2[maxn], imod[maxn];
long long d[maxn];

int isLucky(int x)
{
    if(x==0)
        return 0;
    while(x>0)
    {
        if(x%10!=4 && x%10!=7)
            return 0;
        x/=10;
    }
    return 1;
}

long long lgput(int nr, int exp)
{
    if(exp==0)
        return 1;
    long long aux=lgput(nr, exp/2);
    aux=(1LL*aux*aux)%mod;
    if(exp%2)
        return (1LL*aux*nr)%mod;
    return aux;
}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    sort(v+1, v+n+1);

    p2[0]=1;
    imod[0]=1;
    for(int i=1; i<=n; ++i)
    {
        p2[i]=(p2[i-1]*1LL*i)%mod;
        imod[i]=(lgput(i, mod-2)*imod[i-1])%mod;
        if(isLucky(v[i]))
        {
            if(v[i]==nr[ns])
                ++f[ns];
            else
            {
                nr[++ns]=v[i];
                f[ns]=1;
            }
        }
        else
            ++nm;
    }

    d[0]=1;
    for(int i=1; i<=ns; ++i)
        for(int j=ns; j; --j)
            d[j]=(1LL*d[j]+1LL*d[j-1]*f[i])%mod;

    sol=0;
    for(int i=0; i<=k; ++i)
        if(k-i<=nm)
            sol=(1LL*sol+(p2[nm]*((imod[k-i]*imod[nm-k+i])%mod)%mod)*d[i])%mod;
    printf("%I64d\n", sol);

    return 0;
}