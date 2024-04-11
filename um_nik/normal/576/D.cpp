#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef unsigned int uint;

const int N = 152;
const int S = 5;
const int K = 32;
const int INF = (int)1e9 + 100000;

struct Bitset
{
    uint a[S];

    Bitset() : a() {}

    void setBit(int v)
    {
        a[v >> 5] |= (uint)1 << (v & 31);
    }

    bool getBit(int v)
    {
        return ((a[v >> 5]) >> (v & 31)) & 1;
    }
};

int n;

struct Matrix
{
    Bitset a[N], b[N];

    Matrix() : a(), b() {}

    void setOne(int x, int y)
    {
        a[x].setBit(y);
        b[y].setBit(x);
    }

    Matrix operator * (const Matrix &A) const
    {
        Matrix R = Matrix();
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
            {
                for (int i = 0; i < S; i++)
                    if (a[x].a[i] & A.b[y].a[i])
                    {
                        R.setOne(x, y);
                        break;
                    }
            }
        return R;
    }
};

struct Edge
{
    int v, u;
    int w;

    Edge() : v(), u(), w() {}

    void read()
    {
        scanf("%d%d%d", &v, &u, &w);
        v--;u--;
    }

    void print()
    {
        printf("(v = %d, to = %d, w = %d)\n", v, u, w);
    }

    bool operator < (const Edge &e) const
    {
        return w < e.w;
    }
};

Matrix bin_pow(const Matrix &A, int p)
{
    Matrix R = Matrix();
    for (int i = 0; i < n; i++)
        R.setOne(i, i);
    Matrix B = A;
    while(p > 0)
    {
        if (p & 1)
            R = R * B;
        B = B * B;
        p >>= 1;
    }
    return R;
}

int m;
int ans;
bool canGo[N];
bool newCanGo[N];
int dist[N];
bool g[N][N];
Edge ed[N];

void read()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        ed[i].read();
    sort(ed, ed + m);
    return;
}

int q[N];
int topQ;
void bfs(int T)
{
    topQ = 0;
    for (int v = 0; v < n; v++)
        dist[v] = INF;
    for (int v = 0; v < n; v++)
    {
        if (!canGo[v]) continue;
        dist[v] = T;
        q[topQ++] = v;
    }
    for (int k = 0; k < topQ; k++)
    {
        int v = q[k];
        for (int u = 0; u < n; u++)
        {
            if (!g[v][u]) continue;
            if (dist[u] <= dist[v] + 1) continue;
            dist[u] = dist[v] + 1;
            q[topQ++] = u;
        }
    }
    ans = min(ans, dist[n - 1]);
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    int T = 0;
    ans = INF;
    Matrix A = Matrix();
    canGo[0] = 1;
    for (int it = 0; ans > T && it < m; it++)
    {
//      printf("IT = %d\n", it);
        Edge e = ed[it];
//      e.print();
        Matrix R = bin_pow(A, e.w - T);
//      printf("Matrix:\n");
//      for (int i = 0; i < n; i++)
//          printf("%d\n", R.a[i].a[0]);
        for (int v = 0; v < n; v++)
            newCanGo[v] = 0;
        for (int v = 0; v < n; v++)
        {
            if (!canGo[v]) continue;
            for (int u = 0; u < n; u++)
                if (R.a[v].getBit(u))
                    newCanGo[u] = 1;
        }
        for (int v = 0; v < n; v++)
        {
            canGo[v] = newCanGo[v];
//          printf("canGo[%d] = %d\n", v, (int)canGo[v]);
        }
        g[e.v][e.u] = 1;
        A.setOne(e.v, e.u);
//      printf("Matrix A:\n");
//      for (int i = 0; i < n; i++)
//          printf("%d\n", A.a[i].a[0]);
        T = e.w;
        bfs(T);
    }
    if (ans == INF)
        printf("Impossible\n");
    else
        printf("%d\n", ans);

    return 0;
}