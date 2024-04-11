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
  ll n;cin>>n;
  if(n%4==2){
    cout<<"!" spa -1<<endl;
    return 0;
  }
  auto ask=[&](int i)->ll{
    cout<<"?" spa i<<endl;
    ll x;cin>>x;
    cout<<"?" spa i+n/2<<endl;
    ll y;cin>>y;
    if(y==x){
      cout<<"!" spa i<<endl;
      exit(0);
    }
    return y-x;
  };
  ll dl=ask(1);
  ll l=1,r=1+n/2;
  while(1){
    ll m=(l+r)/2;
    if(ask(m)*dl>0){
      l=m;
    }
    else r=m;
  }
  return 0;
}