#include <cstdio>

using namespace std;

#define maxn 1010

int n, x, m, sol;
int f[maxn], nr[maxn];
int d[maxn];

int main()
{
 //   freopen("b.in", "r", stdin);
 //   freopen("b.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &f[i]);

    for(int i=1; i<=n; ++i)
    {
        x=i;
        while(f[x]!=0)
            x=f[x];
        ++nr[x];
    }

    x=m;
    sol=1;
    while(f[x]!=0)
    {
        x=f[x];
        ++sol;
    }
    nr[x]=0;

    d[0]=1;
    for(int i=1; i<=n; ++i)
    {
        if(nr[i]==0)
            continue;

        for(int j=n; j>=nr[i]; --j)
        {
            if(d[j-nr[i]]==1)
                d[j]=1;
        }
    }

    for(int i=0; i<=n; ++i)
        if(d[i])
            printf("%d\n", i+sol);

    return 0;
}