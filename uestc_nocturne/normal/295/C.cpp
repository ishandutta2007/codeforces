/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V = 6000;
const int En = 1000 * V;
const int oo = 1000000000;
const int P = 1000000007;
struct Edge{int num, ne, way;}e[En];
int p[V], K;
void add(int x, int y, int z)
{
    e[K].num = y;
    e[K].way = z;
    e[K].ne = p[x];
    p[x] = K++;
}
int get(int x, int y, int z)
{
    return (x * 51 + y) * 2 +z;
}
int q[V], vis[V], d[V], st, ed, N, dp[V];
int dfs(int u)
{
    if(vis[u] == 1)
        return dp[u];
    vis[u] = 1;
    dp[u] = 0;
    for(int i = p[u]; i != -1; i = e[i].ne)
    {
        int v = e[i].num;
        if(d[u] + 1 == d[v])
        {
            dp[u] += (LL)e[i].way * dfs(v) %P;
            dp[u] %= P;
        }
    }
    return dp[u];
}
void bfs()
{
    for(int i = 0; i < N; i++)
    {
        vis[i] = 0;
        d[i] = oo;
    }
    vis[st] = 1;
    d[st] = 0;
    int top = 0, tail = 1;
    q[1] = st;
    while(top != tail)
    {
        top++;
        int u = q[top];
        for(int i = p[u]; i != -1; i = e[i].ne)
        {
            int v = e[i].num;
            if(!vis[v])
            {
                vis[v] = 1;
                d[v] = d[u] + 1;
                tail++;
                q[tail] = v;
            }
        }
    }
    if(d[ed] == oo)
    {
        puts("-1");
        puts("0");
        return;
    }
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    vis[ed] = 1;
    dp[ed] = 1;
    printf("%d\n", d[ed]);
    printf("%d\n", dfs(st));
}
int C[70][70], n, S, x;
int main()
{
    for(int i = 0; i < 60; i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
        C[i][j] = (C[i-1][j-1] + C[i-1][j])%P;
    }
    while(~scanf("%d%d", &n, &S))
    {
        int n5 = 0;
        int n1 = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if(x == 50) n5++;
            else n1++;
        }
        N = 51 * 51 * 2;
        st = get(n5, n1, 0);
        ed = get(0, 0, 1);
        memset(p, -1, sizeof(p));
        K = 0;
        for(int i = 0; i <= n5; i++)
        for(int j = 0; j <= n1; j++)
        for(int k = 0; k < 2; k++)
        {
            int r5 = i;
            int r1 = j;
            if(k == 1)
            {
                r5 = n5 - r5;
                r1 = n1 - r1;
            }
            int tk = 1 - k;
            for(int ii = 0; ii <= r5; ii++)
            for(int jj = 0; jj <= r1; jj++)
            {
                if(ii == 0 && jj == 0)continue;
                if(ii * 50 + jj * 100 > S)continue;
                int way = (LL)C[r5][ii] * C[r1][jj] % P;
                int ti = r5 - ii;
                int tj = r1 -jj;
                if(k == 1)
                {
                    ti = n5 - ti;
                    tj = n1 - tj;
                }
                add(get(i, j, k), get(ti, tj, tk), way);
            }
        }
        bfs();
    }
}