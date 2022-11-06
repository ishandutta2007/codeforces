#include <stdio.h>

using namespace std;

#define maxn 100010

int n, m, i, j, k, a, b, sol, nod, dest, nr;
int next[maxn], cost[maxn], v[maxn], dist[maxn], f[maxn], coa[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &next[i]);
        cost[i]=1;
    }
    for(int i=1; i<=m; ++i)
        scanf("%d", &v[i]);
    for(int j=1; j<=m; ++j)
    {
        a=((v[j]+sol-1)%n)+1;
        sol=0;
       // printf("%d\n", a);
        scanf("%d", &b);
        b--;
        coa[0]=1;
        coa[1]=a;
        dist[a]=0;
        for(int i=1; i<=coa[0]; ++i)
        {
            nod=coa[i];
            if(f[nod]==0)
                sol++;
            f[nod]=j;
         //   printf("%d %d\n", nod, dist[nod]);
            if(b<cost[nod] || f[next[nod]]==j)
                break;
            coa[++coa[0]]=next[nod];
            dist[next[nod]]=dist[nod]+cost[nod];
            b-=cost[nod];
        }
        dest=next[nod];
        nr=coa[0];
        //printf("%d\n", nr);
        for(int i=1; i<coa[0]; ++i)
        {
            next[coa[i]]=dest;
            cost[coa[i]]=cost[coa[nr]]+dist[coa[nr]]-dist[coa[i]];
        }
        printf("%d\n", sol);
    }
    return 0;
}