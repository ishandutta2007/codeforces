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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

struct LazySegmentTree{
private:
   int n;
   vector<ll> node,lazy;
public:
   LazySegmentTree(int sz,ll init=longinf){
      n=1;
      while(n<sz)n*=2;
      node.resize(2*n-1,init);
      lazy.resize(2*n-1,0);
   }
   LazySegmentTree(vector<int>&a){
       int sz=a.size();
       n=1;
       while(n<sz)n*=2;
       node.resize(2*n-1,longinf);
       rep(i,sz)node[i+n-1]=a[i];
       for(int i=n-2;i>=0;--i){
           node[i]=min(node[2*i+1],node[2*i+2]);
       }
       lazy.resize(2*n-1,0);
   }

   void eval(int k,int l,int r){
      if(lazy[k]!=0)node[k]+=lazy[k];
      if(r-l>1){
          lazy[2*k+1]+=lazy[k];
          lazy[2*k+2]+=lazy[k];
      }
      lazy[k]=0;
   }
      //[a,b)x
   void add(int a,int b,ll x,int k=0,int l=0,int r=-1){
       if(r<0)r=n;
       eval(k,l,r);
       if(r<=a||b<=l)return;
       if(a<=l&&r<=b){
          lazy[k]+=x;
          eval(k,l,r);
       }
       else {
          add(a,b,x,2*k+1,l,(l+r)/2);
          add(a,b,x,2*k+2,(l+r)/2,r);
          node[k]=min(node[2*k+1],node[2*k+2]);
        }
   }
   //[a,b)
   ll get(int a,int b,int k=0,int l=0,int r=-1){
      if(r<0)r=n;
      eval(k,l,r);
      if(r<=a||b<=l)return longinf;
      if(a<=l&&r<=b)return node[k];
      ll xl=get(a,b,2*k+1,l,(l+r)/2);
      ll xr=get(a,b,2*k+2,(l+r)/2,r);
      return min(xl,xr);
   }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    LazySegmentTree sg(a);

    int l[m],r[m];
    rep(i,m){
        cin>>l[i]>>r[i];
        --l[i];
    }
    ll ans=-1,idx=-1;
    rep(i,n){
        rep(j,m){
            if(i<l[j]||r[j]<=i)sg.add(l[j],r[j],-1);
        }
        int mi=sg.get(0,n);
        if(ans<a[i]-mi)ans=a[i]-mi,idx=i;
        rep(j,m){
            if(i<l[j]||r[j]<=i)sg.add(l[j],r[j],1);
        }
    }
    cout<<ans<<endl;
    vector<int> ret;
    rep(i,m){
        if(idx<l[i]||r[i]<=idx)ret.push_back(i+1);
    }
    cout<<ret.size()<<endl;
    for(auto e:ret)cout<<e<<" ";
    return 0;
}