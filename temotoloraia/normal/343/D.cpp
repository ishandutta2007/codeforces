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

struct node{
    node *l, *r;
    int x;
    int sh;
    node (){
        x = 0;
        sh = 0;
        l = NULL;
        r = NULL;
    }
    updt (){
        if (l)
            x = max (x, l->x);
        if (r)
            x = max (x, r->x);
    }
    shep (int t){
        x = max (x, t);
        sh = max (sh, t);
    }
    shplit (){
        if (l == NULL)
            l = new node();
        if (r == NULL)
            r = new node();
        l->shep (sh);
        r->shep (sh);
        sh = 0;
    }
};

node *root0, *root1;

const int N = 512345;

int n;
vector < int > g[N];
int T;
int in[N], out[N];

void dfs (int k, int p){
    in[k] = ++T;
    for (int u : g[k]){
        if (u == p)
            continue;
        dfs (u, k);
    }
    out[k] = T;
}

void update (node *&t, int l, int r, int x, int y, int tim){
    if (max (l, x) >= min (r, y))
        return;
    if (t == NULL)
        t = new node();
    if (x <= l && r <= y){
        t->shep (tim);
        return;
    }
    t->shplit();
    int mid = (l + r) >> 1;
    update (t->l, l, mid, x, y, tim);
    update (t->r, mid, r, x, y, tim);
    t->updt();
}

int query (node *&t, int l, int r, int x, int y){
    if (t == NULL)
        return 0;
    if (max (l, x) >= min (r, y))
        return 0;
    if (x <= l && r <= y){
        return t->x;
    }
    t->shplit();
    t->updt();
    int mid = (l + r) >> 1;
    int p = query (t->l, l, mid, x, y);
    int q = query (t->r, mid, r, x, y);
    return max (p, q);
}

int main()
{
    //freopen ("in.in", "r", stdin);
    //freopen ("out.out", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v;
        scanf ("%d %d", &u, &v);
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++){
        int t, u;
        scanf ("%d %d", &t, &u);
        if (t == 1){
            update (root1, 1, n + 1, in[u], out[u] + 1, i);
        }
        else if (t == 2){
            update (root0, 1, n + 1, in[u], in[u] + 1, i);
        }
        else {
            int p = query (root0, 1, n + 1, in[u], out[u] + 1);
            int q = query (root1, 1, n + 1, in[u], in[u] + 1);
            int ans = 0;
            if (p < q)
                ans = 1;
            printf ("%d\n", ans);
        }
    }
    return 0;
}