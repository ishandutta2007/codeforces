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

const int N = 210000;

ll B[20];

struct node{
    ll mas[20];
    ll g;
    node *l, *r;
    node () {
        for (int i = 0; i < 20; i++)
            mas[i] = 0;
        g = 0;
        l = nullptr;
        r = nullptr;
    }
};

void update (node *&t, int l, int r, int L, int R, ll x){
    if (t == nullptr)
        t = new node ();
    if (max (l, L) >= min (r, R))
        return;
    if (L <= l && r <= R){
        t -> g ^= x;
        for (int i = 0; i < 20; i++)
            if ((x & B[i]) > 0)
                t -> mas[i] = r - l - t -> mas[i];
        return;
    }
    int m = (l + r) / 2;
    update (t -> l, l, m, l, m, t->g);
    update (t -> r, m, r, m, r, t->g);
    t -> g = 0;
    update (t -> l, l, m, L, R, x);
    update (t -> r, m, r, L, R, x);
    for (int i = 0; i < 20; i++)
        t -> mas[i] = t -> l -> mas[i] + t -> r -> mas[i];
}

ll calc (node *t, int l, int r, int L, int R){
    if (max (l, L) >= min (r, R))
        return 0;
    if (L <= l && r <= R){
        ll pas = 0;
        for (int i = 0; i < 20; i++)
            pas += t -> mas[i] * B[i];
        return pas;
    }
    int m = (l + r) / 2;
    update (t -> l, l, m, l, m, t -> g);
    update (t -> r, m, r, m, r, t -> g);
    t -> g = 0;
    return calc (t -> l, l, m, L, R) + calc (t -> r, m, r, L, R);
}

node *root = nullptr;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    B[0] = 1;
    for (int i = 1; i < 20; i++)
        B[i] = B[i - 1] * 2;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        update (root, 1, n + 1, i, i + 1, x);
    }
    cin >> m;
    while (m--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r;
            cin >> l >> r;
            cout << calc (root, 1, n + 1, l, r + 1) << endl;
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            update (root, 1, n + 1, l, r + 1, x);
        }
    }
    return 0;
}