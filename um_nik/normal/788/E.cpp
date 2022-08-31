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

const int MOD = (int)1e9 + 7;
int add(int x, int y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
int sub(int x, int y)
{
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
int mult(int x, int y)
{
    return ((ll)x * y) % MOD;
}

const int N = 100010;
int a[N];
int xs[N];
int el_id[N];
vector<int> leftNum[N], rightNum[N];
int n, m;
int ans;
int fenv[N];

void fenv_add(int p, int x)
{
    for (; p < N; p |= (p + 1))
        fenv[p] += x;
    return;
}
int fenv_get(int p)
{
    int res = 0;
    for (; p >= 0; p = (p & (p + 1)) - 1)
        res += fenv[p];
    return res;
}

void read()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        xs[i] = a[i];
    }
    sort(xs, xs + n);
    m = unique(xs, xs + n) - xs;
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(xs, xs + m, a[i]) - xs;
        el_id[i] = leftNum[a[i]].size();
        leftNum[a[i]].push_back(0);
        rightNum[a[i]].push_back(0);
    }
    for (int i = 0; i < N; i++)
        fenv[i] = 0;
    for (int i = 0; i < n; i++)
    {
        leftNum[a[i]][el_id[i]] = fenv_get(a[i]);
        fenv_add(a[i], 1);
    }
    for (int i = 0; i < N; i++)
        fenv[i] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        rightNum[a[i]][el_id[i]] = fenv_get(a[i]);
        fenv_add(a[i], 1);
    }
    return;
}

struct Node
{
    int l, r;
    int leftVal, rightVal;
    int leftSum, rightSum;
    int count;
    int leftAr, rightAr;

    Node() : l(-1), r(-1), leftVal(), rightVal(), leftSum(), rightSum(), count(), leftAr(), rightAr() {}
    Node(int _l, int _r) : l(_l), r(_r), leftVal(), rightVal(), leftSum(), rightSum(), count(), leftAr(), rightAr() {}
};

vector<Node> tree[N];

Node merge(Node L, Node R)
{
    if (L.l == -1) return R;
    if (R.l == -1) return L;
    Node A = Node(L.l, R.r);
    A.leftSum = add(L.leftSum, R.leftSum);
    A.rightSum = add(L.rightSum, R.rightSum);
    A.count = L.count + R.count;
    A.leftAr = add(L.leftAr, add(mult(L.leftSum, R.count), R.leftAr));
    A.rightAr = add(R.rightAr, add(mult(R.rightSum, L.count), L.rightAr));
    return A;
}

void buildTree(int k)
{
    int sz = (int)leftNum[k].size();
    while(sz & (sz - 1)) sz++;
    tree[k].resize(sz * 2);
    for (int i = 0; i < sz; i++)
    {
        tree[k][sz + i] = Node();
        if (i < (int)leftNum[k].size())
        {
            tree[k][sz + i].l = i;
            tree[k][sz + i].r = i + 1;
            tree[k][sz + i].leftVal = tree[k][sz + i].leftSum = leftNum[k][i];
            tree[k][sz + i].rightVal = tree[k][sz + i].rightSum = rightNum[k][i];
            tree[k][sz + i].count = 1;
        }
    }
    for (int i = sz - 1; i > 0; i--)
        tree[k][i] = merge(tree[k][2 * i], tree[k][2 * i + 1]);
    return;
}

Node get(int k, int v, int l, int r)
{
    if (l <= tree[k][v].l && tree[k][v].r <= r)
        return tree[k][v];
    if (l >= tree[k][v].r || tree[k][v].l >= r)
        return Node();
    return merge(get(k, 2 * v, l, r), get(k, 2 * v + 1, l, r));
}

void change(int k, int v)
{
    v += (int)tree[k].size() / 2;
    tree[k][v].count ^= 1;
    if (tree[k][v].count == 0)
    {
        tree[k][v].leftSum = 0;
        tree[k][v].rightSum = 0;
    }
    else
    {
        tree[k][v].leftSum = tree[k][v].leftVal;
        tree[k][v].rightSum = tree[k][v].rightVal;
    }
    while(v > 1)
    {
        v >>= 1;
        tree[k][v] = merge(tree[k][2 * v], tree[k][2 * v + 1]);
    }
    return;
}

void initAns()
{
    for (int k = 0; k < m; k++)
        for (int i = 0; i < (int)leftNum[k].size(); i++)
        {
            Node L = get(k, 1, 0, i), R = get(k, 1, i + 1, (int)leftNum[k].size());
            ans = add(ans, mult(L.leftSum, R.rightSum));
        }
}

int calcDelta(int k, int v)
{
    int res = 0;
    Node L = get(k, 1, 0, v), R = get(k, 1, v + 1, (int)leftNum[k].size());
    res = add(res, mult(L.leftSum, R.rightSum));
    res = add(res, mult(L.leftAr, rightNum[k][v]));
    res = add(res, mult(R.rightAr, leftNum[k][v]));
    return res;
}

void query()
{
    int p;
    scanf("%*d%d", &p);
    p--;
    int k = a[p];
    int v = el_id[p];
    int delta = calcDelta(k, v);
    if (tree[k][(int)tree[k].size() / 2 + v].count)
        ans = sub(ans, delta);
    else
        ans = add(ans, delta);
    change(k, v);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();
    for (int i = 0; i < m; i++)
        buildTree(i);
    initAns();
    int q;
    scanf("%d", &q);
    while(q--)
    {
        query();
        printf("%d\n", ans);
    }

    return 0;
}