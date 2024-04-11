//
// Created by yamunaku on 2019/10/04.
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
    ll limit;
    vector<ll> node;

public:
    SegmentTree(int sz, int l){
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2 * n - 1, 0);
        limit = l;
    }

    void update(int x, ll val){
        x += (n - 1);
        ll d = min(node[x] + val, limit) - node[x];
        node[x] += d;
        while(x > 0){
            x = (x - 1) / 2;
            node[x] += d;
        }
    }

    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};


int main(){
    CFS;
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    SegmentTree ta(n, a), tb(n, b);
    int c,d;
    rep(i, q){
        cin >> c;
        if(c==1){
            cin >> d >> a;
            ta.update(d-1, a);
            tb.update(d-1, a);
        }else{
            cin >> d;
            cout << tb.getsum(0,d-1) + ta.getsum(d+k-1, n)  << endl;
        }
    }
    return 0;
}