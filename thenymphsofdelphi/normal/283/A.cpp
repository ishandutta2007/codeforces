#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e5 + 5;

template<class T>
struct fenwick_tree{
    int n;
    vector<T> data;
    fenwick_tree(){ }
    // O(n)
    fenwick_tree(int n): n(n), data(n){ }
    // O(n)
    fenwick_tree(int n, T init): fenwick_tree(vector<T>(n, init)){ }
    // O(n)
    fenwick_tree(const vector<T> &v): n((int)v.size()), data(v){
        for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) data[i + (i & -i) - 1] += data[i - 1];
    }
    fenwick_tree(const fenwick_tree &otr): n(otr.n), data(otr.data){
    }
    // O(log n)
    void update(int p, T x){
        assert(0 <= p && p < n);
        for(++ p; p <= n; p += p & -p) data[p - 1] += x;
    }
    // O(log n)
    T query(int r) const{
        T s{};
        for(; r > 0; r -= r & -r) s += data[r - 1];
        return s;
    }
    // O(log n)
    T query(int l, int r) const{
        assert(0 <= l && l <= r && r <= n);
        return query(r) - query(l);
    }
    // pred(sum[0, r)) is T, T, ..., T, F, F, ..., F
    // Returns max r with T
    // O(log n)
    int max_pref(auto pred) const{
        assert(pred({}));
        int p = 0;
        T sum{};
        for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pred(sum + data[p + pw - 1])){
            sum += data[p + pw - 1];
            p += pw;
        }
        return p;
    }
    template<class output_stream>
    friend output_stream &operator<<(output_stream &out, const fenwick_tree<T> &fw){
        out << "[";
        for(auto i = 0; i < fw.n; ++ i){
            out << fw.query(i, i + 1);
            if(i != fw.n - 1) out << ", ";
        }
        return out << ']';
    }
};

fenwick_tree fen(N, 0ll);

int q;
int n = 1;
ll sum = 0;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
cout << fixed << setprecision(12);
cin >> q; while (q--){
    int type; cin >> type;
    if (type == 1){
        int i, x; cin >> i >> x;
        fen.update(0, x);
        fen.update(i, -x);
        sum += (ll)i * x;
    }
    else if (type == 2){
        int x; cin >> x;
        fen.update(n, x);
        fen.update(n + 1, -x);
        n++;
        sum += x;
    }
    else{
        ll x = fen.query(n);
        fen.update(n - 1, -x);
        fen.update(n, x);
        n--;
        sum -= x;
    }
    cout << (ld)sum / n << endl;
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