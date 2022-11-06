#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define maxn 100010
#define inf 1000010

int pas, a, b, n, m, bt, up, bbd;
int f[maxn], d[maxn], dfm[maxn];
char sol[maxn], csol[maxn];
vector<int> v[maxn];

void df(int nod)
{
    int fiu;

  //  printf("%d\n", nod);

    f[nod]=pas;
    dfm[nod]=0;
    d[nod]=1;
    ++csol[nod];

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu]==pas || sol[fiu]!=0)
            continue;
        df(fiu);
        dfm[nod]=max(dfm[nod], d[fiu]);
        d[nod]+=d[fiu];
    }
}

void df2(int nod)
{
    int sf=0, fiu;

    f[nod]=pas;

    if(max(up, dfm[nod])<bbd)
    {
        bt=nod;
        bbd=max(up, dfm[nod]);
    }

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu]==pas || sol[fiu]!=0)
            continue;
        sf+=d[fiu];
    }

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu]==pas || sol[fiu]!=0)
            continue;

        up+=sf-d[fiu]+1;
        df2(fiu);
        up-=(sf-d[fiu]+1);
    }
}

void solve(int rad)
{
    ++pas;
    df(rad);
    ++pas;

    bt=rad;
    bbd=dfm[rad];
    up=0;
    df2(rad);

 //   printf("%d\n", bt);

    sol[bt]=csol[bt]-1+'A';
}

int main()
{
 //   freopen("c.in", "r", stdin);
//    freopen("c.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; ++i)
        csol[i]=0;

    for(int i=1; i<=n; ++i)
    {
        if(sol[i])
            continue;

        solve(i);
        --i;
    }

    for(int i=1; i<=n; ++i)
        printf("%c ", sol[i]);
    printf("\n");

    return 0;
}