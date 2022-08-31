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

const int N = 100010;
const int M = N * 50;

struct Node
{
    int L, R;
    int val;

    Node() : L(-1), R(-1), val(0) {}
};
Node tree[M];
int treeSz;
int lst[N];
int a[N];
int n;
int roots[N];

int build(int l, int r)
{
    int v = treeSz++;
    tree[v] = Node();
    if (l + 1 == r)
        return v;
    int mid = (l + r) / 2;
    tree[v].L = build(l, mid);
    tree[v].R = build(mid, r);
    return v;
}

int addNode(int v, int a, int b, int pos, int delta)
{
    //cerr << "addNode " << v << " " << a << " " << b << " " << pos << " " << delta << endl;
    if (pos < a || pos >= b) return v;
    int u = treeSz++;
    tree[u] = tree[v];
    tree[u].val += delta;
    if (tree[v].L == -1)
    {
        return u;
    }
    int mid = (a + b) / 2;
    tree[u].L = addNode(tree[v].L, a, mid, pos, delta);
    tree[u].R = addNode(tree[v].R, mid, b, pos, delta);
    return u;
}

int findNext(int v, int a, int b, int k)
{
    //cerr << "findNext " << v << " " << a << " " << b << " " << k << endl;
    if (k >= tree[v].val) return b;
    if (a + 1 == b)
    {
        return a;
    }
    int mid = (a + b) / 2;
    if (k >= tree[tree[v].L].val)
        return findNext(tree[v].R, mid, b, k - tree[tree[v].L].val);
    else
        return findNext(tree[v].L, a, mid, k);
}

int solve(int k)
{
    //cerr << "solve " << k << endl;
    int pos = 0;
    int ans = 0;
    while (pos < n)
    {
        //cerr << pos << endl;
        ans++;
        int oldpos = pos;
        pos = findNext(roots[pos], 0, n, k);
        if (pos == oldpos) throw;
    }
    return ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < N; i++)
        lst[i] = -1;
    roots[n] = build(0, n);
    for (int i = n - 1; i >= 0; i--)
    {
        //cerr << i << endl;
        int x = a[i];
        int root = roots[i + 1];
        if (lst[x] != -1)
            root = addNode(root, 0, n, lst[x], -1);
        lst[x] = i;
        roots[i] = addNode(root, 0, n, lst[x], 1);
    }
    for (int k = 1; k <= n; k++)
        printf("%d ", solve(k));
    printf("\n");

    return 0;
}