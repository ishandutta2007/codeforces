#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
//#define int __int128
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 1e5 + 5, INF = 1e9;


struct node {
    node *l, *r;
    int ans, le, ri, sum;
    node() {
        ans = le = ri = sum = -INF;
        l = r = nullptr;
    }
};

int pos, val;

void update (node *&t, int l, int r){
    if (t == NULL)
        t = new node();
    if (pos < l || r < pos)
        return;
    if (l == r){
        t->ans = t->le = t->ri = t->sum = val;
        return;
    }
    int mid = l + r >> 1;
    update (t->l, l, mid);
    update (t->r, mid+1, r);
    t->sum = t->l->sum + t->r->sum;
    t->le = max (t->l->le, t->l->sum + max (t->r->le, 0ll));
    t->ri = max (t->r->ri, t->r->sum + max (t->l->ri, 0ll));
    t->ans = max (max (t->l->ans, t->r->ans), t->l->ri + t->r->le);
}

node * root;

int n;
int ans;
pair < int, int > P[N];

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> P[i].F;
        P[i].S = i;
    }
    sort (P + 1, P + n + 1);
    for (int i = 1; i <= n; i++){
        pos = P[i].S;
        val = P[i].F;
        update (root, 1, n);
        ans = max (ans, root->ans - P[i].F);
    }
    cout << ans << endl;
}