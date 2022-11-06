#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 200010

int n, rez, m, tot, nt, d[maxn], inv[maxn], f[maxn], w[maxn];
vector<int> sol, v[maxn], o[maxn];

void df1(int nod)
{
    f[nod]=1;
    int fiu;
    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];

        if(f[fiu])
            continue;

        df1(fiu);

        ++w[nod];
        w[nod]+=w[fiu];

        d[nod]+=d[fiu];
        d[nod]+=o[nod][i];

        inv[nod]+=inv[fiu];
        inv[nod]+=1-o[nod][i];
    }
}

void df2(int nod)
{
    f[nod]=1;
    int fiu;

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];

        if(f[fiu])
            continue;

        if(o[nod][i])
            --tot;
        else
            ++tot;

        df2(fiu);

        if(o[nod][i])
            ++tot;
        else
            --tot;
    }

    if(tot<rez)
    {
        rez=tot;
        sol.clear();
    }
    if(tot==rez)
        sol.push_back(nod);
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    int a, b;
    rez=n;
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b); o[a].push_back(0);
        v[b].push_back(a); o[b].push_back(1);
    }

    df1(1);
    memset(f, 0, sizeof(f));
    tot=d[1];
    df2(1);

    printf("%d\n", rez);
    sort(sol.begin(), sol.end());
    for(int i=0; i<sol.size(); ++i)
        printf("%d ", sol[i]);
    printf("\n");

    return 0;
}