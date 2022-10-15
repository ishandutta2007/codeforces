#include<cstring>

#include<cstdio>

#include<vector>

#include<set>

#include<map>

#include<algorithm>

#include<string>

#include<cstdlib>

using namespace std;
int n, m, k, l, idx[111111], cl, v, p, x, y, fv[111111], gv[111111], hv[111111], fp[111111], ans;
bool f[111111], vis[111111];
struct recedge
{
    int y, next;
} edge[222222];
struct recq
{
    int v, p;
} q[111111];
void build(int x, int y)
{
    edge[++l].y = y;
    edge[l].next = idx[x];
    idx[x] = l;
}

int main()

{

    scanf("%d%d%d", &n, &m, &k);
    l = 0;
    memset(idx, 0, sizeof(idx));
    if(m == 0)
    {
        printf("0\n");
        return 0;
    }
    memset(f, false, sizeof(f));
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        f[x] = true;
    }
    for(int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        build(x, y);
        build(y, x);
    }
    q[cl = 1].v = 1;
    q[1].p = idx[1];
    memset(vis, false, sizeof(vis));
    memset(fv, -1, sizeof(fv));
    memset(gv, -1, sizeof(gv));
    vis[1] = true;
    while(cl)
    {
        v = q[cl].v;
        q[cl].p = edge[p = q[cl].p].next;
        if(p)
        {
            if(vis[edge[p].y] == false)
            {
                q[++cl].v = edge[p].y;
                q[cl].p = idx[edge[p].y];
                vis[edge[p].y] = true;
            }
        }else
        {
            if(fv[v] == -1 and f[v] == true)
            {
                fv[v] = 0;
            }
            //printf("v = %d fv = %d gv = %d fp = %d\n", v, fv[v], gv[v], fp[v]);
            if(fv[v] != -1)
            {   
                if(fv[v] + 1 > fv[q[cl - 1].v])
                {
                    gv[q[cl - 1].v] = fv[q[cl - 1].v];
                    fv[q[cl - 1].v] = fv[v] + 1;
                    fp[q[cl - 1].v] = v;
                }else if(fv[v] + 1 > gv[q[cl - 1].v])
                {
                    gv[q[cl - 1].v] = fv[v] + 1;
                }else if(gv[v] != -1)
                {
                    if(gv[v] + 1 > gv[q[cl - 1].v])
                    {
                        gv[q[cl - 1].v] = gv[v] + 1;
                    }
                }
            }
            cl--;
        }
    }

    q[cl = 1].v = 1;
    q[1].p = idx[1];
    memset(vis, false, sizeof(vis));
    memset(hv, -1, sizeof(hv));
    vis[1] = true;
    while(cl)
    {
        v = q[cl].v;
        q[cl].p = edge[p = q[cl].p].next;
        if(p)
        {
            if(vis[edge[p].y] == false)
            {
                q[++cl].v = edge[p].y;
                q[cl].p = idx[edge[p].y];
                vis[edge[p].y] = true;
                if(f[v]) hv[edge[p].y] = 1;
                if(hv[v] != -1) hv[edge[p].y] = hv[v] + 1;
                if(fv[v] != -1)
                {
                    if(fp[v] == edge[p].y)
                    {
                        if(gv[v] != -1 and hv[edge[p].y] < gv[v] + 1)
                        {
                            hv[edge[p].y] = gv[v] + 1;
                        }
                    }else
                    {
                        hv[edge[p].y] = max(hv[edge[p].y], fv[v] + 1);
                    }
                }
                //printf("hv[%d] = %d\n",edge[p].y, hv[edge[p].y]);
            }
        }else
        {
            cl--;
        }
    }
    ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(max(hv[i], fv[i]) <= k) ans++;
    }
    printf("%d\n", ans);

    fclose(stdin);

    return 0;

}