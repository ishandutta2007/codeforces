//
// Created by yamunaku on 2019/10/16.
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

struct SegmentTree {
private:
    int n;
    vector<ll> node;

public:
    SegmentTree(int sz) {
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, -5);
    }

    void update(int x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    int getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};


int main(){
    CFS;
    int n;
    cin >> n;
    vi a(n);
    int ma = 0, mi = IINF;
    map<int,int> zatu;
    int idx = -1;
    rep(i, n){
        cin >> a[i];
        ma = max(ma, a[i]);
        if(a[i]<mi){
            idx = i;
            mi = a[i];
        }
        mi = min(mi, a[i]);
        zatu[a[i]] = 0;
    }
    if(2*mi>=ma){
        rep(i,n) cout << -1 << " ";
        cout << endl;
        return 0;
    }
    int sz = 0;
    for(auto &p:zatu) p.second=sz++;
    SegmentTree seg(sz);
    seg.update(zatu[a[idx]], 0);
    int pre=IINF;
    vi ans(2*n, 0);
    repl(i, 1, 2*n){
        int nx = (idx-i+3*n)%n;
        ans[nx]=max(ans[nx], min(pre+1, i-seg.getmax(0, zatu.lower_bound((a[nx]+1)/2)->second)));
        seg.update(zatu[a[nx]], i);
        pre = ans[nx];
    }
    rep(i,n){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}