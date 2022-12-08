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



struct Data{
    ll aa,ab,bb;
    Data(ll x=0,ll y=0, ll z=0):aa(x),ab(y),bb(z){}
};
template<typename T>
struct SegmentTree{
private:
    int n;
    T E;
    vector<T> node;
    inline void updatef(T& x,T& y){
        x = y;
        //x += y;
        //x = max(x,y);
        //x = min(x,y);
    }
    inline T queryf(T& x,T& y){
        Data s;
        s.aa = x.aa+y.aa;
        s.ab = min(x.ab+y.bb,x.aa+y.ab);
        s.bb = x.bb+y.bb;
        return s;
    }

public:
    SegmentTree(int sz,T E_):E(E_){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E);
    }

    SegmentTree(vector<T>& A,T E_):E(E_){
        int sz=A.size();
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E);
        rep(i,sz)node[i+n-1]=A[i];
        for(int i=n-2;i>=0;--i){
            node[i]=queryf(node[2*i+1], node[2*i+2]);
        }
    }
    void update(int k,T x){
        k+=n-1;
        updatef(node[k],x);
        while(k>0){
            k=(k-1)/2;
            node[k]=queryf(node[2*k+1], node[2*k+2]);
        }
    }
       //[a,b)
    T get(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        if(r<=a||b<=l)return E;
        if(a<=l&&r<=b)return node[k];
        T xl=get(a,b,2*k+1,l,(l+r)/2);
        T xr=get(a,b,2*k+2,(l+r)/2,r);
        return queryf(xl, xr);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> pos(n),a(n);
    rep(i,n){
        int x;
        cin>>x;
        --x;
        pos[x]=i;
    }
    rep(i,n)cin>>a[i];
    SegmentTree<Data> sg(n, {0,0,0});
    rep(i,n){
        if(i==0)sg.update(i,{a[i],a[i],longinf});
        else if(i==n-1)sg.update(i,{longinf,0,0});
        else sg.update(i,{a[i],0,0});
    }
    ll ans = min(a[0],a[n-1]);
    rep(i,n-1){
        int idx = pos[i];
        if(idx==0)sg.update(idx,{0,0,longinf});
        else if(idx==n-1)sg.update(idx,{longinf,a[idx],a[idx]});
        else sg.update(idx,{0,0,a[idx]});
        ans = min(ans,sg.get(0,n).ab);
    }
    cout<<ans<<endl;
    return 0;
}