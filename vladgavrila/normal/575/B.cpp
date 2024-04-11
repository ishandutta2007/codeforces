#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define maxn 100010
#define mlog 20
#define maxm 1000010
#define mod 1000000007

int n, m, sol;
int st[mlog][maxn], ts[maxn], ds[maxn], dj[maxn], niv[maxn];
int a[maxn], b[maxn], x[maxn], f[maxn];
int p2[maxm];
vector<int> v[maxn];

void df(int nod, int t)
{
    st[0][nod]=t;
    niv[nod]=niv[t]+1;

    for(int i=1; st[i-1][st[i-1][nod]]!=0; ++i)
        st[i][nod]=st[i-1][st[i-1][nod]];

    int fiu, mc;
    f[nod]=1;

    for(int i=0; i<v[nod].size(); ++i)
    {
        mc=v[nod][i];
        if(a[mc]==nod)
        {
            fiu=b[mc];
            if(f[fiu])
                continue;
            if(x[mc]==1)
                ts[fiu]=1;
        }
        else
        {
            fiu=a[mc];
            if(f[fiu])
                continue;
            if(x[mc]==1)
                ts[fiu]=2;
        }
        df(fiu, nod);
    }
}

void df2(int nod)
{
    int fiu, mc;
    f[nod]=1;

    for(int i=0; i<v[nod].size(); ++i)
    {
        mc=v[nod][i];
        if(a[mc]==nod)
        {
            fiu=b[mc];
            if(f[fiu])
                continue;
        }
        else
        {
            fiu=a[mc];
            if(f[fiu])
                continue;
        }
        df2(fiu);
        ds[nod]+=ds[fiu];
        dj[nod]+=dj[fiu];
    }

   // printf("%d %d %d\n", nod, ds[nod], dj[nod]);

    if(ts[nod]==2)
        sol=(1LL*sol+p2[dj[nod]]-1+mod)%mod;
    if(ts[nod]==1)
        sol=(1LL*sol+p2[ds[nod]]-1+mod)%mod;
}


int lca(int x, int y)
{
    if(niv[x]<niv[y])
        swap(x, y);

    for(int i=mlog-1; i>=0; --i)
        if(niv[st[i][x]]>=niv[y])
            x=st[i][x];

    if(x==y)
        return x;

    for(int i=mlog-1; i>=0; --i)
        if(st[i][x]!=st[i][y])
        {
            x=st[i][x];
            y=st[i][y];
        }

    return st[0][x];
}

int main()
{
   // freopen("b.in", "r", stdin);

    scanf("%d", &n);

    for(int i=1; i<n; ++i)
    {
        scanf("%d%d%d", &a[i], &b[i], &x[i]);
        v[a[i]].push_back(i);
        v[b[i]].push_back(i);
    }

    df(1, 0);

    int prev=1, ss, xx;

    scanf("%d", &m);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d", &xx);

        ss=lca(prev, xx);

        ds[prev]++;
        ds[ss]--;
        dj[xx]++;
        dj[ss]--;

      //  printf("%d %d %d\n", prev, ss, xx);

        prev=xx;
    }
    p2[0]=1;
    for(int i=1; i<=m+1; ++i)
        p2[i]=(2LL*p2[i-1])%mod;
    memset(f, 0, sizeof(f));
    df2(1);



    printf("%d\n", sol);

    return 0;
}