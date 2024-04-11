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

const int N = 500500;
const int INF = (int)1e7;

struct Node
{
    int x, y;
    int val;
    int sz;
    int l, r;

    Node() : x(), y(), val(), sz(), l(-1), r(-1) {}
    Node(int _x) : x(_x), y(rand()), val(_x), sz(1), l(-1), r(-1) {}
};
Node tree[N];
int m;

int getSize(int v)
{
    if (v == -1) return 0;
    return tree[v].sz;
}
int getVal(int v)
{
    if (v == -1) return INF;
    return tree[v].val;
}
int update(int v)
{
    if (v == -1) return v;
    int lSz = getSize(tree[v].l), rSz = getSize(tree[v].r);
    tree[v].sz = 1 + lSz + rSz;
    tree[v].val = min(getVal(tree[v].l), min(tree[v].x - lSz, getVal(tree[v].r) - lSz - 1));
    return v;
}

int merge(int L, int R)
{
    if (L == -1) return R;
    if (R == -1) return L;
    if (tree[L].y > tree[R].y)
    {
        tree[L].r = merge(tree[L].r, R);
        return update(L);
    }
    else
    {
        tree[R].l = merge(L, tree[R].l);
        return update(R);
    }
}

void splitByX(int v, int x, int &L, int &R)
{
    if (v == -1)
    {
        L = R = -1;
        return;
    }
    if (tree[v].x > x)
    {
        splitByX(tree[v].l, x, L, R);
        tree[v].l = R;
        R = update(v);
    }
    else
    {
        splitByX(tree[v].r, x, L, R);
        tree[v].r = L;
        L = update(v);
    }
}

int solve(int root)
{
    int p = 0;
    int v = root;
    while(v != -1)
    {
        int lSz = getSize(tree[v].l);
        if (p + lSz + 1 + tree[v].x <= 0)
        {
            p += lSz + 1;
            v = tree[v].r;
        }
        else
        {
            v = tree[v].l;
        }
    }
    //printf("%d ", p);
    p *= -1;
    int q = p;
    v = root;
    int rightVal = INF;
    while(v != -1)
    {
        int rSz = getSize(tree[v].r);
        int curVal = min(tree[v].x, min(getVal(tree[v].r) - 1, rightVal - rSz - 1));
        if (curVal > p)
        {
            rightVal -= rSz + 1;
            q += rSz + 1;
            rightVal = min(rightVal, min(tree[v].x, getVal(tree[v].r) - 1));
            v = tree[v].l;
        }
        else
        {
            v = tree[v].r;
        }
    }
    return q;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int root = -1;

    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        tree[m] = Node(x);
        int L, R;
        splitByX(root, x, L, R);
        root = merge(merge(L, m), R);
        m++;
        printf("%d\n", solve(root));
    }

    return 0;
}