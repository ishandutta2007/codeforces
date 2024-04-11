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

template<typename T>
struct SegmentTree{
private:
    int n;
    T E;
    vector<T> node;
    inline void updatef(T& x,T& y){
        x = y;
    }
    inline T queryf(T& x,T& y){
        return max(x,y);
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
    int find(int x, int k = 0) {
        if(k >= n-1)return k - n + 1;
        if(node[2*k+1]>=x)return find(x, 2*k+1);
        else return find(x, 2*k+2);
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<ll> a(n);
        rep(i,n)cin>>a[i];
        ll ma = 0;
        vector<ll> sum(n);
        ll s=0;
        rep(i,n){
            s+=a[i];
            ma=max(ma,s);
            sum[i]=s;
        }
        SegmentTree<ll> sg(sum, -longinf);
        while(m--){
            int x;
            cin>>x;
            ll ans = 0;
            if(s<=0){
                if(x>ma){
                    cout<<-1<<" ";
                    continue;
                }
            } else {
                ll p = (max(x-ma,0ll)+s-1)/s;
                ans += n * p;
                x -= s * p;
            }
            ans += sg.find(x);
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}