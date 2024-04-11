#include <cstdio>

using namespace std;

#define maxn 1000010
#define mod 1000000007

int n, m, x, u, sol, d;
int f[maxn];

int main()
{
  //  freopen("d.in", "r", stdin);
  //  freopen("d.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);
        if(x==1)
            ++u;
        else
            ++d;
    }

    f[0]=1;
    f[1]=1;

    for(int i=2; i<=u; ++i)
        f[i]=(1LL*(i-1)*f[i-2]+f[i-1])%mod;

    sol=f[u];
    for(int i=n; i>n-d; --i)
        sol=(1LL*sol*i)%mod;

    printf("%d\n", sol);

    return 0;
}