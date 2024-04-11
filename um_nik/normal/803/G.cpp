#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9 + 5;

struct Node
{
    int l, r;
    int val;
    int toPush;

    Node() : l(), r(), val(INF), toPush(-1) {}
    Node(int _l, int _r) : l(_l), r(_r), val(INF), toPush(-1) {}
};

const int N = 1 << 18;
Node tree[2 * N];
int a[N];
int n, k, m;
int q[N][4];
int xs[N];
int xsSz;

void build()
{
    for (int i = 0; i < N; i++)
        tree[N + i] = Node(i, i + 1);
    for (int i = N - 1; i > 0; i--)
        tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
    return;
}

void push(int v)
{
    if (v >= N) throw;
    if (tree[v].toPush == -1) return;
    for (int u = 2 * v; u < 2 * v + 2; u++)
    {
        tree[u].val = tree[v].toPush;
        tree[u].toPush = tree[v].toPush;
    }
    tree[v].toPush = -1;
    return;
}
void update(int v)
{
    if (v >= N) throw;
    tree[v].val = min(tree[2 * v].val, tree[2 * v + 1].val);
    return;
}

void setOnSegm(int v, int l, int r, int x)
{
    if (l <= tree[v].l && tree[v].r <= r)
    {
        tree[v].val = tree[v].toPush = x;
        return;
    }
    if (l >= tree[v].r || tree[v].l >= r) return;
    push(v);
    setOnSegm(2 * v, l, r, x);
    setOnSegm(2 * v + 1, l, r, x);
    update(v);
    return;
}

int getMin(int v, int l, int r)
{
    if (l <= tree[v].l && tree[v].r <= r)
        return tree[v].val;
    if (l >= tree[v].r || tree[v].l >= r)
        return INF;
    push(v);
    return min(getMin(2 * v, l, r), getMin(2 * v + 1, l, r));
}

int getCyclicMin(int l, int r)
{
    if (r - l >= n)
        return getMin(1, 0, n);
    l %= n;
    r %= n;
    if (l < r)
        return getMin(1, l, r);
    else
        return min(getMin(1, l, n), getMin(1, 0, r));
}

void read()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    build();
    for (int i = 0; i < n; i++)
        setOnSegm(1, i, i + 1, a[i]);
    scanf("%d", &m);
    xsSz = 0;
    xs[xsSz++] = 0;
    xs[xsSz++] = n * k;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &q[i][0], &q[i][1], &q[i][2]);
        if (q[i][0] == 1)
            scanf("%d", &q[i][3]);
        q[i][1]--;
        xs[xsSz++] = q[i][1];
        xs[xsSz++] = q[i][2];
    }
    sort(xs, xs + xsSz);
    xsSz = unique(xs, xs + xsSz) - xs;
    for (int i = 0; i < m; i++)
        for (int j = 1; j < 3; j++)
            q[i][j] = lower_bound(xs, xs + xsSz, q[i][j]) - xs;
    for (int i = 0; i < xsSz - 1; i++)
        a[i] = getCyclicMin(xs[i], xs[i + 1]);
    build();
    n = xsSz - 1;
    for (int i = 0; i < n; i++)
        setOnSegm(1, i, i + 1, a[i]);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();
    for (int i = 0; i < m; i++)
    {
        if (q[i][0] == 1)
            setOnSegm(1, q[i][1], q[i][2], q[i][3]);
        else
            printf("%d\n", getMin(1, q[i][1], q[i][2]));
    }

    return 0;
}