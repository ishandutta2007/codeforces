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

const int INF = (int)1e9 + 76;

struct Node
{
    int x, y;
    int l, r;
    int add;

    Node() : x(), y(), l(-1), r(-1), add(0) {}
    Node(int _x) : x(_x), y(rand()), l(-1), r(-1), add(0) {}
};
const int N = (int)1e6;
Node tree[N];
int treeSz;

int ans;

void push(int v)
{
    int u;
    u = tree[v].l;
    if (u != -1)
    {
        tree[u].add += tree[v].add;
        tree[u].x += tree[v].add;
    }
    u = tree[v].r;
    if (u != -1)
    {
        tree[u].add += tree[v].add;
        tree[u].x += tree[v].add;
    }
    tree[v].add = 0;
    return;
}

int merge(int L, int R)
{
    if (L == -1) return R;
    if (R == -1) return L;
    if (tree[L].y > tree[R].y)
    {
        push(L);
        tree[L].r = merge(tree[L].r, R);
        return L;
    }
    else
    {
        push(R);
        tree[R].l = merge(L, tree[R].l);
        return R;
    }
}
void split(int root, int x, int &L, int &R)
{
    if (root == -1)
    {
        L = R = -1;
        return;
    }
    push(root);
    if (tree[root].x <= x)
    {
        split(tree[root].r, x, L, R);
        tree[root].r = L;
        L = root;
    }
    else
    {
        split(tree[root].l, x, L, R);
        tree[root].l = R;
        R = root;
    }
}
int cutLeft(int root)
{
    if (root == -1) throw;
    push(root);
    if (tree[root].l == -1)
    {
        int R = tree[root].r;
        tree[root].r = -1;
        return R;
    }
    else
    {
        tree[root].l = cutLeft(tree[root].l);
        return root;
    }
}

void dfsAns(int v)
{
    if (v == -1) return;
    if (tree[v].x < INF)
        ans++;
    push(v);
    dfsAns(tree[v].l);
    dfsAns(tree[v].r);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    int root = treeSz++;
    tree[root] = Node(0);
    for (int i = 1; i <= n + 1; i++)
    {
        tree[treeSz] = Node(INF);
        root = merge(root, treeSz);
        treeSz++;
    }

    while(n--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int L, M, R;
        split(root, x - 1, L, R);
        split(R, y - 1, M, R);
        R = cutLeft(R);
        int v = treeSz++;
        tree[v] = Node(x);
        if (M != -1)
        {
            tree[M].x++;
            tree[M].add++;
        }
        root = merge(merge(L, v), merge(M, R));
    }

    ans = -1;
    dfsAns(root);
    printf("%d\n", ans);

    return 0;
}