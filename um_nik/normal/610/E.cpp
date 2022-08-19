#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int K = 10;
const int N = 1 << 18;
int n, k, m;
char s[N];

struct Node1
{
    int l, r;
    int c;
    int toC;

    Node1() : l(), r(), c(), toC() {}
    Node1(int _l, int _r) : l(_l), r(_r), c(0), toC(-1) {}
};
struct Node2
{
    int l, r;
    int a[K][K];
    int toX, toY;

    Node2() : l(), r(), a(), toX(), toY() {}
    Node2(int _l, int _r) : l(_l), r(_r), a(), toX(-1), toY(-1) {}
};

Node1 treeChar[2 * N];
Node2 treeVal[2 * N];

void pushChar(int v)
{
    if (v >= N) throw;
    if (treeChar[v].toC == -1) return;
    for (int i = 0; i < 2; i++)
    {
        int u = 2 * v + i;
        treeChar[u].c = treeChar[u].toC = treeChar[v].toC;
    }
    treeChar[v].toC = -1;
    return;
}
void pushVal(int v)
{
    if (v >= N) throw;
    if (treeVal[v].toX == -1) return;
    for (int i = 0; i < 2; i++)
    {
        int u = 2 * v + i;
        int len = treeVal[u].r - treeVal[u].l;
        for (int x = 0; x < k; x++)
            for (int y = 0; y < k; y++)
                treeVal[u].a[x][y] = 0;
        int x = treeVal[v].toX, y = treeVal[v].toY;
        treeVal[u].a[x][y] = len;
        treeVal[u].toX = x;
        treeVal[u].toY = y;
    }
    treeVal[v].toX = treeVal[v].toY = -1;
    return;
}
void updateVal(int v)
{
    if (v >= N) throw;
    for (int x = 0; x < k; x++)
        for (int y = 0; y < k; y++)
            treeVal[v].a[x][y] = treeVal[2 * v].a[x][y] + treeVal[2 * v + 1].a[x][y];
    return;
}

void buildTrees()
{
    for (int i = 0; i < N; i++)
    {
        treeChar[N + i] = Node1(i, i + 1);
        treeVal[N + i] = Node2(i, i + 1);
    }
    for (int i = N - 1; i > 0; i--)
    {
        treeChar[i] = Node1(treeChar[2 * i].l, treeChar[2 * i + 1].r);
        treeVal[i] = Node2(treeVal[2 * i].l, treeVal[2 * i + 1].r);
    }
    return;
}

void setCharOnSegm(int v, int l, int r, int c)
{
    if (l <= treeChar[v].l && treeChar[v].r <= r)
    {
        treeChar[v].c = treeChar[v].toC = c;
        return;
    }
    if (l >= treeChar[v].r || treeChar[v].l >= r)
        return;
    pushChar(v);
    for (int i = 0; i < 2; i++)
        setCharOnSegm(2 * v + i, l, r, c);
    return;
}
int getChar(int v, int p)
{
    while(v < N)
    {
        pushChar(v);
        v <<= 1;
        if (p >= treeChar[v].r) v++;
    }
    return treeChar[v].c;
}
int getChar(int p)
{
    return getChar(1, p);
}

void setValOnSegm(int v, int l, int r, int x, int y)
{
    if (l <= treeVal[v].l && treeVal[v].r <= r)
    {
//      printf("%d %d %d\n", v, x, y);
        treeVal[v].toX = x;
        treeVal[v].toY = y;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                treeVal[v].a[i][j] = 0;
        treeVal[v].a[x][y] = treeVal[v].r - treeVal[v].l;
//      printf("%d\n", treeVal[v].a[x][y]);
        return;
    }
    if (l >= treeVal[v].r || treeVal[v].l >= r)
        return;
    pushVal(v);
    for (int i = 0; i < 2; i++)
        setValOnSegm(2 * v + i, l, r, x, y);
    updateVal(v);
    return;
}

void read()
{
    buildTrees();

    scanf("%d%d%d", &n, &m, &k);
    scanf(" %s ", s);
    for (int i = 0; i < n; i++)
        setCharOnSegm(1, i, i + 1, (int)(s[i] - 'a'));
    for (int i = 0; i < n - 1; i++)
        setValOnSegm(1, i, i + 1, (int)(s[i] - 'a'), (int)(s[i + 1] - 'a'));
    /*
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%d ", treeVal[1].a[i][j]);
        }
        printf("\n");
    }
    */
    return;
}

void update()
{
    int l, r, c;
    char _c;
    scanf("%d %d %c", &l, &r, &_c);
    c = (int)(_c - 'a');
    l--;
    setCharOnSegm(1, l, r, c);
    setValOnSegm(1, l, r - 1, c, c);
    if (l != 0)
    {
        int cl = getChar(l - 1);
        setValOnSegm(1, l - 1, l, cl, c);
    }
    if (r != n)
    {
        int cr = getChar(r);
        setValOnSegm(1, r - 1, r, c, cr);
    }
    return;
}

void query()
{
    scanf(" %s ", s);
    int res = 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= i; j++)
        {
            int x = (int)(s[i] - 'a');
            int y = (int)(s[j] - 'a');
            res += treeVal[1].a[x][y];
        }
    printf("%d\n", res);
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();

    while(m--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
            update();
        else
            query();
    }

    return 0;
}