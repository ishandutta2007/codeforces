#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
//#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122
//#define int long long


#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/


using namespace std;

const int N = 300005, MOD = 1e9 + 7;

struct node {
    node *l, *r;
    int mx;
    int sh;
    node() {
        l = r = NULL;
        mx = sh = 0;
    }
    void shplit() {
        if (l == NULL)
            l = new node();
        if (r == NULL)
            r = new node();
        l->mx += sh;
        l->sh += sh;
        r->mx += sh;
        r->sh += sh;
        sh = 0;
    }
};

node *root;

int ll, rr, X;

void update (node *&t, int l, int r){
    if (max (ll, l) >= min (rr, r))
        return;
    if (t == NULL)
        t = new node();
    if (ll <= l && r <= rr){
        t->mx += X;
        t->sh += X;
        return;
    }
    t->shplit();
    int mid = l + r >> 1;
    update (t->l, l, mid);
    update (t->r, mid, r);
    t->mx = max (t->l->mx, t->r->mx);
}

int n;
int Q[N];
int ind[N];

int L[N], R[N], MID[N];

main()
{
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf ("%d", &Q[i]);
        ind[Q[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        scanf ("%d", &Q[i]);
    L[0] = n;
    for (int i = 1; i < n; i++){
        L[i] = 1;
        R[i] = n;
    }
    root = new node();
    cout << n << " ";
    int last = n + 1;
    for (int i = 1; i < n; i++){
        ll = 1;
        rr = Q[i] + 1;
        X = -1;
        update (root, 1, n + 1);
        while (root->mx <= 0){
            ll = 1;
            last--;
            rr = ind[last] + 1;
            X = 1;
            update (root, 1, n + 1);
        }
        printf ("%d ", last);
    }
    return 0;
}