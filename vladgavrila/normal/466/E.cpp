#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 100010
#define mlog 17

int n, m, nr;
int st[mlog][maxn], tp[mlog][maxn];
int tip[maxn], a[maxn], b[maxn], tr[maxn], f[maxn], h[maxn], wh[maxn], t[maxn];
vector<int> v[maxn];

void df(int nod)
{
    h[nod]=h[st[0][nod]]+1;

    for(int i=1; st[i-1][st[i-1][nod]]!=0; ++i)
    {
        st[i][nod]=st[i-1][st[i-1][nod]];
        tp[i][nod]=max(tp[i-1][nod], tp[i-1][st[i-1][nod]]);
    }

    for(int i=0; i<v[nod].size(); ++i)
        df(v[nod][i]);
}

int ask(int x, int y, int tm)
{
    int hx=h[x], hy=h[y];
    if(hx<hy)
        return 0;
    if(x==y)
        return 1;

    for(int i=mlog-1; i>=0; --i)
    {
        if(hx-(1<<i)<=hy)
            continue;
        hx-=(1<<i);
        if(tp[i][x]>tm)
            return 0;
        x=st[i][x];
    }

    if(tp[0][x]>tm)
        return 0;

    if(st[0][x]!=y)
        return 0;

    return 1;
}


int main()
{
    scanf("%d%d", &n, &m);

    for(int i=1; i<=m; ++i)
    {
        scanf("%d", &tip[i]);
        if(tip[i]==1)
        {
            scanf("%d%d", &a[i], &b[i]);
            st[0][a[i]]=b[i];
            tp[0][a[i]]=i;
            v[b[i]].push_back(a[i]);
        }
        else
        if(tip[i]==2)
        {
            scanf("%d", &a[i]);
            wh[++nr]=a[i];
            tr[nr]=i;
        }
        else
            scanf("%d%d", &a[i], &b[i]);
    }

    for(int i=1; i<=n; ++i)
        if(st[0][i]==0)
            df(i);

    for(int i=1; i<=m; ++i)
    {
        if(tip[i]<3)
            continue;
        if(tip[i]==3)
        {
            if(ask(wh[b[i]], a[i], tr[b[i]]))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}