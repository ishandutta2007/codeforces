#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;

const int N = 1 << 17;

ll MOD;
ll P;
ll p[N];
ll h[N];

ll sum(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}

bool isPrime(ll x)
{
    for (ll y = 2; y * y < x; y++)
        if (x % y == 0)
            return false;
    return true;
}

struct Node
{
    int l, r;
    ll val;
    int col;

    Node() : l(), r(), val(0), col(-1) {}
    Node(int _l, int _r, ll _val, int _col = -1) : l(_l), r(_r), val(_val), col(_col) {}
};

Node tree[2 * N];

void push(int v)
{
    if (v >= N) throw;
    if (tree[v].col == -1) return;
    for (int i = 0; i < 2; i++)
    {
        int u = 2 * v + i;
        int len = tree[u].r - tree[u].l;
        tree[u].val = mult(h[len], tree[v].col);
        tree[u].col = tree[v].col;
    }
    tree[v].col = -1;
    return;
}

Node merge(Node L, Node R)
{
    if (L.l == L.r) return R;
    if (R.l == R.r) return L;
    int len = R.r - R.l;
    return Node(L.l, R.r, sum(mult(L.val, p[len]), R.val));
}

void update(int v)
{
    if (v >= N) throw;
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    return;
}

char s[N];
void buildTree(int n)
{
    for (int i = 0; i < N; i++)
        tree[N + i] = Node(i, i + 1, (i < n ? (int)(s[i] - '0') : 0));
    for (int i = N - 1; i > 0; i--)
        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    return;
}

void colorSegm(int v, int l, int r, int col)
{
    if (l <= tree[v].l && tree[v].r <= r)
    {
        tree[v].col = col;
        int len = tree[v].r - tree[v].l;
        tree[v].val = mult(h[len], col);
        return;
    }
    if (l >= tree[v].r || tree[v].l >= r)
        return;
    push(v);
    for (int i = 0; i < 2; i++)
        colorSegm(2 * v + i, l, r, col);
    update(v);
    return;
}

Node getHash(int v, int l, int r)
{
    if (l <= tree[v].l && tree[v].r <= r)
        return tree[v];
    if (l >= tree[v].r || tree[v].l >= r)
        return Node();
    push(v);
    return merge(getHash(2 * v, l, r), getHash(2 * v + 1, l, r));
}

ll getHash(int l, int r)
{
    return getHash(1, l, r).val;
}

int n;
int q;

void read()
{
    int x, y;
    scanf("%d%d%d", &n, &x, &y);
    q = x + y;
    scanf(" %s ", s);
    buildTree(n);
    return;
}

void query()
{
    int t, l, r, x;
    scanf("%d%d%d%d", &t, &l, &r, &x);
    l--;
    if (t == 1)
        colorSegm(1, l, r, x);
    else
    {
        ll h1 = getHash(l, r - x);
        ll h2 = getHash(l + x, r);
        if (h1 == h2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    P = 20 + rand() % 30;
    while(!isPrime(P)) P++;
    MOD = (ll)1e9 + rand() % 1000;
    while(!isPrime(MOD)) MOD++;
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = mult(p[i - 1], P);
    h[0] = 0;
    for (int i = 1; i < N; i++)
        h[i] = sum(h[i - 1], p[i - 1]);
    read();
    while(q--)
        query();

    return 0;
}