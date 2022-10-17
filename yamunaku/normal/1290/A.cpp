//
// Created by yamunaku on 2020/02/02.
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
    int ide = IINF;

    inline void updatef(int &x, int y){
        x = y;
    }

    inline int queryf(int x, int y){
        return min(x, y);
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
};

int main(){
    CFS;
    int t;
    cin >> t;
    rep(_, t){
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n);
        rep(i, n) cin >> a[i];
        SegmentTree seg(m);
        rep(i, m){
            seg.update(i, max(a[i], a[n - m + i]));
        }
        k = min(k, m - 1);
        int ans = 0;
        rep(i, k + 1){
            ans = max(ans, seg.get(i, m - k + i));
        }
        cout << ans << endl;
    }
    return 0;
}