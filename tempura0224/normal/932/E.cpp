#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
typedef long long ll;
const ll mod=1000000007;

ll pow(ll n,ll k){
  ll ret=1;
  while(k>0){
    if(k&1)ret=ret*n %mod;
    n=n*n %mod;
    k/=2;
    }
  return ret;
  }
int main(){
  ll n,k;
  cin>>n>>k;
  ll a[k+1];
  REP(i,1,k+1){
    ll res=pow(i,k);
    ll now=1;
    REP(j,1,i){
      now=now*(i-j+1)%mod;
      ll mi=now*a[j]%mod;
      res=(res-mi+mod)%mod;
      }
    a[i]=res*pow(now,mod-2)%mod;
    }
  ll ans=0,p=1;
  REP(i,1,k+1){
    ll ii=(ll)i;
    p=p*(n-ii+1)%mod;
    ll q=p*pow(2,n-ii) %mod;
    q=a[ii]*q %mod;
    ans=(ans+q) %mod;
    }
  cout<<ans%mod<<endl;
  return 0;        
  }