#include <cstdio>

using namespace std;

#define maxn 200010

int n, m, x, y, pz, ns;
int v[maxn], d[maxn], sa[maxn], sb[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
   // freopen("data.out", "w", stdout);
    
    scanf("%d%d%d%d", &n, &m, &x, &y);
    
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
    }
    
    pz=1;
    
    for(int i=1; i<=m; ++i)
    {
        scanf("%d", &d[i]);
        while(d[i]>v[pz]+y && pz<=n)
            ++pz;
        if(v[pz]-x<=d[i] && d[i]<=v[pz]+y && pz<=n)
        {
            sa[++ns]=pz;
            sb[ns]=i;
            ++pz;
        }
    }
    
    printf("%d\n", ns);
    
    for(int i=1; i<=ns; ++i)
        printf("%d %d\n", sa[i], sb[i]);
    
    return 0;
}