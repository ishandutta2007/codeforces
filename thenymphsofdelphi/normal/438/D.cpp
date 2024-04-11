#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e5 + 5;

int n, q;
int a[N];

ll segsum[4 * N]; int segmax[4 * N];

void build(int id, int l, int r){
    if (l == r){
        segsum[id] = a[l];
        segmax[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    segsum[id] = segsum[id << 1] + segsum[id << 1 | 1];
    segmax[id] = max(segmax[id << 1], segmax[id << 1 | 1]);
}

void update_assign(int id, int l, int r, int i, int val){
    if (i < l || r < i){
        return;
    }
    if (l == r){
        segsum[id] = val;
        segmax[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update_assign(id << 1, l, mid, i, val);
    update_assign(id << 1 | 1, mid + 1, r, i, val);
    segsum[id] = segsum[id << 1] + segsum[id << 1 | 1];
    segmax[id] = max(segmax[id << 1], segmax[id << 1 | 1]);
}

void update_modulo(int id, int l, int r, int u, int v, int val){
    if (v < l || r < u){
        return;
    }
    if (segmax[id] < val){
        return;
    }
    if (l == r){
        segsum[id] = segmax[id] % val;
        segmax[id] = segsum[id];
        return;
    }
    int mid = (l + r) >> 1;
    update_modulo(id << 1, l, mid, u, v, val);
    update_modulo(id << 1 | 1, mid + 1, r, u, v, val);
    segsum[id] = segsum[id << 1] + segsum[id << 1 | 1];
    segmax[id] = max(segmax[id << 1], segmax[id << 1 | 1]);
}

ll query_sum(int id, int l, int r, int u, int v){
    if (v < l || r < u){
        return 0;
    }
    if (u <= l && r <= v){
        return segsum[id];
    }
    int mid = (l + r) >> 1;
    return query_sum(id << 1, l, mid, u, v) + query_sum(id << 1 | 1, mid + 1, r, u, v);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--){
        int que; cin >> que;
        if (que == 1){
            int l, r; cin >> l >> r;
            cout << query_sum(1, 1, n, l, r) << endl;
        }
        if (que == 2){
            int l, r, x; cin >> l >> r >> x;
            update_modulo(1, 1, n, l, r, x);
        }
        if (que == 3){
            int i, x; cin >> i >> x;
            update_assign(1, 1, n, i, x);
        }
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/