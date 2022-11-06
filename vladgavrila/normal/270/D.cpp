#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 5010

int n, m, mx;
int v[maxn], d[maxn], aib[maxn];
double a;

inline int lsb(int x)
{
    return (x&(x-1))^x;
}

void update(int pz, int vl)
{
    while(pz<maxn)
    {
        aib[pz]=max(aib[pz], vl);
        pz+=lsb(pz);
    }
}

int query(int pz)
{
    int sol=0;
    while(pz)
    {
        sol=max(sol, aib[pz]);
        pz-=lsb(pz);
    }
    return sol;
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%lf", &v[i], &a);
        d[v[i]]=query(v[i]);
        ++d[v[i]];
        update(v[i], d[v[i]]);
        mx=max(mx, d[v[i]]);
    }

    printf("%d\n", n-mx);

    return 0;
}