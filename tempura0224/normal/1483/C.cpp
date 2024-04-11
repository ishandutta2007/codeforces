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
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<int> b(n);
    rep(i,n)cin>>b[i];
    SegmentTree<ll> sg1(n+5, -longinf), sg2(n+5, -longinf);
    vector<ll> dp(n+1, -longinf);
    dp[0]=0;
    stack<int> st;
    rep(i,n){
        ll v1 = sg1.get(a[i],n+5);
        ll v2 = sg2.get(0,a[i]);
        dp[i+1]=max({dp[i]+b[i],v1+b[i],v2});
        while(st.size() && st.top()>a[i]){
            int x = st.top();st.pop();
            sg1.update(x,-longinf);sg2.update(x,-longinf);
        }
        sg1.update(a[i],max(v1,dp[i]));
        sg2.update(a[i],dp[i+1]);
        st.push(a[i]);
    }
    cout<<dp[n]<<endl;
    return 0;
}