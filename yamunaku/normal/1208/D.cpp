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

struct SegmentTree {
private:
    int n;
    vector<ll> node;

public:
    SegmentTree(int sz) {
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
    }

    ll get(int x) {
        x += (n - 1);
        ll ans=node[x];
        while(x > 0) {
            x = (x - 1) / 2;
            ans+=node[x];
        }
        return ans;
    }

    void add(int a, int b, ll val, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return;
        if(a <= l && r <= b){
            node[k]+=val;
            return;
        }
        add(a, b, val, 2*k+1, l, (l+r)/2);
        add(a, b, val, 2*k+2, (l+r)/2, r);
    }
};


int main(){
    CFS;
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans(n);
    SegmentTree seg(n+1);
    per(i,n){
        ll l=1,r=n+1,mid;
        while(r-l>1){
            mid=(l+r)/2;
            if((mid-1)*mid/2-seg.get(mid)<=a[i]){
                l=mid;
            }else{
                r=mid;
            }
        }
        ans[i]=l;
        seg.add(l+1,n+1,l);
    }
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}