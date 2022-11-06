#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 300010

int n, m, q, tip, x, y, a, b;
int t[maxn], lp[maxn], f[maxn], c[maxn], lpc[maxn], d[maxn];
vector<int> v[maxn];

int tata(int nod)
{
    if(t[nod]==nod)
        return nod;

    int aux=tata(t[nod]);
    t[nod]=aux;
    return aux;
}

void df(int nod, int rad)
{
    if(f[nod])
        return;

    t[nod]=rad;

    f[nod]=1;
    int fiu;

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu])
            continue;

        df(fiu, rad);
        d[nod]=max(d[nod], d[fiu]+1);
    }
}

void df2(int nod, int rad, int up)
{
    if(f[nod]==2)
        return;

    f[nod]=2;
    int fiu, f1=0, f2=0;

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu]==2)
            continue;

        if(d[fiu]>d[f1])
        {
            f2=f1;
            f1=fiu;
        }
        else
        if(d[fiu]>d[f2])
        {
            f2=fiu;
        }
    }

 //   printf("%d %d %d %d %d\n", nod, f1, f2, d[f1], d[f2]);

    lp[rad]=max(lp[rad], d[f1]+d[f2]+2);
    if(up<lpc[rad] && d[nod]<lpc[rad])
    {
        lpc[rad]=max(up, d[nod]);
        c[rad]=nod;
    }

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu]==2)
            continue;

        if(fiu==f1)
            df2(fiu, rad, max(up, d[f2]+1)+1);
        else
            df2(fiu, rad, max(up, d[f1]+1)+1);
    }
}




int main()
{
  //  freopen("C.in", "r", stdin);
  //  freopen("c.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &q);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    d[0]=-1;

    for(int i=1; i<=n; ++i)
    {
        if(f[i]==0)
        {
            df(i, i);
            c[i]=i;
            lpc[i]=d[i];
            df2(i, i, 0);
        }
    }

    while(q--)
    {
        scanf("%d", &tip);
        if(tip==1)
        {
            scanf("%d", &x);
            printf("%d\n", lp[tata(x)]);
        }
        else
        {
            scanf("%d%d", &x, &y);
         //   printf("%d %d\n", x, y);

            x=tata(x);
            y=tata(y);

            if(x==y)
                continue;

            if(lpc[x]<lpc[y])
                swap(x, y);

            t[y]=x;

            if(lp[y]>lp[x])
                lp[x]=lp[y];

            if(lpc[y]+1+lpc[x]>lp[x])
                lp[x]=lpc[y]+1+lpc[x];

            if(lpc[x]==lpc[y])
                ++lpc[x];

         //   printf("%d %d %d\n", lp[x], lpc[x], c[x]);
        }
    }

    return 0;
}