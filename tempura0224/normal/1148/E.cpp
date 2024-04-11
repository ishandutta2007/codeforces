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


using P =pair<ll, pair<int,int>>;
template<typename T>
struct LazySegmentTree{
private:
    int n;
    vector<T> node;
    vector<ll>lazy;
    T E0;
    ll E1;

    inline void updatef(ll& lazy, ll& value){
        lazy += value;
        //lazy = value;
        //lazy = max(lazy, value);
        //lazy = min(lazy, value);
    }
    inline void calculatef(T& node,ll& lazy,int len){
        //node += lazy * len; //sum
        node.first += lazy ; //max
        //node = lazy ;
    }
    inline T queryf(T& x,T& y){
        //return x + y;
        //return x * y;
        //return max(x, y);
        if(x.first!=y.first){
            return max(x, y);
        }
        else {
            if(x.second.second+1==y.second.first){
                return {x.first,{x.second.first, y.second.second}};
            }
            else return x;
        }
    }
public:
    LazySegmentTree(int sz,ll nodeE,ll lazyE = 0):E0(nodeE), E1(lazyE){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
    }

    LazySegmentTree(vector<ll>& v,T E0,ll E1 = 0):E0(E0),E1(E1){
        n=1;
        int sz=v.size();
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
        rep(i,sz)node[i+n-1] = {v[i],{i,i}};
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

    void update(int a, int b, ll x,int k=0,int l=0,int r=-1){
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
    int n;
    cin>>n;
    vector<ll> v(n);
    rep(i,n)scanf("%lld",&v[i]);
    vector<ll> x(n);
    rep(i,n)scanf("%lld",&x[i]);
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int a,int b){
        return v[a]<v[b];
    });
    sort(v.begin(),v.end());
    sort(x.begin(),x.end());
    rep(i,n){
        x[i]-=v[i];
    }
    rep(i,n-1){
        x[i+1]+=x[i];
    }
    if(x[n-1]!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    rep(i,n){
        if(x[i]<0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    LazySegmentTree<P> sg(x,{0,{-1,-1}},0);
    vector<pair<int,int>> ans;
    vector<int> num;
    while(1){
        auto ma=sg.query(0,n);
        if(ma.first==0)break;
        int ok=ma.second.first, l=ma.second.second+1;
        ans.emplace_back(ok,l);
        ll mi=max(sg.query(ok-1,ok).first,sg.query(l,l+1).first);
        ma.first-=mi;
        num.push_back(ma.first);
        sg.update(ok,l,-ma.first);
    }
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    int i=0;
    for(auto p : ans){
        printf("%d %d %d\n",ord[p.first]+1,ord[p.second]+1,num[i]);
        ++i;
    }
    return 0;
}