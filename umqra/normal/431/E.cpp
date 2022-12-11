#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;
const int pow2 = (1 << 18);
const int N = (int)3e5 + 10;
const int IT = 100;
const double eps = 1e-8;

bool Eq(double a, double b)
{
    return fabs(a - b) < eps;
}

bool LsEq(double a, double b)
{
    return a < b || Eq(a, b);
}

struct Item
{
    ll sum; 
    int cnt;
    Item () {}
    Item (ll sum, int c) : sum(sum), cnt(c) {}
};

struct Query
{
    int t;
    ll a, b;
    Query () {}
    Query (int t, ll a, ll b) : t(t), a(a), b(b) {}
} qr[N];
int listVal[N];
int indL = 0;

struct SegmentTree
{
    Item tree[pow2 * 2];
    void build()
    {
        for (int i = 0; i < pow2 * 2; i++)
            tree[i] = Item(0, 0);
    }
    void addVal(int pos, int val, int v, int l, int r)
    {
        if (l == r)
        {                             
            tree[v].cnt += val;
            tree[v].sum += val * listVal[pos];     
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
            addVal(pos, val, 2 * v, l, m);
        else
            addVal(pos, val, 2 * v + 1, m + 1, r);
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;  
        tree[v].cnt = tree[2 * v].cnt + tree[2 * v + 1].cnt;
    }                                                       
    double getVal(double x, double w, int v, int l, int r)
    {
        if (l == r)
        {   
            double t = x * tree[v].cnt - tree[v].sum;
            return t;   
        }
        int m = (l + r) / 2;
        if (listVal[m] > x)
            return getVal(x, w, 2 * v, l, m);
        double t = x * tree[2 * v].cnt - tree[2 * v].sum;
        if (LsEq(w, t))
            return getVal(x, w, 2 * v, l, m);
        else
            return getVal(x, w - t, 2 * v + 1, m + 1, r) + t;
    }
} tree;
int h[N];

int getPos(int val)
{
    return lower_bound(listVal, listVal + indL, val) - listVal;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    tree.build();
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
        listVal[indL++] = h[i];
    }

    for (int i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int p, x;
            scanf("%d%d", &p, &x);
            qr[i] = Query(1, p, x);
            listVal[indL++] = x;
        }
        else
        {
            ll v;
            scanf("%I64d", &v);
            qr[i] = Query(2, v, 0);
        }
    }
    sort(listVal, listVal + indL);
    indL = unique(listVal, listVal + indL) - listVal;
    for (int i = 0; i < n; i++)
    {
        int pos = getPos(h[i]);
        tree.addVal(pos, 1, 1, 0, indL - 1);
    }

    for (int i = 0; i < q; i++)
    {
        if (qr[i].t == 1)
        {
            int pos = qr[i].a - 1;
            int v = qr[i].b;
            int old = h[pos];
            tree.addVal(getPos(old), -1, 1, 0, indL - 1);
            tree.addVal(getPos(v), 1, 1, 0, indL - 1);
            h[pos] = v;
        }
        else
        {
            double l = 0, r = 2e15;
            for (int s = 0; s < IT; s++)
            {
                double m = (l + r) / 2;
                double val = tree.getVal(m, qr[i].a, 1, 0, indL - 1);
//              cout << val << ":" << qr[i].a << endl;
                if (LsEq(qr[i].a, val))
                    r = m;
                else            
                    l = m;
            }
            printf("%.5lf\n", r);
        }
    }

    return 0;
}