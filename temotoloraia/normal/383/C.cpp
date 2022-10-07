#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int N = 1e6 + 5;

int n, m;
ll a[N];
vector < int > g[N];

int Tim;
int fix[N];

int l[2][N], r[2][N];

int mas[2][N];

void dfs (int k, int p, int st){
    fix[k] = st;
    mas[st][++Tim] = k;
    l[st][k] = Tim;
    for (int u : g[k]){
        if (u == p)
            continue;
        l[st][u] = Tim + 1;
        for (int v : g[u]){
            if (v == k)
                continue;
            dfs (v, u, st);
        }
        r[st][u] = Tim;
    }
    r[st][k] = Tim;
}

struct node {
    node *l, *r;
    ll s, x;
    node() {
        s = 0;
        x = 0;
        l = NULL;
        r = NULL;
    }
};

node * root[2] = {NULL, NULL};

void update (node *&t, ll l, ll r, ll L, ll R, ll x){
    if (min (r, R) <= max (l, L))
        return;
    if (t == NULL)
        t = new node();
    if (L <= l && r <= R){
        t->x += x;
        t->s += x * (r - l);
        return;
    }
    ll mid = (l + r) / 2;
    update (t->l, l, mid, l, mid, t->x);
    update (t->r, mid, r, mid, r, t->x);
    t->x = 0;
    update (t->l, l, mid, L, R, x);
    update (t->r, mid, r, L, R, x);
    t->s = (t->l?t->l->s:0) + (t->r?t->r->s:0);
}

ll datvla (node *&t, ll l, ll r, ll L, ll R){
    if (min (r, R) <= max (l, L))
        return 0;
    if (t == NULL)
        return 0;
    if (L <= l && r <= R)
        return t->s;
    ll mid = (l + r) / 2;
    update (t->l, l, mid, l, mid, t->x);
    update (t->r, mid, r, mid, r, t->x);
    t->x = 0;
    return datvla (t->l, l, mid, L, R) + datvla (t->r, mid, r, L, R);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    g[0].pb (1);
    Tim = 0;
    dfs (0, 0, 0);
    for (int i = 1; i <= Tim; i++)
        update (root[0], 1, n + 1, i, i + 1, a[mas[0][i]]);
    Tim = 0;
    dfs (1, 0, 1);
    for (int i = 1; i <= Tim; i++)
        update (root[1], 1, n + 1, i, i + 1, a[mas[1][i]]);
    while (m--){
        int t;
        cin >> t;
        if (t == 1){
            int x;
            ll val;
            cin >> x >> val;
            update (root[fix[x]],     1, n + 1, l[fix[x]][x],     r[fix[x]][x] + 1,     val);
            update (root[1 - fix[x]], 1, n + 1, l[1 - fix[x]][x], r[1 - fix[x]][x] + 1, -val);
        }
        else {
            int x;
            cin >> x;
            cout << datvla (root[fix[x]], 1, n + 1, l[fix[x]][x], l[fix[x]][x] + 1) << endl;
        }
    }
    return 0;
}