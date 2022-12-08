#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

template<typename T, typename S>
struct LazySegmentTree{
private:
    int n;
    int sz;
    vector<T> node;
    vector<S> lazy;
    T E0;
    S E1;

    inline void updatef(S& lazy,S& value){
        lazy = value;
    }
    inline void calculatef(T& node,S& lazy,int len){
        node.first = lazy * len; //sum
        node.second = lazy;
    }
    inline T queryf(T& x,T& y){
        return {x.first + y.first, min(x.second, y.second)};
    }
public:
    LazySegmentTree(int sz,T nodeE,S lazyE ):sz(sz),E0(nodeE), E1(lazyE){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
    }

    LazySegmentTree(vector<T>& v,T E0,S E1 ):E0(E0),E1(E1){
        n=1;
        sz=v.size();
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
        rep(i,sz)node[i+n-1] = v[i];
        for(int i=n-2; i>=0; --i){
            node[i] = queryf(node[2*i+1],node[2*i+2]);
        }
    }

    void eval(int k,int l,int r){
        if(lazy[k]==E1)return ;
        calculatef(node[k], lazy[k], r-l);
        if(r-l>1){
            updatef(lazy[2*k+1], lazy[k]);
            updatef(lazy[2*k+2], lazy[k]);
        }
        lazy[k]=E1;
    }

    void update(int a, int b, S x,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            updatef(lazy[k], x);
            eval(k,l,r);
        }
        else {
            update(a,b,x,2*k+1,l,(l+r)/2);
            update(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=queryf(node[2*k+1], node[2*k+2]);
        }
    }

    T query(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(r<=a||b<=l)return E0;
        if(a<=l&&r<=b)return node[k];
        T xl=query(a,b,2*k+1,l,(l+r)/2);
        T xr=query(a,b,2*k+2,(l+r)/2,r);
        return queryf(xl, xr);
    }
    int find(int x, int k=0, int l=0, int r=-1){
        if(r<0){
            r=n;
            eval(k,0,r);
            if(node[k].second > x)return sz;
        }
        if(k>=n-1)return k-n+1;
        eval(2*k+1,l,(l+r)/2);
        if(node[2*k+1].second <=x){
            return find(x, 2*k+1, l, (l+r)/2);
        }
        eval(2*k+2,(l+r)/2,r);
        return find(x, 2*k+2,(l+r)/2, r);
    }

    int find_sum(ll x, int k=0, int l=0, int r=-1){
        if(r<0){
            r=n;
            eval(k,0,r);
            if(node[k].first <= x)return sz;
        }
        if(k>=n-1)return k-n+1;
        eval(2*k+1,l,(l+r)/2);
        if(node[2*k+1].first > x){
            return find_sum(x, 2*k+1, l, (l+r)/2);
        }
        eval(2*k+2,(l+r)/2,r);
        return find_sum(x - node[2*k+1].first, 2*k+2,(l+r)/2, r);
    }
};



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    vector<pair<ll,ll>> a(n);
    rep(i,n){
        cin>>a[i].first;
        a[i].second=a[i].first;
    }
    LazySegmentTree<pair<ll,ll>,ll> sg(a,{0,longinf},-1);

    while(q--){
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1){
            int l=sg.find(y);
            sg.update(l, x, y);
        } else {
            --x;
            int ret = 0;
            x = max(sg.find(y), x);
            int cnt=0;
            while(x<n){
                ll cy = sg.query(0, x).first;
                int idx = sg.find_sum(cy+y);
                y -= sg.query(x, idx).first;
                ret += idx-x;
                x = max(sg.find(y),idx);
            }
            cout<<ret<<endl;
        }
    }
    return 0;
}