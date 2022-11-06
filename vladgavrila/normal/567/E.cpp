#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

#define maxn 1000010
#define inf (1LL*1000000000*1000000)

int n, m, s, t;
long long ds[maxn], dt[maxn];
int f[maxn], q[maxn], q0;
int a[maxn], b[maxn], c[maxn];
int ans[maxn];
vector<int> v[maxn], vi[maxn];
vector<pair<long long, int> > h;

void dijkstra(int ss, long long d[], vector<int> v[])
{
    memset(f, 0, sizeof(f));

    h.clear();
    h.push_back(make_pair(0, ss));
    for(int i=1; i<=n; ++i)
        d[i]=inf;
    d[ss]=0;

    int nod, fiu;

    while(h.size()>0)
    {
        nod=h[0].second;
        pop_heap(h.begin(), h.end());
        h.pop_back();

        if(f[nod])
            continue;

        f[nod]=1;

        for(int i=0; i<v[nod].size(); ++i)
        {
            fiu=b[v[nod][i]];
            if(d[nod]+c[v[nod][i]]<d[fiu])
            {
                d[fiu]=d[nod]+c[v[nod][i]];
                h.push_back(make_pair(-d[fiu], fiu));
                push_heap(h.begin(), h.end());
            }
        }
    }
}

void bf()
{
    memset(f, 0, sizeof(f));
    h.clear();
    h.push_back(make_pair(0, s));

    int nod, fiu, mcc=0, pls=0, ok=0;
    f[s]=1;

    while(h.size()>0)
    {
        nod=h[0].second;
        pop_heap(h.begin(), h.end());
        h.pop_back();

        if(nod==t)
            break;

        if(h.size()==0)
        {
            ok=1;
            pls=0;
        }
        else
            ok=0;

        for(int i=0; i<v[nod].size(); ++i)
        {
            fiu=b[v[nod][i]];
            if(ds[nod]+c[v[nod][i]]+dt[fiu]==ds[t] )
            {
                if(f[fiu]==0)
                {
                    f[fiu]=1;
                    h.push_back(make_pair(-ds[fiu], fiu));
                    push_heap(h.begin(), h.end());
                }
                ++pls;
                mcc=v[nod][i];
            }
        }
        if(pls==1 && ok==1)
            ans[mcc]=-1;
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        v[a[i]].push_back(i);
        vi[b[i]].push_back(i);
    }

    dijkstra(s, ds, v);
    for(int i=1; i<=m; ++i)
        swap(a[i], b[i]);

    dijkstra(t, dt, vi);
    for(int i=1; i<=m; ++i)
        swap(a[i], b[i]);

    bf();

    for(int i=1; i<=m; ++i)
    {
        if(ds[a[i]] == inf || dt[b[i]] == inf)
        {
            printf("NO\n");
            continue;
        }

        if(ans[i]==-1)
        {
            printf("YES\n");
            continue;
        }

        long long dff = ds[t] - (ds[a[i]] + dt[b[i]]) - 1;

        if(dff<=0)
            printf("NO\n");
        else
            printf("CAN %d\n", int(c[i] - dff));
    }

    return 0;
}