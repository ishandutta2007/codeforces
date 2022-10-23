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
    ll n;cin>>n;
    vector<bool>a(n+1);
    vector<ll>b(n);
    rep(i,0,n)cin>>b[i];
    a[0]=true;
    rep(i,0,n+1){
      if(i>0&&i-b[i-1]-1>=0&&a[i-b[i-1]-1]){
        a[i]=true;
      }
      if(i<n&&a[i]&&i+b[i]+1<=n){
        a[i+b[i]+1]=true;
      }
    }
    if(a[n])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
  return 0;
}