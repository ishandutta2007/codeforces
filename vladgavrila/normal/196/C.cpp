#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define maxn 1510

int n, m, a, b, xo, yo, t[maxn], d[maxn], f[maxn], sol[maxn];
vector<int> v[maxn];
pair<pair<int, int>, int> p[maxn];

void df(int nod)
{
    if(f[nod])
        return;

    f[nod]=1;
    d[nod]=1;

    int fiu;
    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(f[fiu])
        {
            t[nod]=fiu;
            continue;
        }
        df(fiu);
        d[nod]+=d[fiu];
    }
}

inline int cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    return (1LL*a.first.second-yo)*(1LL*b.first.first-xo)<(1LL*b.first.second-yo)*(1LL*a.first.first-xo);
}

void solve(int nod, int left, int right)
{
    sort(p+left, p+right+1);
    xo=p[left].first.first;
    yo=p[left].first.second;
    if(left!=right)
        sort(p+left+1, p+right+1, cmp);

    sol[p[left].second]=nod;

    int fiu, pz=left+1;
    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(fiu==t[nod])
            continue;
        solve(fiu, pz, pz+d[fiu]-1);
        pz+=d[fiu];
    }
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    df(1);

    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &p[i].first.first, &p[i].first.second);
        p[i].second=i;
    }

    solve(1, 1, n);

    for(int i=1; i<=n; ++i)
        printf("%d ", sol[i]);
    printf("\n");

    return 0;
}