#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

//#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 400005, MOD = 1e9 + 7, INF = 1e11;

struct node {
    node *l, *r;
    int x;
    node() {
        l = r = NULL;
        x = INF;
    }
};

int L, R, X;

void update (node *&t, int l, int r){
    if (t == NULL)
        t = new node();
    if (r < L || L < l)
        return;
    if (l == r){
        t->x = X;
        return;
    }
    int mid = l + r >> 1;
    update (t->l, l, mid);
    update (t->r, mid+1, r);
    t->x = min (t->l->x, t->r->x);
}

int query (node *t, int l, int r){
    if (min (r, R) < max (l, L) || t == NULL)
        return INF;
    if (L <= l && r <= R)
        return t->x;
    int mid = l + r >> 1;
    int x = query (t->l, l, mid);
    int y = query (t->r, mid+1, r);
    return min (x, y);
}


int n, m;
int a[N];
pair < int, int > P[N];
int st[N];
int dp[N];

    node *root1;
    node *root2;
void solve () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        scanf ("%lld", &a[i]);
        P[m+i] = {a[i], a[i]};
    }
    sort (a+1, a+n+1);
    for (int i = 1; i <= m; i++){
        scanf ("%lld%lld", &P[i].F, &P[i].S);
    }
    m += n;
    sort (P+1, P+m+1);
    reverse (P+1, P+m+1);
    int RR = MOD, cnt = 0;
    for (int i = 1; i <= m; i++){
        if (RR <= P[i].S){
            P[i].F = MOD;
            cnt++;
            continue;
        }
        RR = P[i].S;
    }
    sort (P+1, P+m+1);
    m -= cnt;
    //m=3;
    int ind = 0;
    root1 = new node();
    root2 = new node();
    for (int i = 0; i <= 0; i++){
        L = R = i;
        X = dp[i] - P[i+1].S;
        update (root1, 0, m);
        X -= P[i+1].S;
        update (root2, 0, m);
    }
    //cout << root1->l->r->x << endl;
    for (int i = 1; i <= m; i++){
        //cout << P[i].F << " " << P[i].S << " ";
        st[i] = st[i-1];
        if (P[i].F >= a[ind+1] && ind < n){
            ind++;
            st[i] = i;
        }
        if (ind){
            R = st[i]-1;
            L = st[R];
            int A = query (root1, 0, m) + a[ind] + (P[i].F - a[ind]) * 2;
            int B = query (root2, 0, m) + a[ind]*2 + (P[i].F - a[ind]);
            dp[i] = min (A, B);
        }
        else {
            dp[i] = INF;
        }
        L = R = i;
        X = dp[i] - P[i+1].S;
        update (root1, 0, m);
        X -= P[i+1].S;
        update (root2, 0, m);
        //cout << ind << " " << dp[i] << endl;
    }

    cout << dp[m] << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}