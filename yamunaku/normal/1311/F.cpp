//
// Created by yamunaku on 2020/02/24.
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

struct SegmentTree{
    int ide = 0;

    inline void updatef(ll &x, int y){
        x += y;
    }

    inline ll queryf(ll x, ll y){
        return x + y;
    }

    int n;
    vector<ll> node;

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

    ll get(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)r = n;
        if(r <= a || b <= l) return ide;
        if(a <= l && r <= b) return node[k];
        ll xl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        ll xr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return queryf(xl, xr);
    }
};

struct point{
    ll x;
    ll v;
};

int main(){
    //CFS;
    int n;
    cin >> n;
    vector<point> p(n);
    map<int, int> mp;
    rep(i, n){
        cin >> p[i].x;
    }
    rep(i, n){
        cin >> p[i].v;
        mp[p[i].v] = 0;
    }
    int sz = 0;
    for(auto &pp:mp) pp.second = sz++;
    sort(all(p), [](point &l, point &r){
        return l.x < r.x;
    });
    ll ans = 0;
    SegmentTree seg(sz);
    SegmentTree seg2(sz);
    rep(i, n){
        int id = mp[p[i].v];
        ans += seg2.get(0, id + 1) * p[i].x - seg.get(0, id + 1);
        seg.update(id, p[i].x);
        seg2.update(id, 1);
    }
    cout << ans << endl;
    return 0;
}