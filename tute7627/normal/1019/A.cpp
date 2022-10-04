#include<bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa << " " <<
#define rep(i,n,m) for(int i=(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=(int)(m)-1;i>=n;i--)
using ll = long long;
template<typename T1,typename T2>
bool chmin(T1 &a, T2 b){
  if(a>b){
    a=b;
    return true;
  }
  return false;
}
template<typename T1,typename T2>
bool chmax(T1 &a, T2 b){
  if(a<b){
    a=b;
    return true;
  }
  return false;
}
int main(){
  //cin.tie(nullptr);
  //ios_base::sync_with_stdio(false);
  ll n,m;cin>>n>>m;
  vector<ll>p(n),c(n);
  vector<vector<ll>>a(m);
  rep(i,0,n){
    cin>>p[i]>>c[i];
    p[i]--;
    a[p[i]].push_back(c[i]);
  }
  rep(i,0,m)sort(ALL(a[i]));
  const ll inf=1e18;
  ll ret=inf;
  rep(i,1,n+1){
    ll sum=0;
    ll need=max<ll>(0,i-(ll)a[0].size());
    vector<int>r;
    rep(j,1,m){
      rep(o,0,a[j].size()){
        if(o<(ll)a[j].size()-i+1){
          sum+=a[j][o];
          need--;
        }
        else r.push_back(a[j][o]);
      }
    }
    sort(ALL(r));
    for(auto z:r){
      if(need>0){
        need--;
        sum+=z;
      }
    }
    chmin(ret,sum);
  }
  cout<<ret<<endl;
  return 0;
}