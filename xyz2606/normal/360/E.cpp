#include<cstring>
#include<cstdio>
#include<algorithm>
#include<numeric>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<vector>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int n;
struct edge
{
    int y, next, p[2];
} edge[11111];
int s[2], t, m, k, l, v, d, y, x, z, w, idx[11111], ans[111], L;
long long dis[2][11111];
void build(int x, int y, int z, int w)
{
    edge[++l].y = y;
    edge[l].p[0] = z;
    edge[l].p[1] = w;
    edge[l].next = idx[x];
    idx[x] = l;
}
struct rechp
{
    int v, d;
    long long dis;
    rechp(int _v, const long long & _dis, int _d) : v(_v), dis(_dis), d(_d){}
};
bool operator < (const rechp & a, const rechp & b)
{return a.dis - b.dis?a.dis < b.dis:a.v - b.v?a.v < b.v:a.d < b.d;}
set<rechp> hp;
template<typename T> bool check(T cdt)
{
    
    for(int d = 0; d < 2; d++)
    {
        for(int i = 1; i <= n; i++) dis[d][i] = 0x3fffffffffffffffll;
        dis[d][s[d]] = 0;
        for(int i = 1; i <= n; i++) hp.insert(rechp(i, dis[d][i], d));
    }
    while(!hp.empty())
    {
        v = hp.begin()->v;
        d = hp.begin()->d;
        //for(set<rechp>::iterator itr = hp.begin(); itr != hp.end(); itr++) printf("%d %d ", itr->v, itr->d);
        //printf("\n");
        hp.erase(hp.begin());
        for(int p = idx[v]; p; p = edge[p].next)
        {
            L = edge[p].p[cdt(dis[1][v], dis[0][v])];
            if(p > m) ans[p - m] = L;
            if(dis[d][v] + L < dis[d][y = edge[p].y])
            {
                //printf("%d\n", hp.size());
                hp.erase(rechp(y, dis[d][y], d));
                //printf("%d\n", hp.size());
                dis[d][y] = dis[d][v] + L;
                hp.insert(rechp(y, dis[d][y], d));
                //printf("%d\n", hp.size());
                
            }
        }
    }
    //printf("%lld %lld\n", dis[0][t], dis[1][t]);
    return cdt(dis[0][t], dis[1][t]);
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    scanf("%d%d%d", &s[0], &s[1], &t);
    l = 0; memset(idx, 0, sizeof(idx));
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        build(x, y, z, z);
    }
    for(int i = 1; i <= k; i++)
    {
        scanf("%d%d%d%d", &x, &y, &z, &w);
        build(x, y, z, w);
    }
    
    if(check(less<long long>()))
    {
        printf("WIN\n");
        for(int i = 1; i <= k; i++) printf("%d%c", ans[i], i == k?'\n':' ');
    }else if(check(less_equal<long long>()))
    {
        printf("DRAW\n");
        for(int i = 1; i <= k; i++) printf("%d%c", ans[i], i == k?'\n':' ');
    }else
    {
        printf("LOSE\n");
    }
    fclose(stdin);
    return 0;
}