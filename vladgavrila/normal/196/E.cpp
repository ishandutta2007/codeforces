#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define maxn 100010
#define inf (1LL*1000000000*10000000)

int n, k, m, nm;
char f[maxn];
int t[maxn], p[maxn];
long long sol, d[maxn];
vector<int> v[maxn], w[maxn];
pair<long long, pair<int, int> > l[maxn];
set<pair<long long, int> > g;

int tata(int nod)
{
    if(t[nod]==nod)
        return nod;
    int aux=tata(t[nod]);
    t[nod]=aux;
    return aux;
}

int main()
{
 //   freopen("data.in", "r", stdin);
   // freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);

    int a, b, c;
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        v[a].push_back(b);
        w[a].push_back(c);
        v[b].push_back(a);
        w[b].push_back(c);
    }

    for(int i=1; i<=n; ++i)
    {
        t[i]=i;
        d[i]=inf;
    }

    scanf("%d", &k);
    for(int i=1; i<=k; ++i)
    {
   //     printf("*");
        scanf("%d", &a);
        d[a]=0;
        p[a]=a;
        g.insert(make_pair(0LL, a));
    }

    int nod, fiu;
    while(!g.empty())
    {
        nod=g.begin()->second;
        g.erase(g.begin());

        if(f[nod])
            continue;

        f[nod]=1;
        for(int i=0; i<v[nod].size(); ++i)
        {
            fiu=v[nod][i];
            if(f[fiu]==0 && d[nod]+w[nod][i]<d[fiu])
            {
                g.erase(make_pair(d[fiu], fiu));
                d[fiu]=d[nod]+w[nod][i];
                p[fiu]=p[nod];
                g.insert(make_pair(d[fiu], fiu));
            }
        }
    }

    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<v[i].size(); ++j)
        {
            fiu=v[i][j];
            if(fiu<i && p[fiu]!=p[i])
                l[++nm]=make_pair(w[i][j]+d[fiu]+d[i], make_pair(p[i], p[fiu]));
        }
    }

    sort(l+1, l+nm+1);

    for(int i=1; i<=nm; ++i)
    {
        a=l[i].second.first;
        b=l[i].second.second;
        if(tata(a)!=tata(b))
        {
            sol+=l[i].first;
            t[tata(a)]=tata(b);
        }
    }

    printf("%I64d\n", sol+d[1]);

    return 0;
}