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

template<typename T>
struct SegmentTree{
private:
    int n;
    T E;
    vector<T> node;
    inline void updatef(T& x,T& y){
        x = min(x,y);
    }
    inline T queryf(T& x,T& y){
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
};
int main(){
    int n;
    cin>>n;
    vector<int> a(3*n);
    vector<int> x;
    rep(i,n){
        cin>>a[i];
        a[n+i]=a[2*n+i]=a[i];
        x.push_back(a[i]);
        int h=(a[i]+1)/2;
        x.push_back(h);
    }
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    int m=x.size();
    vector<int> dp(3*n,inf);
    SegmentTree<int> sg(m,inf);
    for(int i=3*n-1;i>=0;--i){
        int id1=lower_bound(x.begin(), x.end(),a[i])-x.begin();
        int res1=sg.get(id1+1,m);
        int id2=lower_bound(x.begin(), x.end(),(a[i]+1)/2)-x.begin();
        int res2=sg.get(0,id2);
        if(res1!=inf)dp[i]=min(dp[i],dp[res1]);
        if(res2!=inf)dp[i]=min(dp[i],res2);
        sg.update(id1,i);
    }
    rep(i,n){
        if(dp[i]!=inf)cout<<dp[i]-i;
        else cout<<-1;
        cout<<" ";
    }
    return 0;
}