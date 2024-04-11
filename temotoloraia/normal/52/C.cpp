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

const ll INF = 1e18;

struct node {
    node *l, *r;
    ll x;
    ll sh;
    node() {
        l = NULL;
        r = NULL;
        x = 0;
        sh = 0;
    }
    updt (){
        x = INF;
        if (l)
            x = min (x, l->x);
        if (r)
            x = min (x, r->x);
    }
    shep (ll t){
        x += t;
        sh += t;
    }
    shplit (){
        if (l == NULL)
            l = new node();
        if (r == NULL)
            r = new node();
        l->shep(sh);
        r->shep(sh);
        sh = 0;
    }
};

void update (node *&t, int l, int r, int L, int R, ll x){
    if (max (l, L) >= min (r, R))
        return;
    if (t == NULL)
        t = new node();
    if (L <= l && r <= R){
        t->shep(x);
        return;
    }
    t->shplit();
    int mid = l + r >> 1;
    update (t->l, l, mid, L, R, x);
    update (t->r, mid, r, L, R, x);
    t->updt ();
}

ll datvla (node *&t, int l, int r, int L, int R){
    if (max (l, L) >= min (r, R))
        return INF;
    if (t == NULL)
        return INF;
    if (L <= l && r <= R)
        return t->x;
    t->shplit();
    int mid = l + r >> 1;
    ll p = datvla (t->l, l, mid, L, R);
    ll q = datvla (t->r, mid, r, L, R);
    return min (p, q);
}

node *root;

const int N = 210000;


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
        int x;
        scanf ("%d", &x);
        update (root, 1, n + 1, i, i + 1, x);
    }
    int m;
    scanf ("%d", &m);
    while (m--){
        int l, r;
        scanf ("%d %d", &l, &r);
        l++;
        r++;
        char ch = getchar();
        if (ch == ' '){
            int x;
            scanf ("%d", &x);
            if (l <= r)
                update (root, 1, n + 1, l, r + 1, x);
            else {
                update (root, 1, n + 1, l, n + 1, x);
                update (root, 1, n + 1, 1, r + 1, x);
            }
        }
        else {
            if (l <= r)
                printf ("%lld\n", datvla (root, 1, n + 1, l, r + 1));
            else {
                ll p = datvla (root, 1, n + 1, l, n + 1);
                ll q = datvla (root, 1, n + 1, 1, r + 1);
                printf ("%lld\n", min (p, q));
            }
        }
    }
    return 0;
}