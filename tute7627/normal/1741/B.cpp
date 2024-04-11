#include<bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa << " " <<
#define rep(i,n,m) for(int i=(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=int(n);i--)
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
    ll n;cin>>n;
    vector<ll>v(n);
    iota(ALL(v),1);
    if(n==3){
      cout<<-1<<endl;
      continue;
    }
    if(n%2==0){
      reverse(ALL(v));
    }
    else{
      reverse(ALL(v));
      reverse(v.begin(),v.begin()+n/2+1);
    }
    rep(i,0,n){
      cout<<v[i];
      if(i==n-1)cout<<endl;
      else cout<<" ";
    }
  }
  return 0;
}