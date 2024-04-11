#include<bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa << " " <<
#define rep(i,n,m) for(int i=(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=int(n);i--)
#define endl "\n"
#define MP make_pair
#define fi first
#define se second
using ll=long long;
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){
  if(a>b){
    a=b;
    return true;
  }
  return false;
}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){
  if(a<b){
    a=b;
    return true;
  }
  return false;
}
int main(){

  ll t;cin>>t;
  while(t--){
    ll m;cin>>m;
    vector<ll>pa(m);
    rep(i,0,m)cin>>pa[i];
    bool sw=true;
    ll ret=0;
    using P=pair<ll,ll>;
    auto dfs=[&](auto &&f,ll l,ll r)->P{
      P p(1e9,-1e9);
      if(r-l==1){
        p=MP(pa[l],pa[l]);
        return p;
      }
      ll m=(l+r)/2;
      auto pl=f(f,l,m);
      auto pr=f(f,m,r);
      if(pl.fi>pr.fi)ret++;
      p.fi=min(pl.fi,pr.fi);
      p.se=max(pl.se,pr.se);
      if(p.se-p.fi!=r-l-1)sw=false;
      //cout<<l spa r spa p.fi spa p.se<<endl;
      return p;
    };
    dfs(dfs,0,m);
    if(!sw)cout<<-1<<endl;
    else cout<<ret<<endl;
  }
  return 0;
}