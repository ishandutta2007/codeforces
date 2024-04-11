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

struct Node{
    ll a00,a01,a10,a11;
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
        return {
            max(x.a00+y.a00, x.a01+y.a10),
            max(x.a00+y.a01, x.a01+y.a11),
            max(x.a10+y.a00, x.a11+y.a10),
            max(x.a10+y.a01, x.a11+y.a11),
        };
        //return x+y;
        //return max(x,y);
        //return min(x,y);
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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int q;cin>>q;
        vector<ll> a(n);
        rep(i,n)cin>>a[i];
        vector<Node> node(n);
        rep(i,n)node[i]={0,a[i],-a[i],0};
        SegmentTree<Node> sg(node,{0,-longinf,-longinf,0});
        auto ret = sg.get(0,n);
        cout << max({ret.a00,ret.a01})<<"\n";
        rep(i,q){
            int l,r;
            cin>>l>>r;
            --l;--r;
            sg.update(l,node[r]);
            sg.update(r,node[l]);
            swap(node[l],node[r]);
            auto ret = sg.get(0,n);
            cout << max({ret.a00,ret.a01})<<"\n";
        }
    }
    return 0;
}