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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


struct UnionFind{
   vector<int> par;
   UnionFind(int n):par(n,-1){}
   int find(int x){
       if(par[x]<0)return x;
       return par[x]=find(par[x]);
   }
   bool unite(int x,int y){
       x=find(x);
       y=find(y);
       if(x==y)return false;
       if(par[x]>par[y]){
           par[y]+=par[x];
           par[x]=y;
       }
       else{
           par[x]+=par[y];
           par[y]=x;
       }
       return true;
   }

   bool same(int x,int y){
       return find(x)==find(y);
   }
   ll size(int x){
       return -par[find(x)];
   }
};


ll powmod(ll n,ll k){
    ll ret=1;
    while(k){
        if(k&1)ret=ret*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return ret;
}
int main(){
    int n,k;
    cin>>n>>k;
    UnionFind uf(n);
    rep(i,n-1){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        --x;--y;
        if(z==0)uf.unite(x,y);
    }
    ll ans=powmod(n,k);
    rep(i,n){
        if(uf.find(i)==i){
            ans+=mod-powmod(uf.size(i),k);
        }
    }
    cout<<ans%mod<<endl;
    return 0;
}