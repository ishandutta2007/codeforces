#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define maxn 200010

int l[maxn], niv[maxn], d[maxn], tl[maxn], fls[maxn], fol[maxn], sol[maxn], mt[maxn];
int nl, n, m, x, y;
vector<int> v[maxn], w[maxn];

void df(int nod)
{
    fol[nod]=1;
    d[nod]=1;
    if((v[nod].size()==1 && nod!=1) || (nod==1 && n==1))
    {
        l[nod]=++nl;
        return;
    }

    int fmax, it, dmax=0;

    for(int i=0; i<v[nod].size(); ++i)
    {
        it=v[nod][i];
        if(fol[it])
            continue;
        mt[it]=w[nod][i];
        niv[it]=niv[nod]+1;
        df(it);
        d[nod]+=d[it];
        if(d[it]>dmax)
        {
            dmax=d[it];
            fmax=(it);
        }
        tl[l[it]]=nod;
    }

    l[nod]=l[fmax];
}

int solve(int x, int y)
{
    while(l[x]!=l[y])
    {
        if(niv[tl[l[x]]]>niv[tl[l[y]]])
            x=tl[l[x]];
        else
            y=tl[l[y]];
    }

    if(niv[x]<niv[y])
        return x;
    return y;
}

void dfsolve(int nod)
{
    int it;
    fol[nod]=1;
    for(int i=0; i<v[nod].size(); ++i)
    {
        it=v[nod][i];
        if(fol[it])
            continue;
        dfsolve(it);
        fls[nod]+=fls[it];
    }
    sol[mt[nod]]=fls[nod];
}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=2; i<=n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
        w[a].push_back(i);
        w[b].push_back(i);
    }

    niv[1]=1;
    df(1);
    tl[l[1]]=0;

    scanf("%d", &m);

    while(m--)
    {
        scanf("%d%d", &x, &y);
        ++fls[x];
        ++fls[y];
        fls[solve(x, y)]-=2;
    }

    memset(fol, 0, sizeof(fol));
    dfsolve(1);

    for(int i=2; i<=n; ++i)
        printf("%d ", sol[i]);
    printf("\n");

    return 0;
}