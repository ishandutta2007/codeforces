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
        if(x.first<y.first)return;
        else if(x.first>y.first)x=y;
        else (x.second += y.second)%=mod;
    }
    inline T queryf(T& x,T& y){
        if(x.first!=y.first)return min(x,y);
        return {x.first, (x.second+y.second)%mod};
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
    int n;
    cin>>n;
    int a[n],b[n];
    vector<int> v;
    rep(i,n){
        cin>>b[i]>>a[i];
        v.push_back(a[i]);
        v.push_back(b[i]);
    }
    v.push_back(0);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int m = v.size();
    vector<vector<int>> st(m);
    int ma = 0;
    rep(i,n){
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        b[i]=lower_bound(v.begin(),v.end(),b[i])-v.begin();
        st[a[i]].push_back(b[i]);
        ma = max(ma, a[i]);
    }
    SegmentTree<pair<ll,ll>> sg(m,{longinf,0});
    sg.update(0,{0,1});
    pair<ll,ll> ans = {longinf,0};
    rep(i,m){
        auto res = sg.get(0,i+1);
        for(auto e : st[i]){
            ll nxt = res.first+v[i]-v[e];
            sg.update(e,{nxt, res.second});
            if(e>ma){
                if(res.first+v[i]<ans.first){
                    ans = {res.first+v[i],res.second};
                }
                else if(res.first+v[i]==ans.first){
                    ans.second = (ans.second+res.second)%mod;
                }
            }
        }
    }
    cout<<ans.second<<endl;
    return 0;
}