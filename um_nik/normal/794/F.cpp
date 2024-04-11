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

const int K = 10;
const int N = 1 << 17;
struct Node
{
    int l, r;
    ll val[K];
    int p[K];

    Node()
    {
        l = r = -1;
        for (int i = 0; i < K; i++)
        {
            val[i] = 0;
            p[i] = i;
        }
    }
    Node(int _l, int _r)
    {
        l = _l;
        r = _r;
        for (int i = 0; i < K; i++)
        {
            val[i] = 0;
            p[i] = i;
        }
    }
    ll getVal()
    {
        ll res = 0;
        for (int i = 0; i < K; i++)
            res += i * val[i];
        return res;
    }
};
Node tree[2 * N];

void build()
{
    for (int i = 0; i < N; i++)
        tree[N + i] = Node(i, i + 1);
    for (int i = N - 1; i > 0; i--)
        tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void push(int v)
{
    if (v >= N) throw;
    ll nval[K];
    for (int u = 2 * v; u < 2 * v + 2; u++)
    {
        for (int i = 0; i < K; i++)
            nval[i] = 0;
        for (int i = 0; i < K; i++)
            nval[tree[v].p[i]] += tree[u].val[i];
        for (int i = 0; i < K; i++)
            tree[u].val[i] = nval[i];
        for (int i = 0; i < K; i++)
            tree[u].p[i] = tree[v].p[tree[u].p[i]];
    }
    for (int i = 0; i < K; i++)
        tree[v].p[i] = i;
    return;
}
Node merge(Node L, Node R)
{
    if (L.l == -1) return R;
    if (R.l == -1) return L;
    Node A = Node(L.l, R.r);
    for (int i = 0; i < K; i++)
        A.val[i] = L.val[i] + R.val[i];
    return A;
}

Node get(int v, int l, int r)
{
    if (l <= tree[v].l && tree[v].r <= r) return tree[v];
    if (l >= tree[v].r || tree[v].l >= r) return Node();
    push(v);
    return merge(get(2 * v, l, r), get(2 * v + 1, l, r));
}

void change(int v, int l, int r, int x, int y)
{
    if (l <= tree[v].l && tree[v].r <= r)
    {
        for (int i = 0; i < K; i++)
            if (tree[v].p[i] == x)
                tree[v].p[i] = y;
        tree[v].val[y] += tree[v].val[x];
        tree[v].val[x] = 0;
        return;
    }
    if (l >= tree[v].r || tree[v].l >= r) return;
    push(v);
    change(2 * v, l, r, x, y);
    change(2 * v + 1, l, r, x, y);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);

    build();

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        ll oldx = x;
        ll y = 1;
        while(y <= oldx)
        {
            tree[N + i].val[x % 10] += y;
            x /= 10;
            y *= 10;
        }
    }
    for (int i = N - 1; i > 0; i--)
        for (int j = 0; j < K; j++)
            tree[i].val[j] = tree[2 * i].val[j] + tree[2 * i + 1].val[j];

    while(q--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int l, r, x, y;
            scanf("%d%d%d%d", &l, &r, &x, &y);
            l--;
            if (x == y) continue;
            change(1, l, r, x, y);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--;
            printf("%lld\n", get(1, l, r).getVal());
        }
    }


    return 0;
}