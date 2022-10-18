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

const int N = 3e5 + 5;

template <typename T>
struct Segment_Tree{
    const T unit = 0;

    inline T f(T x, T y){
        return max(x, y);
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
            seg[id] = val;
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

int n;
int a[N];
int b[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; ForE(test, 1, tests){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }

    map <int, int> mpp;
    ForE(i, 1, n){
        mpp[a[i]]++;
    }
    ForE(i, 1, n){
        mpp[b[i]]--;
    }
    bool ans = 1;
    Fora(&elem, mpp){
        if (elem.se){
            ans = 0;
            break;
        }
    }
    if (!ans){
        cout << "NO" << endl;
        continue;
    }

    Segment_Tree <int> seg(n + 1);
    vvi vpos(n + 1);
    ForE(i, 1, n){
        seg.Update(a[i], i);
        vpos[a[i]].emplace_back(i);
    }
    FordE(i, n, 1){
        if (seg.Get(b[i], b[i]) < seg.Get(b[i] + 1, n + 1)){
            ans = 0;
            break;
        }
        vpos[b[i]].pop_back();
        seg.Update(b[i], vpos[b[i]].empty() ? 0 : vpos[b[i]].back());
    }
    if (!ans){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
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