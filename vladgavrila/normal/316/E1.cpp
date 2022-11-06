#include <cstdio>

using namespace std;

#define mod 1000000000
#define maxn 200010

int n, t, m, x, y, sol;
int a[maxn];
int f[maxn];


int main()
{
  //  freopen("e.in", "r", stdin);
  //  freopen("e.out", "w", stdout);

    scanf("%d%d", &n, &m);
    f[0]=f[1]=1;
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        if(i>1)
            f[i]=(f[i-1]+f[i-2])%mod;
    }

    while(m--)
    {
        scanf("%d", &t);
        if(t==1)
        {
            scanf("%d%d", &x, &y);
            a[x]=y;
        }
        if(t==2)
        {
            scanf("%d%d", &x, &y);
            sol=0;
            for(int i=x; i<=y; ++i)
                sol=(1LL*sol+1LL*f[i-x]*a[i])%mod;
            printf("%d\n", sol);
        }
    }

    return 0;
}