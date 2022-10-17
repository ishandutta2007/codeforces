//
// Created by yamunaku on 2019/08/25.
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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

struct SegmentTree{
private:
    int n;
    vector<ll> node;

public:
    SegmentTree(int sz){
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2 * n - 1, 0);
    }

    ll get(int x){
        x += (n - 1);
        ll ans = node[x];
        while(x > 0){
            x = (x - 1) / 2;
            ans += node[x];
        }
        return ans;
    }

    void add(int a, int b, ll val, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return;
        if(a <= l && r <= b){
            node[k] += val;
            return;
        }
        add(a, b, val, 2 * k + 1, l, (l + r) / 2);
        add(a, b, val, 2 * k + 2, (l + r) / 2, r);
    }
};

struct SegmentTree2{
private:
    int n;
    vector<ll> node;

public:
    SegmentTree2(int sz){
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2 * n - 1, -LINF);
    }

    ll get(int x){
        x += (n - 1);
        ll ans = node[x];
        while(x > 0){
            x = (x - 1) / 2;
            ans = max(ans, node[x]);
        }
        return ans;
    }

    void add(int a, int b, ll val, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return;
        if(a <= l && r <= b){
            node[k] = max(node[k], val);
            return;
        }
        add(a, b, val, 2 * k + 1, l, (l + r) / 2);
        add(a, b, val, 2 * k + 2, (l + r) / 2, r);
    }
};


int main(){
    CFS;
    int n, w;
    cin >> n >> w;
    SegmentTree seg(w);
    rep(i, n){
        int sz;
        cin >> sz;
        vi a(sz);
        rep(j, sz) cin >> a[j];
        if(sz >= w / 2){
            SegmentTree2 seg2(w);
            rep(j, sz){
                seg2.add(j, j + w - sz + 1, a[j]);
            }
            seg2.add(0, w - sz, 0);
            seg2.add(sz, w, 0);
            rep(j, w){
                seg.add(j, j + 1, seg2.get(j));
            }
        }else{
            int ma = 0;
            rep(j, sz){
                ma = max(ma, a[j]);
                seg.add(j, j + 1, ma);
            }
            ma = 0;
            rep(j, sz){
                ma = max(ma, a[sz-j-1]);
                seg.add(w - j - 1, w - j, ma);
            }
            seg.add(sz, w - sz, ma);
        }
    }
    rep(i, w){
        cout << seg.get(i) << " ";
    }
    cout << endl;
    return 0;
}