#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define maxn 100010

int n, m, k, t, cr, sol, maxb;
int v[maxn], d[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d%d%d", &k, &n, &maxb, &t);

    t=min(t, maxb);

    while(k--)
    {
        for(int i=1; i<=n; ++i)
            scanf("%d", &v[i]);
        memset(d, 0, sizeof(d));
        sol=0;

        for(int p=1; p<=t; ++p)
            for(int i=1; i<=n; ++i)
            {
                d[v[i]]=max(d[v[i]], d[v[i]-1]+1);
                sol=max(sol, d[v[i]]);
                for(int j=v[i]+1; j<=maxb; ++j)
                    if(d[j]<d[v[i]])
                        d[j]=d[v[i]];
                    else
                        break;
            }
        printf("%d\n", sol);
    }

    return 0;
}