#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define maxn 200010

int n, m, q0, rad, ut[maxn];
int f[maxn], g[maxn], d[maxn], ml[maxn], sml[maxn], wml[maxn], sol, ssol, q[maxn], p[maxn];
vector<int> v[maxn];

void df1(int nod)
{
    if(f[nod])
        return;

    f[nod]=1;
    int fiu;

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu]==1 || ut[fiu]==1)
            continue;

        df1(fiu);

        d[nod]=max(d[nod], d[fiu]+1);
        if(d[fiu]+1>ml[nod])
        {
            sml[nod]=ml[nod];
            ml[nod]=d[fiu]+1;
            wml[nod]=fiu;
        }
        else
        if(d[fiu]+1>sml[nod])
            sml[nod]=d[fiu]+1;
    }
}

void df2(int nod, int up)
{
    if(f[nod])
        return;

    f[nod]=1;
    int fiu;

    if(up>sol)
    {
        sol=up;
        ssol=n+1;
    }
    if(ml[nod]>sol)
    {
        sol=ml[nod];
        ssol=n+1;
    }

    if((up==sol || ml[nod]==sol)&& nod<ssol)
        ssol=nod;


    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu]==1 || ut[fiu]==1)
            continue;

        if(wml[nod]==fiu)
            df2(fiu, max(up, sml[nod])+1);
        else
            df2(fiu, max(up, ml[nod])+1);
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=1; i<n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
        ++g[a];
        ++g[b];
    }

    for(int i=1; i<=m; ++i)
    {
        int x;
        scanf("%d", &x);
        p[x]=1;
    }

    for(int i=1; i<=n; ++i)
        if(g[i]==1 && p[i]!=1)
        {
            q[++q0]=i;
            ut[i]=1;
        }

    for(int i=1; i<=q0; ++i)
    {
        int nod=q[i];
        for(int j=0; j<v[nod].size(); ++j)
        {
            int fiu=v[nod][j];
            --g[fiu];
            if(g[fiu]==1 && p[fiu]!=1 && ut[fiu]!=1)
            {
                ut[fiu]=1;
                q[++q0]=fiu;
            }
        }
    }

    rad=1;
    while(ut[rad])
        rad++;

    df1(rad);
    memset(f, 0, sizeof(f));
    ssol=n+1;
    df2(rad, 0);

    printf("%d\n%d\n", ssol, (n-1-q0)*2-sol);

    return 0;
}