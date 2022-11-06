#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 500010

int n, m;
struct grip
{
    int x, y, m, r, p, dd;
    long long d;
} v[maxn];
int ind[maxn], ms[maxn], pz[maxn], f[maxn], q[maxn];
vector<int> st[maxn];

inline int cmp(int a, int b)
{
    return v[a].m<v[b].m;
}

inline int cmp2(int a, int b)
{
    return v[a].d<v[b].d;
}

inline int lsb(int x)
{
    return (x&(x-1))^x;
}

void update(int poz, int who)
{
    while(poz<=n+1)
    {
        st[poz].push_back(who);
        poz+=lsb(poz);
    }
}

void query(long long rg, int poz)
{
    while(poz)
    {
        while(pz[poz]<st[poz].size())
        {
         //   printf("%d %d\n", 1LL*rg*rg, st[poz][pz[poz]]);
            if(rg*rg<v[st[poz][pz[poz]]].d)
                break;
            if(f[st[poz][pz[poz]]]==0)
            {
                f[st[poz][pz[poz]]]=1;
                q[++q[0]]=st[poz][pz[poz]];
            }
            ++pz[poz];
        }
        poz-=lsb(poz);
    }
}

int main()
{
   // freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    scanf("%d%d%d%d%d", &v[0].x, &v[0].y, &v[0].p, &v[0].r, &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d%d%d%d", &v[i].x, &v[i].y, &v[i].m, &v[i].p, &v[i].r);
        v[i].d=(1LL*v[i].x-v[0].x)*(1LL*v[i].x-v[0].x)+(1LL*v[i].y-v[0].y)*(1LL*v[i].y-v[0].y);
        ind[i]=i;
    }

    sort(ind, ind+n+1, cmp);

    for(int i=0; i<=n; ++i)
    {
        ms[i]=v[ind[i]].m;
        if(v[ind[i]].m==v[ind[i-1]].m && i!=1)
            v[ind[i]].dd=v[ind[i-1]].dd;
        else
            v[ind[i]].dd=i;
    }

  //  for(int i=1; i<=n; ++i)
  //  {
  //      printf("%d %d %d\n", v[i].d, v[i].m, v[i].dd);
 //   }

    sort(ind, ind+n+1, cmp2);

    for(int i=1; i<=n; ++i)
        update(v[ind[i]].dd, ind[i]);

 /*   for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<st[i].size(); ++j)
            printf("%d ", st[i][j]);
        printf("\n");
    }*/

    q[++q[0]]=0;

  //  for(int i=1; i<=n; ++i)
    //    printf("%d\n", ms[i]);

    int wh;
    for(int i=1; i<=q[0]; ++i)
    {
        wh=int(upper_bound(ms+1, ms+n+1, v[q[i]].p)-(ms+1));
       // printf("%d %d\n", v[q[i]].p, ms[wh]);
        query(v[q[i]].r, wh);
    }

    printf("%d\n", q[0]-1);

    return 0;
}