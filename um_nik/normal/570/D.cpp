#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500200;
const int A = 26;
const int L = 19;

int oldp[N];
vector<int> g[N];
int par[N][L];
int p[N];
int n, m;
int dist[N];
int h[N];
int q[N];
int topQ;
int sum[A][N];
int hptr[N];
char s[N];

void bfs()
{
    for (int i = 0; i < n; i++)
        dist[i] = N;
    dist[0] = 0;
    q[topQ++] = 0;
    for (int k = 0; k < topQ; k++)
    {
        int v = q[k];
        for (int u : g[v])
        {
            dist[u] = dist[v] + 1;
            q[topQ++] = u;
        }
    }
    return;
}

void read()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        oldp[i] = x;
        g[x].push_back(i);
    }
    bfs();
    for (int i = 0; i < n; i++)
        p[q[i]] = i;
    for (int v = 0; v < n; v++)
        for (int i = 0; i < L; i++)
            par[v][i] = -1;
    for (int i = 1; i < n; i++)
        par[p[i]][0] = p[oldp[i]];
    for (int i = 0; i < n; i++)
        h[p[i]] = dist[i];
    for (int v = 1; v < n; v++)
    {
        for (int i = 1; i < L; i++)
        {
            par[v][i] = par[par[v][i - 1]][i - 1];
            if (par[v][i] == -1) break;
        }
    }
    for (int i = 0; i <= n; i++)
        hptr[i] = -1;
    for (int v = 0; v < n; v++)
    {
        if (hptr[h[v]] == -1)
            hptr[h[v]] = v;
    }
    hptr[h[n - 1] + 1] = n;
    scanf(" %s ", s);
    for (int i = 0; i < n; i++)
        sum[(int)(s[i] - 'a')][p[i] + 1]++;
    for (int a = 0; a < A; a++)
        for (int i = 1; i <= n; i++)
            sum[a][i] += sum[a][i - 1];
    return;
}

int up(int v, int dh)
{
    for (int k = L - 1; k >= 0; k--)
    {
        if (dh & (1 << k))
            v = par[v][k];
    }
    return v;
}

void query()
{
    int v, ht;
    scanf("%d%d", &v, &ht);
    v = p[v - 1];
    ht--;
    if (h[v] >= ht)
    {
        printf("Yes\n");
        return;
    }
    if (ht > h[n - 1])
    {
        printf("Yes\n");
        return;
    }
    int dh = ht - h[v];
    int l, r;
    int le = hptr[ht] - 1;
    int re = hptr[ht + 1];
    while(re - le > 1)
    {
        int u = (le + re) / 2;
        int w = up(u, dh);
        if (w < v)
            le = u;
        else
            re = u;
    }
    l = re;
    le = hptr[ht] - 1;
    re = hptr[ht + 1];
    while(re - le > 1)
    {
        int u = (le + re) / 2;
        int w = up(u, dh);
        if (w <= v)
            le = u;
        else
            re = u;
    }
    r = le + 1;
    if (r - l <= 1)
    {
        printf("Yes\n");
        return;
    }
    int cnt = 0;
    for (int a = 0; a < A; a++)
        if ((sum[a][r] - sum[a][l]) & 1)
            cnt++;
    if (cnt <= 1)
        printf("Yes\n");
    else
        printf("No\n");
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    
    read();
    while(m--)
        query();

    return 0;
}