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

typedef pair<int, int> pii;
#define mp make_pair

const int MOD = (int)1e9 + 7;
int add(int x, int y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}

const int N = 1 << 17;
int h, w, n;

struct Node
{
    int l, r;
    int val;

    Node() : l(), r(), val() {}
    Node(int _l, int _r) : l(_l), r(_r), val(-1) {}
};

struct Node2
{
    int l, r;
    vector<int> p;
    vector<Node> tree;

    Node2() : l(), r(), p(), tree() {}
    Node2(int _l, int _r) : l(_l), r(_r), p(), tree() {}

    void buildTree()
    {
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end()) - p.begin()); //???
        int m = (int)p.size();
        if (m == 0) return;
        while(m & (m - 1)) m++;
        tree.resize(2 * m);
        for (int i = 0; i < m; i++)
            tree[m + i] = Node(i, i + 1);
        for (int i = m - 1; i > 0; i--)
            tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
    }

    int getMax(int x)
    {
        int pt = lower_bound(p.begin(), p.end(), x) - p.begin();
        if (p[pt] != x) throw;
        x = pt + (int)tree.size() / 2;
        int res = -1;
        while(x > 0)
        {
            res = max(res, tree[x].val);
            x >>= 1;
        }
        return res;
    }

    void push(int v)
    {
        if (v >= (int)tree.size() / 2) throw;
        tree[2 * v].val = max(tree[2 * v].val, tree[v].val);
        tree[2 * v + 1].val = max(tree[2 * v + 1].val, tree[v].val);
        tree[v].val = -1;
        return;
    }

    void relaxMax(int v, int ll, int rr, int val)
    {
        if (ll <= tree[v].l && tree[v].r <= rr)
        {
            tree[v].val = max(tree[v].val, val);
            return;
        }
        if (ll >= tree[v].r || tree[v].l >= rr)
            return;
        push(v);
        relaxMax(2 * v, ll, rr, val);
        relaxMax(2 * v + 1, ll, rr, val);
        return;
    }
    void relaxMax(int ll, int rr, int val)
    {
        int ptl = lower_bound(p.begin(), p.end(), ll) - p.begin(), ptr = lower_bound(p.begin(), p.end(), rr) - p.begin();
        if (ptl >= ptr) return;
        relaxMax(1, ptl, ptr, val);
        return;
    }
};

Node2 tree[2 * N];

void build()
{
    for (int i = 0; i < N; i++)
        tree[N + i] = Node2(i, i + 1);
    for (int i = N - 1; i > 0; i--)
        tree[i] = Node2(tree[2 * i].l, tree[2 * i + 1].r);
    return;
}


struct Bound
{
    int y;
    int l, r;
    int s;
    
    Bound() : y(), l(), r(), s() {}

    void scan()
    {
        scanf("%d%d%d%d", &y, &l, &r, &s);
    }

    bool operator < (const Bound &B) const
    {
        return y < B.y;
    }
};

Bound bounds[N];
int dp[N][2];

void read()
{
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 0; i < n; i++)
        bounds[i].scan();
    sort(bounds, bounds + n);
    return;
}

void addPoint(int x, int y)
{
    x += N;
    while(x > 0)
    {
        tree[x].p.push_back(y);
        x >>= 1;
    }
    return;
}

int getMaxGlobal(int v, int x, int y)
{
    if (v >= 2 * N) return -1;
    if (tree[v].l > x || tree[v].r <= x)
        return -1;
    int res = tree[v].getMax(y);
    return max(res, max(getMaxGlobal(2 * v, x, y), getMaxGlobal(2 * v + 1, x, y)));
}

void relaxMaxGlobal(int v, int l, int r, int ly, int ry, int val)
{
    if (l <= tree[v].l && tree[v].r <= r)
    {
        tree[v].relaxMax(ly, ry, val);
        return;
    }
    if (l >= tree[v].r || tree[v].l >= r)
        return;
    relaxMaxGlobal(2 * v, l, r, ly, ry, val);
    relaxMaxGlobal(2 * v + 1, l, r, ly, ry, val);
    return;
}

int solvePoint(int x, int y)
{
    int v = getMaxGlobal(1, x, y);
    if (v == -1) return 1;
    if (dp[v][0] == -1)
        return add(dp[v][1], dp[v][1]);
    if (dp[v][1] == -1)
        return add(dp[v][0], dp[v][0]);
    return add(dp[v][0], dp[v][1]);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();
    build();
    for (int i = 0; i < n; i++)
    {
        if (bounds[i].l > 1)
            addPoint(bounds[i].l - 1, bounds[i].y);
        if (bounds[i].r < w)
            addPoint(bounds[i].r + 1, bounds[i].y);
    }
    for (int i = 1; i <= w; i++)
        addPoint(i, h + 1);
    for (int i = 1; i < 2 * N; i++)
        tree[i].buildTree();

    for (int i = 0; i < n; i++)
    {
        if (bounds[i].l > 1)
            dp[i][0] = solvePoint(bounds[i].l - 1, bounds[i].y);
        else
            dp[i][0] = -1;
        if (bounds[i].r < w)
            dp[i][1] = solvePoint(bounds[i].r + 1, bounds[i].y);
        else
            dp[i][1] = -1;
        relaxMaxGlobal(1, bounds[i].l, bounds[i].r + 1, bounds[i].y, bounds[i].y + bounds[i].s + 1, i);
    }

    int ans = 0;
    for (int i = 1; i <= w; i++)
        ans = add(ans, solvePoint(i, h + 1));
    printf("%d\n", ans);

    return 0;
}