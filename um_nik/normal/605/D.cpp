#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int INF = (int)1e8;
const int N = 1 << 18;
int n;
int q[N];
int topQ;
int dist[N];
int par[N];
int a[N][4];
int xs[N];
int ans[N];

struct Node
{
    int l, r;
    set<pii> val;

    Node() : l(), r(), val() {}
    Node(int _l, int _r) : l(_l), r(_r), val() {}
};

Node tree[2 * N];

void read()
{
    int m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);
        xs[m++] = a[i][0];
        xs[m++] = a[i][2];
    }
    sort(xs, xs + m);
    m = unique(xs, xs + m) - xs;
    for (int i = 0; i < n; i++)
    {
        a[i][0] = lower_bound(xs, xs + m, a[i][0]) - xs;
        a[i][2] = lower_bound(xs, xs + m, a[i][2]) - xs;
    }
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    return;
}

void build()
{
//  cerr << "BUILD START\n";
    for (int i = 0; i < N; i++)
        tree[N + i] = Node(i, i + 1);
    for (int i = N - 1; i > 0; i--)
        tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
//  cerr << "BUILD END\n";
    return;
}

void addItem(int x, pii z)
{
    x += N;
    while(x > 0)
    {
        tree[x].val.insert(z);
        x >>= 1;
    }
    return;
}
void removeItem(int x, pii z)
{
    x += N;
    while(x > 0)
    {
        tree[x].val.erase(z);
        x >>= 1;
    }
    return;
}

void move(int v, int l, int r, int y, int p, int nd)
{
//  cerr << v << endl;
    if (l <= tree[v].l && tree[v].r <= r)
    {
        while(!tree[v].val.empty())
        {
            pii t = *tree[v].val.begin();
            if (t.first > y) break;
            int id = t.second;
            removeItem(a[id][0], t);
            dist[id] = nd;
            q[topQ++] = id;
            par[id] = p;
        }
        return;
    }
    if (tree[v].l >= r || l >= tree[v].r)
        return;
    move(2 * v, l, r, y, p, nd);
    move(2 * v + 1, l, r, y, p, nd);
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    build();
    for (int i = 0; i < n; i++)
        addItem(a[i][0], mp(a[i][1], i));
    move(1, 0, 1, 0, -1, 1);
    for (int i = 0; i < topQ; i++)
    {
//      cerr << i << endl;
        int id = q[i];
        move(1, 0, a[id][2] + 1, a[id][3], id, dist[id] + 1);
    }
    if (dist[n - 1] == INF)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", dist[n - 1]);
    int v = n - 1;
    while(v != -1)
    {
        ans[dist[v] - 1] = v + 1;
        v = par[v];
    }
    for (int i = 0; i < dist[n - 1]; i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}