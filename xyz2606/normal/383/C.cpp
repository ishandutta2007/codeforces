#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
struct recedge
{
    int y, next;
} edge[444444];
int n, m, ini[222222], x, y, dlt, query, l, len, idx[222222], bg[222222], ed[222222], dep[222222], bt[2][444444];
void build(int x, int y)
{
    edge[++l].next = idx[x];
    edge[l].y = y;
    idx[x] = l;
}
void dfs(int v)
{
    bg[v] = ++len;
    for(int p = idx[v]; p; p = edge[p].next) if(dep[edge[p].y] == -1)
    {
        dep[edge[p].y] = dep[v] ^ 1;
        dfs(edge[p].y);
    }
    ed[v] = ++len;
}
void inc(int * bt, int x, int dlt)
{
    for(int p = x; p <= 2 * n; p += (p & -p)) bt[p] += dlt;
}
int getsum(int * bt, int x)
{
    int rtn = 0;
    for(int p = x; p; p -= (p & -p)) rtn += bt[p];
    return rtn;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &ini[i]);
    l = 0 ;
    memset(idx, 0, sizeof(idx));
    len = 0;
    for(int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        build(x, y);
        build(y, x);
    }
    memset(dep, -1, sizeof(dep));
    dep[1] = 0;
    dfs(1);
    //for(int i = 1; i <= n; i++) printf("%d %d\n", bg[i], ed[i]);
    memset(bt, 0, sizeof(bt));
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &query);
        if(query == 1)
        {
            scanf("%d%d", &x, &dlt);
            inc(bt[dep[x]], bg[x], dlt);
            inc(bt[dep[x]], ed[x], -dlt);
        }else
        {
            scanf("%d", &x);
            printf("%d\n", ini[x] + getsum(bt[dep[x]], bg[x]) - getsum(bt[dep[x]^1], bg[x]));
        }
    }
    fclose(stdin);
    return 0;
}