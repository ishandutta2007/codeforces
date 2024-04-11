#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
/*
#pragma GCC optimize ("O3")
#pragma comment(linker, "/STACK: 20000000005")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
*/
using namespace std;

const int N = 100005, M = 21;

struct node {
    node *l, *r;
    ll x;
    ll sh;
    node() {
        l = r = NULL;
        x = 0;
        sh = 0;
    }
    void shplit () {
        if (l == NULL)
            l = new node();
        if (r == NULL)
            r = new node();
        l->x += sh;
        l->sh += sh;
        r->x += sh;
        r->sh += sh;
        sh = 0;
    }
};

node *root[N];

int L, R;
ll X;

void update (node *&t, int l, int r){
    if (t == NULL)
        t = new node();
    if (max (l, L) >= min (r, R))
        return;
    if (L <= l && r <= R){
        t->sh += X;
        t->x += X;
        return;
    }
    t->shplit();
    int mid = l + r >> 1;
    update (t->l, l, mid);
    update (t->r, mid, r);
    t->x = max (t->l->x, t->r->x);
}

ll datvla (node *&t, int l, int r){
    if (t == NULL)
        t = new node();
    if (max (l, L) >= min (r, R))
        return 0;
    if (L <= l && r <= R)
        return t->x;
    t->shplit();
    int mid = l + r >> 1;
    ll x = datvla (t->l, l, mid);
    ll y = datvla (t->r, mid, r);
    //t->x = max (t->l->x, t->r->x);
    return max (x, y);
}


ll n, Q, W;

int A[N], B[N];
ll C[N];

vector < int > g[N];
int TURN;

int st[M][N], in[M][N], out[M][N], par[M][N];

int S[N];

multiset < ll > Se[N];
multiset < ll > ANS;
ll pas[N], ans[M][N];

bool F[N];

void dfs_sz (ll k, ll p){
    S[k] = 1;
    for (ll u : g[k]){
        if (F[u] == 1 || u == p)
            continue;
        dfs_sz (u, k);
        S[k] += S[u];
    }
}

ll find_centroid (ll k, ll p, ll x){
    for (ll u : g[k]){
        if (F[u] == 1 || u == p)
            continue;
        ll to = find_centroid (u, k, x);
        if (to)
            return to;
    }
    if (S[k] > x)
        return k;
    return 0;
}

ll T = 0;

ll parent (ll k, ll p, ll star, ll papa){
    in[TURN][k] = ++T;
    if (papa == 0 && k != star)
        papa = k;
    st[TURN][k] = star;
    par[TURN][k] = papa;
    for (ll u : g[k]){
        if (u == p || F[u] == 1)
            continue;
        parent (u, k, star, papa);
    }
    out[TURN][k] = T;
}

void go (int k, int turn){
    TURN = turn;
    dfs_sz (k, 0);
    int to = find_centroid (k, 0, S[k] / 2);
    k = to;
    T = 0;
    parent (k, 0, k, 0);
    for (int i = 0; i < g[k].size(); i++){
        int u = g[k][i];
        if (F[u])
            continue;
        Se[k].insert (0);
    }
    F[k] = 1;
    TURN = 0;
    for (int i = 0; i < g[k].size(); i++){
        int u = g[k][i];
        if (F[u])
            continue;
        go (u, turn + 1);
    }
}

void shecvla (ll d, ll e){
    ll u = A[d], v = B[d], f = C[d];
    ll delta = e - f;
    for (int i = 1; ;i++){
        if (st[i][u] != st[i][v])
            break;
        int START = st[i][u];
        if (START == 0)
            break;
        if (in[i][u] > in[i][v])
            swap (u, v);
        int papa = par[i][v];
        auto I = Se[START].find (ans[i][papa]);
        Se[START].erase (I);
        L = in[i][v];
        R = out[i][v] + 1;
        X = delta;
        update (root[START], 1, out[i][START] + 1);
        L = in[i][papa];
        R = out[i][papa] + 1;
        ans[i][papa] = datvla (root[START], 1, out[i][START] + 1);
        Se[START].insert (ans[i][papa]);
        if ((ll)Se[START].size() > 1){
            I = Se[START].end();
            I--;
            ll p1 = (*I);
            I--;
            ll p2 = (*I);
            I = ANS.find (pas[START]);
            ANS.erase (I);
            pas[START] = p1 + p2;
            ANS.insert (pas[START]);
        }
    }
    C[d] = e;
}


main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n >> Q >> W;
    if (n == 2){
        cin >> A[1] >> B[1] >> C[1];
        ll last = 0;
        while (Q--){
            ll d, e;
            scanf ("%lld %lld", &d, &e);
            d = (d + last) % (n - 1);
            e = (e + last) % W;
            last = e;
            cout << last << endl;
        }
        return 0;
    }
    for (ll i = 0; i < n - 1; i++){
        int u, v;
        ll x;
        scanf ("%d %d %lld", &u, &v, &x);
        A[i] = u;
        B[i] = v;
        C[i] = x;
        g[u].pb (v);
        g[v].pb (u);
    }
    for (ll i = 1; i <= n; i++)
        ANS.insert (0);
    go (1, 1);
    for (ll i = 0; i < n - 1; i++){
        ll x = C[i];
        C[i] = 0;
        shecvla (i, x);
    }
    ll last = 0;
    while (Q--){
        ll d, e;
        scanf ("%lld %lld", &d, &e);
        d = (d + last) % (n - 1);
        e = (e + last) % W;
        shecvla (d, e);
        auto I = ANS.end();
        I--;
        last = (*I);
        printf ("%lld\n", last);
    }
    return 0;
}