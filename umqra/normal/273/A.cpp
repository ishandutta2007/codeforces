#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int pow2 = (1 << 18);

int a[pow2];

struct item
{
    ll tree[pow2 * 2];
    ll d[pow2 *2];
    void build()
    {
        for (int i = 0; i < 2 * pow2; i++)
            d[i] = tree[i] = 0;
    }
    void push(int v)
    {
        if (d[v])
        {
            d[2 * v] = d[2 * v + 1] = d[v];
            tree[2 * v] = tree[2 * v + 1] = d[v];
        }
        d[v] = 0;
    }
    void change(int a, int b, ll val, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l >= a && r <= b)
        {
            d[v] = tree[v] = val;
            return;
        }
        if (l > b || r < a)
            return;
        push(v);
        int m = (l + r) / 2;
        change(a, b, val, 2 * v, l, m);
        change(a, b, val, 2 * v + 1, m + 1, r);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
    ll getMax(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
    {
        if (l >= a && r <= b)
            return tree[v];
        if (l > b || r < a)
            return 0;
        push(v);
        int m = (l + r) / 2;
        return max(getMax(a, b, 2 * v, l, m), getMax(a, b, 2 * v + 1, m + 1, r));
    }
} tree;

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        tree.change(i, i, (ll)a[i]);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int w, h;
        scanf("%d%d", &w, &h);
        ll t = tree.getMax(0, w - 1);
        printf("%I64d\n", t);
        tree.change(0, w - 1, t + h);
    }

    return 0;
}