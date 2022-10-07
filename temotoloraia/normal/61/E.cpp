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

const int N = 1e6 + 5, M = 1e9 + 1;

struct node {
    node *l, *r;
    int s;
    node (){
        l = NULL;
        r = NULL;
        s = 0;
    }
    updt (){
        s = 0;
        if (l)
            s += l->s;
        if (r)
            s += r->s;
    }
};

node *root;

void update (node *&t, int l, int r, int x){
    if (x < l || r <= x)
        return;
    if (t == NULL)
        t = new node();
    if (l + 1 == r){
        t->s ++;
        return;
    }
    int mid = l + r >> 1;
    update (t -> l, l, mid, x);
    update (t -> r, mid, r, x);
    t->updt();
}

int datvla (node *&t, int l, int r, int L, int R){
    if (max (l, L) >= min (r, R))
        return 0;
    if (t == NULL)
        return 0;
    if (L <= l && r <= R)
        return t->s;
    int mid = l + r >> 1;
    return datvla (t->l, l, mid, L, R) + datvla (t->r, mid, r, L, R);
}

int n;
int a[N];

int b[N];
map < int, int > MY;

ll x[N], y[N];
ll ans;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    reverse (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    sort (b + 1, b + n + 1);
    MY[b[1]] = 1;
    for (int i = 2; i <= n; i++)
        if (b[i] > b[i - 1])
            MY[b[i]] = MY[b[i - 1]] + 1;
    for (int i = 1; i <= n; i++)
        a[i] = MY[a[i]];
    for (int i = 1; i <= n; i++){
        x[i] = datvla (root, 1, N, 1, a[i]);
        update (root, 1, N, a[i]);
    }
    root = NULL;
    for (int i = n; i >= 1; i--){
        y[i] = datvla (root, 1, N, a[i] + 1, N);
        update (root, 1, N, a[i]);
    }
    for (int i = 1; i <= n; i++)
        ans += x[i] * y[i];
    cout << ans << endl;
    return 0;
}