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
        node.resize(2*n-1,0);
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
    ll m,n;
    cin>>m>>n;
    vector<ll> a(n),b(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)a[i]*=2;
    rep(i,n)b[i]*=2;
    vector<pair<ll, int>> pa(n),pb(n);
    rep(i,n)pa[i]={a[i],i};
    rep(i,n)pb[i]={b[i],i};
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(pa.begin(),pa.end());
    sort(pb.begin(),pb.end());

    LazySegmentTree<ll, ll> sg(n,-longinf,0);
    int id[5];
    rep(i,n){
        id[0] = 0;
        id[1] = lower_bound(b.begin(),b.end(),a[i]-m)-b.begin();
        id[2] = lower_bound(b.begin(),b.end(),a[i])-b.begin();
        id[3] = lower_bound(b.begin(),b.end(),a[i]+m)-b.begin();
        id[4] = n;
        rep(j,5)id[j]-=i;
        rep(j,4){
            ll add = j%2?(a[i]/2):(-a[i]/2);
            if(j==0||j==3)add+=m;
            if(id[j]>=0){
                sg.update(id[j],id[j+1],add);
            }
            else if(id[j+1]<0)sg.update(id[j]+n,id[j+1]+n,add);
            else {
                sg.update(id[j]+n,n,add);
                sg.update(0,id[j+1],add);
            }
        }
    }
    rep(i,n){
        id[0] = 0;
        id[1] = upper_bound(a.begin(),a.end(),b[i]-m)-a.begin();
        id[2] = upper_bound(a.begin(),a.end(),b[i])-a.begin();
        id[3] = upper_bound(a.begin(),a.end(),b[i]+m)-a.begin();
        id[4] = n;
        rep(j,5)id[j]*=-1;
        rep(j,5)id[j]+=i+1;
        rep(j,4){
            ll add = j%2?(b[i]/2):(-b[i]/2);
            if(id[j+1]>=0){
                sg.update(id[j+1],id[j],add);
            }
            else if(id[j]<0)sg.update(id[j+1]+n,id[j]+n,add);
            else {
                sg.update(id[j+1]+n,n,add);
                sg.update(0,id[j],add);
            }
        }
    }
    ll mi = longinf;
    ll idx = -1;
    rep(i,n){
        ll ret = sg.query(i,i+1);
        if(ret<mi&&ret>=0){mi=ret;idx=i;}
    }
    vector<int> ans(n);
    rep(i,n){
        ans[pa[i].second]=pb[(i+idx)%n].second;
    }
    cout<<mi<<endl;
    rep(i,n)cout<<ans[i]+1<<" \n"[i+1==n];
    return 0;
}