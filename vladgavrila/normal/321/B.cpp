#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define maxn 210
#define maxm 35510
#define inf 2000000000

int n, m, nn, sol, nm, s, kk, dst, ok, ftot, ctot;
int d[maxn], old[maxn], real[maxn], t[maxn], f[maxn], tm[maxn];
vector<int> v[maxn];
vector<pair<int, int> > h;
queue<int> q;
struct muchie
{
    int dest, cost, flux, cap, per;
} mc[maxm];
string ss;
int tip[maxn], vl[maxn], x[maxn];
int na, nd, pa[maxn], pd[maxn];

void add_muchie(int a, int b, int c, int d)
{
    ++nm;
    v[a].push_back(nm);
    mc[nm].cost=d;
    mc[nm].cap=c;
    mc[nm].per=nm+1;
    mc[nm].dest=b;

    ++nm;
    v[b].push_back(nm);
    mc[nm].cost=-d;
    mc[nm].cap=0;
    mc[nm].per=nm-1;
    mc[nm].dest=a;
}

int dijkstra()
{
    int nod, fiu, cc, cost, cnou, mcc;

    for(int i=1; i<=n; ++i)
    {
        d[i]=inf;
        t[i]=0;
    }

    d[s]=0;
    h.clear();
    h.push_back(make_pair(0, s));
    push_heap(h.begin(), h.end());

    while(!h.empty())
    {
        cc=-h[0].first;
        nod=h[0].second;

        pop_heap(h.begin(), h.end());
        h.pop_back();

        if(cc!=d[nod])
            continue;

        for(int i=0; i<v[nod].size(); ++i)
        {
            mcc=v[nod][i];
            fiu=mc[mcc].dest;
            cost=mc[mcc].cost;

            if(mc[mcc].cap>mc[mcc].flux)
            {
                cnou=d[nod]+cost+old[nod]-old[fiu];
                if(cnou<d[fiu])
                {
                    d[fiu]=cnou;
                    real[fiu]=real[nod]+cost;
                    t[fiu]=nod;
                    tm[fiu]=mcc;
                    h.push_back(make_pair(-d[fiu], fiu));
                    push_heap(h.begin(), h.end());
                }
            }
        }
    }

    for(int i=1; i<=n; ++i)
        old[i]=real[i];

    if(d[dst]==inf)
        return 0;

    int mn=inf, ctt=0;

    for(int nod=dst; nod!=s; nod=t[nod])
    {
        mn=min(mn, mc[tm[nod]].cap-mc[tm[nod]].flux);
        ctt+=mc[tm[nod]].cost;
    }

    ftot+=mn;
    ctot+=mn*ctt;

    for(int nod=dst; nod!=s; nod=t[nod])
    {
        mc[tm[nod]].flux+=mn;
        mc[mc[tm[nod]].per].flux-=mn;
    }

    return 1;
}

void bellmanford()
{
    for(int i=1; i<=n; ++i)
        old[i]=inf;

    q.push(s);
    old[s]=0;
    f[s]=1;

    int nod, fiu, cost, mcc;

    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(int i=0; i<v[nod].size(); ++i)
        {
            mcc=v[nod][i];
            fiu=mc[v[nod][i]].dest;
            cost=mc[v[nod][i]].cost;
            if(old[nod]+cost<old[fiu] && mc[mcc].cap>mc[mcc].flux)
            {
                old[fiu]=old[nod]+cost;
                if(f[fiu]==0)
                {
                    f[fiu]=1;
                    q.push(fiu);
                }
            }
        }
        f[nod]=0;
    }
}


int main()
{
 //   freopen("b.in", "r", stdin);
 //   freopen("b.out", "w", stdout);

    cin>>nn>>m;
    for(int i=1; i<=nn; ++i)
    {
        cin>>ss;
        if(ss=="DEF")
            tip[i]=1;
        cin>>vl[i];
        add_muchie(1+m+i, 2+nn+m, 1, 0);
    }

    for(int i=1; i<=m; ++i)
    {
        cin>>kk;
        x[i]=kk;
        add_muchie(1, 1+i, 1, 0);
        for(int j=1; j<=nn; ++j)
        {
            if(tip[j]==1)
                continue;
            if(kk>=vl[j])
                add_muchie(1+i, 1+m+j, 1, vl[j]-kk);
        }
    }

    add_muchie(2+nn+m, 3+nn+m, m, 0);
    add_muchie(1, 2+nn+m, m, 0);

    n=3+nn+m;
    s=1;
    dst=n;

    while(dijkstra());

    sol=-ctot;

    ctot=0;
    for(int i=1; i<=nn; ++i)
    {
        if(tip[i]==0)
            pa[++na]=vl[i];
        else
            pd[++nd]=vl[i];
    }

    sort(x+1, x+m+1);
    sort(pd+1, pd+nd+1);
    sort(pa+1, pa+na+1);

    for(int i=1; i<=nd; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(x[j]>pd[i] && f[j]==0)
            {
                f[j]=1;
                break;
            }
            if(j==m)
            {
                printf("%d\n", sol);
                return 0;
            }
        }

    for(int i=1; i<=na; ++i)
        for(int j=1; j<=m; ++j)
        {
            if(x[j]>=pa[i] && f[j]==0)
            {
                f[j]=1;
                ctot+=x[j]-pa[i];
                break;
            }
            if(j==m)
            {
                printf("%d\n", sol);
                return 0;
            }
        }

    for(int i=1; i<=m; ++i)
        if(f[i]==0)
            ctot+=x[i];

    printf("%d\n", max(sol, ctot));

    return 0;
}