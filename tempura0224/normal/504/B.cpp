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
        x = y;
        //x += y;
        //x = max(x,y);
        //x = min(x,y);
    }
    inline T queryf(T& x,T& y){
        //return x*y;
        return x+y;
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
    int find(int x, int k = 0){
        if(k>=n-1)return k-n+1;
        if(node[2*k+1]>=x)return find(x, 2*k+1);
        x -= node[2*k+1];
        return find(x,2*k+2);
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> ans(n);
    rep(_,2){
        int a[n];
        rep(i,n)cin>>a[i];
        SegmentTree<int> sg(n,0);
        rep(i,n){
            int x = sg.get(0,a[i]);
            ans[i]+=a[i]-x;
            sg.update(a[i], 1);
        }
    }
    rep(i,n){
        if(ans[n-i-1]>i){
            ans[n-i-1]-=i+1;
            if(i!=n-1)ans[n-i-2]++;
        }
    }
    SegmentTree<int> sg(n,0);
    rep(i,n)sg.update(i,1);
    vector<int> res;
    rep(i,n){
        int x = sg.find(ans[i]+1);
        res.push_back(x);
        sg.update(x, 0);
    }
    rep(i,n)cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}