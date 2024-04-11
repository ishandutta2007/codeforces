#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define maxn 100010

int n, r;
int t[maxn], f[maxn];
long long d[maxn];
int c[maxn];
vector<int> v[maxn];
multiset<long long> g;

void df(int nod)
{
    f[nod]=1;
    int fiu;

    if(c[nod]==-1)
        return;

    if(nod!=r)
        d[nod]=1;

 //   printf("!%d %d\n", nod, c[nod]);

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(fiu==t[nod])
            continue;
        t[fiu]=nod;
        df(fiu);
    }

   // printf("%d %d\n\n", nod, c[nod]);

    g.clear();

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(fiu==t[nod])
            continue;
        if(d[fiu]>0)
            g.insert(d[fiu]);
        if(g.size()>c[nod])
            g.erase(g.begin());
    }

    for(multiset<long long> :: iterator it = g.begin(); it!=g.end(); ++it)
    {
      //  printf("*");
        d[nod]+=(*it)+1;
        --c[nod];
    }

   // printf("%d %d\n", nod, d[nod]);

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(fiu==t[nod])
            continue;
        d[nod]+=2*min(c[nod], c[fiu]);
        c[nod]-=min(c[nod], c[fiu]);
    }
  //  printf("%d %d %d\n\n", nod, d[nod], c[nod]);
}

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &c[i]);
        --c[i];
    }

    int a, b;
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    scanf("%d", &r);

    ++c[r];
    df(r);

    printf("%I64d\n", d[r]);

    return 0;
}