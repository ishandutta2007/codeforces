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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

template<typename T, typename S>
struct LazySegmentTree{
private:
    int n;
    vector<T> node;
    vector<S> lazy;
    T E0;
    S E1;

    inline void updatef(S& lazy,S& value){
        lazy += value;
        //lazy = value;
        //lazy = max(lazy, value);
        //lazy = min(lazy, value);
    }
    inline void calculatef(T& node,S& lazy,int len){
        //node += lazy * len; //sum
        node += lazy ; //max
        //node = lazy ;
    }
    inline T queryf(T& x,T& y){
        //return x + y;
        //return x * y;
        return max(x, y);
        //return min(x, y);
    }
public:
    LazySegmentTree(int sz,T nodeE,S lazyE ):E0(nodeE), E1(lazyE){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
    }

    LazySegmentTree(vector<T>& v,T E0,S E1 ):E0(E0),E1(E1){
        n=1;
        int sz=v.size();
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
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,p;
    cin>>n>>m>>p;
    vector<pair<int,pair<int,ll>>> v(n+p);
    rep(i,n){
        int x,y;
        cin>>x>>y;
        v[i]={x,{-inf,-y}};
    }
    vector<pair<int,int>> b(m);
    rep(i,m){
        cin>>b[i].first>>b[i].second;
    }
    rep(i,p){
        int x,y,z;
        cin>>x>>y>>z;
        v[n+i]={x,{y,z}};
    }
    sort(b.begin(), b.end());
    vector<ll> c(m);
    rep(i,m)c[i]=-b[i].second;
    LazySegmentTree<ll,ll> sg(c,-longinf, 0);
    sort(v.begin(),v.end());
    ll ans = -longinf;
    for(auto e:v){
        if(e.second.second<0){
            ans = max(sg.query(0,m)+e.second.second,ans);
        }
        else {
            int idx = lower_bound(b.begin(),b.end(),pair<int,int>{e.second.first,inf})-b.begin();
            sg.update(idx, m, e.second.second);
        }
    }
    cout<<ans<<endl;
    return 0;
}