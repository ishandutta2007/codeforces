#include<bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define spa << " " <<
#define rep(i,n,m) for(int i=(n);i<int(m);i++)
#define rrep(i,n,m) for(int i=int(m)-1;i>=int(n);i--)
#define endl "\n"
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
    vector<ll>a(n),b(n+1);
    rep(i,0,n){
      cin>>a[i];
      b[i+1]=a[i]+b[i];
    }
    ll ret=1e9;
    rep(s,1,n+1){
      if(b[n]%s!=0)continue;
      ll d=b[n]/s;
      ll cnt=0;
      ll pre=0;
      ll mx=0;
      rep(i,1,n+1){
        if(b[i]%d==0){
          cnt++;
          chmax(mx,i-pre);
          pre=i;
        }
      }
      if(cnt==s)chmin(ret,mx);
    }
    cout<<ret<<endl;
  }
  return 0;
}