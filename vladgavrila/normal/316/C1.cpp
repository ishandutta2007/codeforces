#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define maxn 6500
#define maxx 85
#define maxm 55510
#define inf 2000000000

int n, m, nm, s, dst, ok, ftot, ctot;
int d[maxn], old[maxn], real[maxn], t[maxn], f[maxn], tm[maxn];
vector<int> v[maxn];
vector<pair<int, int> > h;
queue<int> q;
struct muchie
{
    int dest, cost, flux, cap, per;
} mc[maxm];
int vv[maxx][maxx];
const int d1[]={0, 0, -1, 1};
const int d2[]={1, -1, 0, 0};

void add_muchie(int a, int b, int c, int d)
{
  //  printf("%d %d %d %d\n", a, b, c, d);
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

void citire()
{
  //  freopen("c.in", "r", stdin);
  //  freopen("c.out", "w", stdout);

    int nn, mm;

    scanf("%d%d", &nn, &mm);
    s=1;
    dst=nn*mm+2;
    n=nn*mm+2;

    int a, b, c, dd, nx, ny;
    for(int i=1; i<=nn; ++i)
        for(int j=1; j<=mm; ++j)
            scanf("%d", &vv[i][j]);

    for(int i=1; i<=nn; ++i)
        for(int j=1; j<=mm; ++j)
            if((i+j)%2==0)
            {
                add_muchie(1, (i-1)*mm+j+1, 1, 0);
                for(int k=0; k<4; ++k)
                {
                    nx=i+d1[k];
                    ny=j+d2[k];
                    if(nx<=0 || ny<=0 || nx>nn || ny>mm)
                        continue;

                    if(vv[nx][ny]==vv[i][j])
                        add_muchie((i-1)*mm+j+1, (nx-1)*mm+ny+1, 1, 0);
                    else
                        add_muchie((i-1)*mm+j+1, (nx-1)*mm+ny+1, 1, 1);
                }
            }
            else
                 add_muchie((i-1)*mm+j+1, n, 1, 0);
}

void afisare()
{
    printf("%d\n", ctot);
}

int main()
{
    citire();

    bellmanford();

    while(dijkstra());

    afisare();

    return 0;
}