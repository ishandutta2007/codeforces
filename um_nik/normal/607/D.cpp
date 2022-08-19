#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
    if (p == 0) return 1;
    if (p == 2) return mult(x, x);
    if (p & 1) return mult(x, bin_pow(x, p - 1));
    return bin_pow(bin_pow(x, p / 2), 2);
}
ll rev(ll x)
{
    return bin_pow(x, MOD - 2);
}
ll Div(ll x, ll y)
{
    return mult(x, rev(y));
}

const int N = 1 << 18;
int n;
int q;
vector<int> g[N];
int deg[N];
int tIn[N], tOut[N];
ll a[N];
int T = 0;

struct Node
{
    ll sum, mp;
    ll toMp;
    int l, r;

    Node() : sum(0), mp(1), toMp(1), l(-1), r(-1) {}
    Node(int _l, int _r) : sum(0), mp(1), toMp(1), l(_l), r(_r) {}
};

Node tree[2 * N];

struct Query
{
    int type;
    int v;
    ll val;

    Query() : type(), v(), val() {}
    
    void scan()
    {
        scanf("%d%d", &type, &v);
        v--;
        if (type == 1)
            scanf("%lld", &val);
    }
};
Query Q[N];

void dfs(int v)
{
    tIn[v] = T++;
    for (int u : g[v])
        dfs(u);
    tOut[v] = T;
    return;
}

void buildTree()
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
    ll x = tree[v].toMp;
    tree[v].toMp = 1;
    for (int i = 0; i < 2; i++)
    {
        int u = 2 * v + i;
        tree[u].sum = mult(tree[u].sum, x);
        tree[u].mp = mult(tree[u].mp, x);
        tree[u].toMp = mult(tree[u].toMp, x);
    }
    return;
}
void update(int v)
{
    if (v >= N) throw;
    tree[v].sum = add(tree[2 * v].sum, tree[2 * v + 1].sum);
    return;
}

ll getSum(int v, int l, int r)
{
    if (l <= tree[v].l && tree[v].r <= r)
        return tree[v].sum;
    if (l >= tree[v].r || tree[v].l >= r)
        return 0;
    push(v);
    ll res = add(getSum(2 * v, l, r), getSum(2 * v + 1, l, r));
    update(v);
    return res;
}
ll getMp(int v)
{
    v = tIn[v];
    int u = 1;
    while(u < N)
    {
        push(u);
        u <<= 1;
        if (tree[u].r <= v) u++;
    }
    ll res = tree[u].mp;
    u >>= 1;
    while(u > 0)
    {
        update(u);
        u >>= 1;
    }
    return res;
}
void multOnSegm(int v, int l, int r, ll x)
{
    if (l <= tree[v].l && tree[v].r <= r)
    {
        tree[v].sum = mult(tree[v].sum, x);
        tree[v].mp = mult(tree[v].mp, x);
        tree[v].toMp = mult(tree[v].toMp, x);
        return;
    }
    if (l >= tree[v].r || tree[v].l >= r) return;
    push(v);
    for (int i = 0; i < 2; i++)
        multOnSegm(2 * v + i, l, r, x);
    update(v);
    return;
}
void multInV(int v, ll x)
{
    multOnSegm(1, tIn[v], tOut[v], x);
}

void read()
{
    n = 1;
    scanf("%lld%d", &a[0], &q);
    for (int i = 0; i < q; i++)
    {
        Q[i].scan();
        if (Q[i].type == 1)
        {
            a[n] = Q[i].val;
            g[Q[i].v].push_back(n++);
        }
    }
    dfs(0);
    buildTree();
    return;
}

void addVertex(int v, int p)
{
    ll x = Div(deg[p] + 1, deg[p]);
    deg[p]++;
    deg[v] = 1;
    multInV(p, x);
    ll y = mult(a[v], getMp(v));
    v = tIn[v];
    v += N;
    tree[v].sum = y;
    v >>= 1;
    while(v > 0)
    {
        update(v);
        v >>= 1;
    }
    return;
}

ll getAns(int v)
{
    return mult(Div(getSum(1, tIn[v], tOut[v]), getMp(v)), deg[v]);
}

void solve()
{
    deg[0] = 1;
    int v = N;
    tree[v].sum = a[0];
    v >>= 1;
    while(v > 0)
    {
        update(v);
        v >>= 1;
    }
    n = 1;
    for (int i = 0; i < q; i++)
    {
        if (Q[i].type == 1)
            addVertex(n++, Q[i].v);
        else
        {
            printf("%lld\n", getAns(Q[i].v));
        }
    }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    solve();

    /*
    for (int i = 0; i < n; i++)
        printf("%lld\n", getMp(i));
    for (int i = 0; i < n; i++)
        printf("%d %d\n", tIn[i], tOut[i]);
    for (int i = 0; i < n; i++)
        printf("%lld\n", getSum(1, i, i + 1));
        */

    return 0;
}