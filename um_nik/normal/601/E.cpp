#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const ll P = (ll)1e7 + 19;
const ll MOD = (ll)1e9 + 7;

const int N = 1 << 15;
const int K = 1002;
int dp[N / 2][K];

struct Node
{
    int l, r;
    vector<pii> val;

    Node() : l(), r(), val() {}
    Node(int _l, int _r) : l(_l), r(_r), val() {}
};
Node tree[2 * N];

struct Item
{
    int w, c;
    int l, r;

    Item() : w(), c(), l(), r() {}
    Item(int _w, int _c, int _l, int _r) : w(_w), c(_c), l(_l), r(_r) {}
};

void buildTree()
{
    for (int i = 0; i < N; i++)
        tree[N + i] = Node(i, i + 1);
    for (int i = N - 1; i > 0; i--)
        tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
    return;
}
void addSegm(int v, int l, int r, pii val)
{
    if (l <= tree[v].l && tree[v].r <= r)
    {
        tree[v].val.push_back(val);
        return;
    }
    if (l >= tree[v].r || tree[v].l >= r) return;
    addSegm(2 * v, l, r, val);
    addSegm(2 * v + 1, l, r, val);
    return;
}

Item a[N];
int n;
int q;
int m;
int k;
bool query[N];

void read()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        a[i].l = 0;
        a[i].r = N;
        scanf("%d%d", &a[i].c, &a[i].w);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            n++;
            a[n].l = i;
            a[n].r = N;
            scanf("%d%d", &a[n].c, &a[n].w);
        }
        else if (t == 2)
        {
            int x;
            scanf("%d", &x);
            a[x].r = i + 1;
        }
        else
            query[i] = true;
    }
    return;
}

void printAns()
{
    m--;
    ll res = 0;
    for (int i = k; i > 0; i--)
        res = (res * P + dp[m][i]) % MOD;
    printf("%lld\n", res);
    m++;
    return;
}

void dfs(int v)
{
    if (v >= N)
    {
        int x = v - N;
        if (!query[x]) return;
        printAns();
        return;
    }
    for (pii val : tree[v].val)
    {
        int c = val.X;
        int w = val.Y;
        for (int x = 0; x <= k; x++)
            dp[m][x] = max(dp[m - 1][x], (x < w ? 0 : dp[m - 1][x - w] + c));
        m++;
    }
    dfs(2 * v);
    dfs(2 * v + 1);
    m -= (int)tree[v].val.size();
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    buildTree();
    read();
    for (int i = 1; i <= n; i++)
    {
//      printf("%d %d %d %d\n", a[i].l, a[i].r, a[i].c, a[i].w);
        addSegm(1, a[i].l, a[i].r, mp(a[i].c, a[i].w));
    }
    m = 1;
    dfs(1);

    return 0;
}