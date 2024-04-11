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
        //x += y;
        //x = max(x,y);
        //x = min(x,y);
    }
    inline T queryf(T& x,T& y){
        //return x*y;
        //return x+y;
        //return max(x,y);
        return min(x,y);
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
    int find(int k){
        if(k>=n-1)return k;
        if(node[2*k+1]==0)return find(2*k+1);
        else return find(2*k+2);
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    rep(i,n){
        if(a[i]>i+1){
            cout<<-1<<endl;
            return 0;
        }
    }
    vector<int> l(n+1),r(n+1, n);
    rep(i,n){
        l[a[i]]=i+1;
        if(a[i])r[a[i]-1]=min(r[a[i]-1],i);
    }
    vector<int> ord(n+1);
    rep(i,n+1)ord[i]=i;
    sort(ord.begin(),ord.end(),[&](int s,int t){
        return l[s]==l[t]?s<t:l[s]<l[t];
    });
    rep(i,n)r[n-i-1]=min(r[n-i-1],r[n-i]);
    set<pair<int,int>> st;
    vector<int> b;
    int j=0;
    rep(i,n){
        while(j<=n+1 && l[ord[j]]<=i){
            st.insert({r[ord[j]],ord[j]});
            j++;
        }
        if(st.empty()||st.begin()->first<i){
            cout<<-1<<endl;
            return 0;
        }
        b.push_back(st.begin()->second);
        st.erase(st.begin());
    }
    rep(i,n)cout<<b[i]<<" ";
    return 0;
}