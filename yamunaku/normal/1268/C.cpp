//
// Created by yamunaku on 2019/12/21.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

struct LazySegmentTree{
    ll ide = 0;
    ll lazyide = 0;

    inline void updatef(ll &x, ll y){
        x += y;
    }

    inline ll queryf(ll x, ll y){
        return x + y;
    }

    inline void mergef(ll &x, ll y){
        x += y;
    }

    inline ll splitf(ll x){
        return x / 2;
    }

    int n;
    vector<ll> node, lazy;

    LazySegmentTree(int sz){
        n = 1;
        while(n < sz) n <<= 1;
        node.resize(2 * n - 1, ide);
        lazy.resize(2 * n - 1, ide);
    }

    void eval(int k, int l, int r){
        if(lazy[k] != 0){
            updatef(node[k], lazy[k]);
            if(r - l > 1){
                lazy[2 * k + 1] += splitf(lazy[k]);
                lazy[2 * k + 2] += splitf(lazy[k]);
            }
            lazy[k] = lazyide;
        }
    }

    void update(int a, int b, ll x, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            mergef(lazy[k], (r - l) * x);
            eval(k, l, r);
        }else{
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = queryf(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    ll get(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)r = n;
        if(r <= a || b <= l) return ide;
        eval(k, l, r);
        if(a <= l && r <= b) return node[k];
        ll xl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        ll xr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return queryf(xl, xr);
    }
};

struct SegmentTree{
    int ide = 0;

    inline void updatef(int &x, int y){
        x += y;
    }

    inline int queryf(int x, int y){
        return x + y;
    }

    int n;
    vector<int> node;

    SegmentTree(int sz){
        n = 1;
        while(n < sz) n <<= 1;
        node.resize(2 * n - 1, ide);
        // for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        // for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void update(int k, int x){
        k += n - 1;
        updatef(node[k], x);
        while(k){
            k = (k - 1) / 2;
            node[k] = queryf(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    int get(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)r = n;
        if(r <= a || b <= l) return ide;
        if(a <= l && r <= b) return node[k];
        int xl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        int xr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return queryf(xl, xr);
    }

    int search(int x, int k = 0, int l = 0, int r = -1){
        if(r < 0)r = n;
        if(r - l == 1) return l;
        if(x <= node[2 * k + 1]) return search(x, 2 * k + 1, l, (l + r) / 2);
        else return search(x - node[2 * k + 1], 2 * k + 2, (l + r) / 2, r);
    }
};

int main(){
    CFS;
    int n;
    cin >> n;
    vi a(n), pos(n);
    rep(i, n){
        cin >> a[i], a[i]--;
        pos[a[i]] = i;
    }
    LazySegmentTree ls(n), rs(n);
    SegmentTree seg(n);
    ll ans = 0;
    rep(i, n){
        ans += i - seg.get(0, pos[i]);
        seg.update(pos[i], 1);
        rs.update(0, pos[i], 1);
        ls.update(pos[i]+1, n, 1);
        ll mid = seg.search(i / 2 + 1);
        ll ansl = ls.get(0, mid);
        ll ansr = rs.get(mid, n);
        ll dl = seg.get(0, mid);
        ll dr = seg.get(mid, n);
        cout << ans + ansl + ansr - dl*(dl-1)/2 - dr*(dr-1)/2 << " ";
    }
    cout << endl;
    return 0;
}