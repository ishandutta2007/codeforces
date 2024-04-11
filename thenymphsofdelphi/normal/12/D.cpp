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

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 5e5 + 5, inf = 1e9 + 7;

template <typename T>
struct Segment_Tree{
    const T unit = inf;

    inline T f(T x, T y){
        return min(x, y);
    }

    int n;
    vector <T> seg;

    Segment_Tree(int n): n(n) {
        seg.resize(4 * n + 1);
        Build(1, 1, n);
    }

    void Build(int id, int l, int r){
        if (l == r){
            seg[id] = unit;
            return;
        }
        int mid = (l + r) >> 1;
        Build(id << 1, l, mid);
        Build(id << 1 | 1, mid + 1, r);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    Segment_Tree(int n, vector <T>& a): n(n) {
        seg.resize(4 * n + 1);
        Build(1, 1, n, a);
    }

    void Build(int id, int l, int r, vector <T>& a){
        if (l == r){
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(id << 1, l, mid, a);
        Build(id << 1 | 1, mid + 1, r, a);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    void Update(int i, T val){
        Update(1, 1, n, i, val);
    }

    void Update(int id, int l, int r, int i, T val){
        if (i < l || r < i){
            return;
        }
        if (i <= l && r <= i){
            seg[id] = f(seg[id], val);
            return;
        }
        int mid = (l + r) >> 1;
        Update(id << 1, l, mid, i, val);
        Update(id << 1 | 1, mid + 1, r, i, val);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    T Get(int u, int v){
        return Get(1, 1, n, u, v);
    }

    T Get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return unit;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1;
        return f(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
    }
};

int n, ans;
tuple <int, int, int> a[N];

bool cmp(const tuple <int, int, int>& lhs, const tuple <int, int, int>& rhs){
    if (get<0>(lhs) != get<0>(rhs)){
        return get<0>(lhs) < get<0>(rhs);
    }
    if (get<1>(lhs) != get<1>(rhs)){
        return get<1>(lhs) > get<1>(rhs);
    }
    return get<2>(lhs) > get<2>(rhs);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        int x; cin >> x; x = inf - x; get<0>(a[i]) = x;
    }
    ForE(i, 1, n){
        int y; cin >> y; y = inf - y; get<1>(a[i]) = y;
    }
    ForE(i, 1, n){
        int z; cin >> z; z = inf - z; get<2>(a[i]) = z;
    }
    {
        int ctrmppy = 0; map <int, int> mppy;
        ForE(i, 1, n){
            int y = get<1>(a[i]); mppy[y] = 1;
        }
        Fora(&elem, mppy){
            elem.se = ++ctrmppy;
        }
        ForE(i, 1, n){
            get<1>(a[i]) = mppy[get<1>(a[i])];
        }
    }
    sort(a + 1, a + n + 1, cmp);
    Segment_Tree <int> it(n);
    ForE(i, 1, n){
        int y, z; tie(ignore, y, z) = a[i];
        if (it.Get(1, y - 1) < z){
            ans++;
        }
        it.Update(y, z);
    }
    cout << ans << endl;
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