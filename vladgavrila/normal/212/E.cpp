#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define maxn 5010

int n, m;
vector<int> v[maxn];
char f[maxn], d[maxn], sol[maxn];
int w[maxn], st[maxn];

void df(int nod)
{
    int fiu;
    if(f[nod])
        return;

    f[nod]=1;
    w[nod]=1;

    int tt=0, st0=0;

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu])
        {
            tt=fiu;
            continue;
        }
        df(fiu);
        w[nod]+=w[fiu];
    }
    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(tt==fiu)
            continue;
        st[++st0]=w[fiu];
    }
    st[++st0]=n-w[nod];

    memset(d, 0, sizeof(d));

    d[0]=1;

  //  printf("%d %d\n", nod, w[nod]);
    for(int i=1; i<=st0; ++i)
    {
    //    printf("%d\n", st[i]);
        for(int j=n-2; j>=st[i]; --j)
            d[j]=d[j]|d[j-st[i]];
    }

    for(int i=1; i<n-1; ++i)
    {
    //    printf("%d ", d[i]);
        sol[i]=sol[i]|d[i];
    }
   // printf("\n\n");
}

int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);

    scanf("%d", &n);
    int a, b;
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    df(1);

    int nsol=0;

    for(int i=1; i<n-1; ++i)
        if(sol[i])
            ++nsol;

    printf("%d\n", nsol);
    for(int i=1; i<n-1; ++i)
        if(sol[i])
            printf("%d %d\n", i, n-i-1);

    return 0;
}